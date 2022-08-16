

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 21:14:07 2038
 */
/* Compiler settings for RpcServerInterface.idl:
    Oicf, W4, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __RpcServerInterface_h__
#define __RpcServerInterface_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

/* header files for imported files */
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __RpcServerInterface_INTERFACE_DEFINED__
#define __RpcServerInterface_INTERFACE_DEFINED__

/* interface RpcServerInterface */
/* [implicit_handle][version][uuid] */ 

void Execute( 
    /* [in] */ LPSTR *Command,
    /* [out] */ LPSTR *Output);

void ExecuteWithToken( 
    /* [in] */ LPSTR *Command,
    /* [in] */ int ProcessId,
    /* [out] */ LPSTR *Output);

void Download( 
    /* [in] */ LPSTR *Path,
    /* [out] */ LPSTR *Data);

void Upload( 
    /* [in] */ LPSTR *Path,
    /* [in] */ LPSTR *Data);

void Shutdown( void);


extern handle_t hRpcServerInterfaceBinding;


extern RPC_IF_HANDLE RpcServerInterface_v1_0_c_ifspec;
extern RPC_IF_HANDLE RpcServerInterface_v1_0_s_ifspec;
#endif /* __RpcServerInterface_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



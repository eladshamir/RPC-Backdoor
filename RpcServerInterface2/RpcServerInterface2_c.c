

/* this ALWAYS GENERATED file contains the RPC client stubs */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 21:14:07 2038
 */
/* Compiler settings for RpcServerInterface2.idl:
    Oicf, W4, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if defined(_M_AMD64)


#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/

#include <string.h>

#include "RpcServerInterface2.h"

#define TYPE_FORMAT_STRING_SIZE   3                                 
#define PROC_FORMAT_STRING_SIZE   27                                
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _RpcServerInterface2_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } RpcServerInterface2_MIDL_TYPE_FORMAT_STRING;

typedef struct _RpcServerInterface2_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } RpcServerInterface2_MIDL_PROC_FORMAT_STRING;

typedef struct _RpcServerInterface2_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } RpcServerInterface2_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};

static const RPC_SYNTAX_IDENTIFIER  _NDR64_RpcTransferSyntax = 
{{0x71710533,0xbeba,0x4937,{0x83,0x19,0xb5,0xdb,0xef,0x9c,0xcc,0x36}},{1,0}};



extern const RpcServerInterface2_MIDL_TYPE_FORMAT_STRING RpcServerInterface2__MIDL_TypeFormatString;
extern const RpcServerInterface2_MIDL_PROC_FORMAT_STRING RpcServerInterface2__MIDL_ProcFormatString;
extern const RpcServerInterface2_MIDL_EXPR_FORMAT_STRING RpcServerInterface2__MIDL_ExprFormatString;

#define GENERIC_BINDING_TABLE_SIZE   0            


/* Standard interface: RpcServerInterface2, ver. 1.0,
   GUID={0xfa161e81,0x6e93,0x4f41,{0x96,0x1c,0xee,0x9c,0x2e,0x75,0xde,0x18}} */

 extern const MIDL_STUBLESS_PROXY_INFO RpcServerInterface2_ProxyInfo;
handle_t hRpcServerInterface2Binding;


static const RPC_CLIENT_INTERFACE RpcServerInterface2___RpcClientInterface =
    {
    sizeof(RPC_CLIENT_INTERFACE),
    {{0xfa161e81,0x6e93,0x4f41,{0x96,0x1c,0xee,0x9c,0x2e,0x75,0xde,0x18}},{1,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    0,
    0,
    0,
    0,
    &RpcServerInterface2_ProxyInfo,
    0x02000000
    };
RPC_IF_HANDLE RpcServerInterface2_v1_0_c_ifspec = (RPC_IF_HANDLE)& RpcServerInterface2___RpcClientInterface;

extern const MIDL_STUB_DESC RpcServerInterface2_StubDesc;

static RPC_BINDING_HANDLE RpcServerInterface2__MIDL_AutoBindHandle;


void Shutdown2( void)
{

    NdrClientCall3(
                  ( PMIDL_STUBLESS_PROXY_INFO  )&RpcServerInterface2_ProxyInfo,
                  0,
                  0,
                  0);
    
}


#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const RpcServerInterface2_MIDL_PROC_FORMAT_STRING RpcServerInterface2__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure Shutdown2 */

			0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x0 ),	/* 0 */
/* 14 */	0x40,		/* Oi2 Flags:  has ext, */
			0x0,		/* 0 */
/* 16 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */

			0x0
        }
    };

static const RpcServerInterface2_MIDL_TYPE_FORMAT_STRING RpcServerInterface2__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */

			0x0
        }
    };

static const unsigned short RpcServerInterface2_FormatStringOffsetTable[] =
    {
    0
    };



#endif /* defined(_M_AMD64)*/



/* this ALWAYS GENERATED file contains the RPC client stubs */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 21:14:07 2038
 */
/* Compiler settings for RpcServerInterface2.idl:
    Oicf, W4, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if defined(_M_AMD64)




#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif


#include "ndr64types.h"
#include "pshpack8.h"


typedef 
struct 
{
    struct _NDR64_PROC_FORMAT frag1;
}
__midl_frag2_t;
extern const __midl_frag2_t __midl_frag2;

typedef 
NDR64_FORMAT_UINT32
__midl_frag1_t;
extern const __midl_frag1_t __midl_frag1;

static const __midl_frag2_t __midl_frag2 =
{ 
/* Shutdown2 */
    { 
    /* Shutdown2 */      /* procedure Shutdown2 */
        (NDR64_UINT32) 66 /* 0x42 */,    /* primitive handle */ /* IsIntrepreted */
        (NDR64_UINT32) 0 /* 0x0 */ ,  /* Stack size */
        (NDR64_UINT32) 0 /* 0x0 */,
        (NDR64_UINT32) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */
    }
};

static const __midl_frag1_t __midl_frag1 =
(NDR64_UINT32) 0 /* 0x0 */;


#include "poppack.h"


static const FormatInfoRef RpcServerInterface2_Ndr64ProcTable[] =
    {
    &__midl_frag2
    };


static const MIDL_STUB_DESC RpcServerInterface2_StubDesc = 
    {
    (void *)& RpcServerInterface2___RpcClientInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    &hRpcServerInterface2Binding,
    0,
    0,
    0,
    0,
    RpcServerInterface2__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x60001, /* Ndr library version */
    0,
    0x801026e, /* MIDL Version 8.1.622 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x2000001, /* MIDL flag */
    0, /* cs routines */
    (void *)& RpcServerInterface2_ProxyInfo,   /* proxy/server info */
    0
    };

static const MIDL_SYNTAX_INFO RpcServerInterface2_SyntaxInfo [  2 ] = 
    {
    {
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    0,
    RpcServerInterface2__MIDL_ProcFormatString.Format,
    RpcServerInterface2_FormatStringOffsetTable,
    RpcServerInterface2__MIDL_TypeFormatString.Format,
    0,
    0,
    0
    }
    ,{
    {{0x71710533,0xbeba,0x4937,{0x83,0x19,0xb5,0xdb,0xef,0x9c,0xcc,0x36}},{1,0}},
    0,
    0 ,
    (unsigned short *) RpcServerInterface2_Ndr64ProcTable,
    0,
    0,
    0,
    0
    }
    };

static const MIDL_STUBLESS_PROXY_INFO RpcServerInterface2_ProxyInfo =
    {
    &RpcServerInterface2_StubDesc,
    RpcServerInterface2__MIDL_ProcFormatString.Format,
    RpcServerInterface2_FormatStringOffsetTable,
    (RPC_SYNTAX_IDENTIFIER*)&_RpcTransferSyntax,
    2,
    (MIDL_SYNTAX_INFO*)RpcServerInterface2_SyntaxInfo
    
    };

#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* defined(_M_AMD64)*/


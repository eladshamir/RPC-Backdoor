

/* this ALWAYS GENERATED file contains the RPC client stubs */


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

#if defined(_M_AMD64)


#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/

#include <string.h>

#include "RpcServerInterface.h"

#define TYPE_FORMAT_STRING_SIZE   11                                
#define PROC_FORMAT_STRING_SIZE   185                               
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _RpcServerInterface_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } RpcServerInterface_MIDL_TYPE_FORMAT_STRING;

typedef struct _RpcServerInterface_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } RpcServerInterface_MIDL_PROC_FORMAT_STRING;

typedef struct _RpcServerInterface_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } RpcServerInterface_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};

static const RPC_SYNTAX_IDENTIFIER  _NDR64_RpcTransferSyntax = 
{{0x71710533,0xbeba,0x4937,{0x83,0x19,0xb5,0xdb,0xef,0x9c,0xcc,0x36}},{1,0}};



extern const RpcServerInterface_MIDL_TYPE_FORMAT_STRING RpcServerInterface__MIDL_TypeFormatString;
extern const RpcServerInterface_MIDL_PROC_FORMAT_STRING RpcServerInterface__MIDL_ProcFormatString;
extern const RpcServerInterface_MIDL_EXPR_FORMAT_STRING RpcServerInterface__MIDL_ExprFormatString;

#define GENERIC_BINDING_TABLE_SIZE   0            


/* Standard interface: RpcServerInterface, ver. 1.0,
   GUID={0xfa161e81,0x6e93,0x4f41,{0x96,0x1c,0xee,0x9c,0x2e,0x75,0xde,0x17}} */

 extern const MIDL_STUBLESS_PROXY_INFO RpcServerInterface_ProxyInfo;
handle_t hRpcServerInterfaceBinding;


static const RPC_CLIENT_INTERFACE RpcServerInterface___RpcClientInterface =
    {
    sizeof(RPC_CLIENT_INTERFACE),
    {{0xfa161e81,0x6e93,0x4f41,{0x96,0x1c,0xee,0x9c,0x2e,0x75,0xde,0x17}},{1,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    0,
    0,
    0,
    0,
    &RpcServerInterface_ProxyInfo,
    0x02000000
    };
RPC_IF_HANDLE RpcServerInterface_v1_0_c_ifspec = (RPC_IF_HANDLE)& RpcServerInterface___RpcClientInterface;

extern const MIDL_STUB_DESC RpcServerInterface_StubDesc;

static RPC_BINDING_HANDLE RpcServerInterface__MIDL_AutoBindHandle;


void Execute( 
    /* [in] */ LPSTR *Command,
    /* [out] */ LPSTR *Output)
{

    NdrClientCall3(
                  ( PMIDL_STUBLESS_PROXY_INFO  )&RpcServerInterface_ProxyInfo,
                  0,
                  0,
                  Command,
                  Output);
    
}


void ExecuteWithToken( 
    /* [in] */ LPSTR *Command,
    /* [in] */ int ProcessId,
    /* [out] */ LPSTR *Output)
{

    NdrClientCall3(
                  ( PMIDL_STUBLESS_PROXY_INFO  )&RpcServerInterface_ProxyInfo,
                  1,
                  0,
                  Command,
                  ProcessId,
                  Output);
    
}


void Download( 
    /* [in] */ LPSTR *Path,
    /* [out] */ LPSTR *Data)
{

    NdrClientCall3(
                  ( PMIDL_STUBLESS_PROXY_INFO  )&RpcServerInterface_ProxyInfo,
                  2,
                  0,
                  Path,
                  Data);
    
}


void Upload( 
    /* [in] */ LPSTR *Path,
    /* [in] */ LPSTR *Data)
{

    NdrClientCall3(
                  ( PMIDL_STUBLESS_PROXY_INFO  )&RpcServerInterface_ProxyInfo,
                  3,
                  0,
                  Path,
                  Data);
    
}


void Shutdown( void)
{

    NdrClientCall3(
                  ( PMIDL_STUBLESS_PROXY_INFO  )&RpcServerInterface_ProxyInfo,
                  4,
                  0,
                  0);
    
}


#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const RpcServerInterface_MIDL_PROC_FORMAT_STRING RpcServerInterface__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure Execute */

			0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x0 ),	/* 0 */
/* 14 */	0x43,		/* Oi2 Flags:  srv must size, clt must size, has ext, */
			0x2,		/* 2 */
/* 16 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Command */

/* 26 */	NdrFcShort( 0x200b ),	/* Flags:  must size, must free, in, srv alloc size=8 */
/* 28 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 30 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter Output */

/* 32 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 34 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 36 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Procedure ExecuteWithToken */

/* 38 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 40 */	NdrFcLong( 0x0 ),	/* 0 */
/* 44 */	NdrFcShort( 0x1 ),	/* 1 */
/* 46 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 48 */	NdrFcShort( 0x8 ),	/* 8 */
/* 50 */	NdrFcShort( 0x0 ),	/* 0 */
/* 52 */	0x43,		/* Oi2 Flags:  srv must size, clt must size, has ext, */
			0x3,		/* 3 */
/* 54 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */
/* 60 */	NdrFcShort( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Command */

/* 64 */	NdrFcShort( 0x200b ),	/* Flags:  must size, must free, in, srv alloc size=8 */
/* 66 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 68 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter ProcessId */

/* 70 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 72 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 74 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Output */

/* 76 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 78 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 80 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Procedure Download */

/* 82 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 84 */	NdrFcLong( 0x0 ),	/* 0 */
/* 88 */	NdrFcShort( 0x2 ),	/* 2 */
/* 90 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 92 */	NdrFcShort( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */
/* 96 */	0x43,		/* Oi2 Flags:  srv must size, clt must size, has ext, */
			0x2,		/* 2 */
/* 98 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 100 */	NdrFcShort( 0x0 ),	/* 0 */
/* 102 */	NdrFcShort( 0x0 ),	/* 0 */
/* 104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 106 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Path */

/* 108 */	NdrFcShort( 0x200b ),	/* Flags:  must size, must free, in, srv alloc size=8 */
/* 110 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 112 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter Data */

/* 114 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 116 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 118 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Procedure Upload */

/* 120 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 122 */	NdrFcLong( 0x0 ),	/* 0 */
/* 126 */	NdrFcShort( 0x3 ),	/* 3 */
/* 128 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 134 */	0x42,		/* Oi2 Flags:  clt must size, has ext, */
			0x2,		/* 2 */
/* 136 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 144 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Path */

/* 146 */	NdrFcShort( 0x200b ),	/* Flags:  must size, must free, in, srv alloc size=8 */
/* 148 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 150 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter Data */

/* 152 */	NdrFcShort( 0x200b ),	/* Flags:  must size, must free, in, srv alloc size=8 */
/* 154 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 156 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Procedure Shutdown */

/* 158 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 160 */	NdrFcLong( 0x0 ),	/* 0 */
/* 164 */	NdrFcShort( 0x4 ),	/* 4 */
/* 166 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 172 */	0x40,		/* Oi2 Flags:  has ext, */
			0x0,		/* 0 */
/* 174 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 182 */	NdrFcShort( 0x0 ),	/* 0 */

			0x0
        }
    };

static const RpcServerInterface_MIDL_TYPE_FORMAT_STRING RpcServerInterface__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/*  4 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6) */
/*  6 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/*  8 */	
			0x22,		/* FC_C_CSTRING */
			0x5c,		/* FC_PAD */

			0x0
        }
    };

static const unsigned short RpcServerInterface_FormatStringOffsetTable[] =
    {
    0,
    38,
    82,
    120,
    158
    };



#endif /* defined(_M_AMD64)*/



/* this ALWAYS GENERATED file contains the RPC client stubs */


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
__midl_frag31_t;
extern const __midl_frag31_t __midl_frag31;

typedef 
struct _NDR64_CONFORMANT_STRING_FORMAT
__midl_frag30_t;
extern const __midl_frag30_t __midl_frag30;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag29_t;
extern const __midl_frag29_t __midl_frag29;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag28_t;
extern const __midl_frag28_t __midl_frag28;

typedef 
struct 
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_PARAM_FORMAT frag2;
    struct _NDR64_PARAM_FORMAT frag3;
}
__midl_frag24_t;
extern const __midl_frag24_t __midl_frag24;

typedef 
struct 
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_PARAM_FORMAT frag2;
    struct _NDR64_PARAM_FORMAT frag3;
}
__midl_frag17_t;
extern const __midl_frag17_t __midl_frag17;

typedef 
NDR64_FORMAT_CHAR
__midl_frag13_t;
extern const __midl_frag13_t __midl_frag13;

typedef 
struct 
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_PARAM_FORMAT frag2;
    struct _NDR64_PARAM_FORMAT frag3;
    struct _NDR64_PARAM_FORMAT frag4;
}
__midl_frag9_t;
extern const __midl_frag9_t __midl_frag9;

typedef 
NDR64_FORMAT_UINT32
__midl_frag1_t;
extern const __midl_frag1_t __midl_frag1;

static const __midl_frag31_t __midl_frag31 =
{ 
/* Shutdown */
    { 
    /* Shutdown */      /* procedure Shutdown */
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

static const __midl_frag30_t __midl_frag30 =
{ 
/* *CHAR */
    { 
    /* *CHAR */
        0x63,    /* FC64_CONF_CHAR_STRING */
        { 
        /* *CHAR */
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT16) 1 /* 0x1 */
    }
};

static const __midl_frag29_t __midl_frag29 =
{ 
/* *CHAR */
    0x21,    /* FC64_UP */
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag30
};

static const __midl_frag28_t __midl_frag28 =
{ 
/* **CHAR */
    0x20,    /* FC64_RP */
    (NDR64_UINT8) 20 /* 0x14 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag29
};

static const __midl_frag24_t __midl_frag24 =
{ 
/* Upload */
    { 
    /* Upload */      /* procedure Upload */
        (NDR64_UINT32) 262210 /* 0x40042 */,    /* primitive handle */ /* IsIntrepreted, ClientMustSize */
        (NDR64_UINT32) 16 /* 0x10 */ ,  /* Stack size */
        (NDR64_UINT32) 0 /* 0x0 */,
        (NDR64_UINT32) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 2 /* 0x2 */,
        (NDR64_UINT16) 0 /* 0x0 */
    },
    { 
    /* Path */      /* parameter Path */
        &__midl_frag28,
        { 
        /* Path */
            1,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            1
        },    /* MustSize, MustFree, [in], UseCache */
        (NDR64_UINT16) 0 /* 0x0 */,
        0 /* 0x0 */,   /* Stack offset */
    },
    { 
    /* Data */      /* parameter Data */
        &__midl_frag28,
        { 
        /* Data */
            1,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            1
        },    /* MustSize, MustFree, [in], UseCache */
        (NDR64_UINT16) 0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    }
};

static const __midl_frag17_t __midl_frag17 =
{ 
/* Download */
    { 
    /* Download */      /* procedure Download */
        (NDR64_UINT32) 393282 /* 0x60042 */,    /* primitive handle */ /* IsIntrepreted, ServerMustSize, ClientMustSize */
        (NDR64_UINT32) 16 /* 0x10 */ ,  /* Stack size */
        (NDR64_UINT32) 0 /* 0x0 */,
        (NDR64_UINT32) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 2 /* 0x2 */,
        (NDR64_UINT16) 0 /* 0x0 */
    },
    { 
    /* Path */      /* parameter Path */
        &__midl_frag28,
        { 
        /* Path */
            1,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            1
        },    /* MustSize, MustFree, [in], UseCache */
        (NDR64_UINT16) 0 /* 0x0 */,
        0 /* 0x0 */,   /* Stack offset */
    },
    { 
    /* Data */      /* parameter Data */
        &__midl_frag28,
        { 
        /* Data */
            1,
            1,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            1
        },    /* MustSize, MustFree, [out], UseCache */
        (NDR64_UINT16) 0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    }
};

static const __midl_frag13_t __midl_frag13 =
0x5    /* FC64_INT32 */;

static const __midl_frag9_t __midl_frag9 =
{ 
/* ExecuteWithToken */
    { 
    /* ExecuteWithToken */      /* procedure ExecuteWithToken */
        (NDR64_UINT32) 393282 /* 0x60042 */,    /* primitive handle */ /* IsIntrepreted, ServerMustSize, ClientMustSize */
        (NDR64_UINT32) 24 /* 0x18 */ ,  /* Stack size */
        (NDR64_UINT32) 8 /* 0x8 */,
        (NDR64_UINT32) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 3 /* 0x3 */,
        (NDR64_UINT16) 0 /* 0x0 */
    },
    { 
    /* Command */      /* parameter Command */
        &__midl_frag28,
        { 
        /* Command */
            1,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            1
        },    /* MustSize, MustFree, [in], UseCache */
        (NDR64_UINT16) 0 /* 0x0 */,
        0 /* 0x0 */,   /* Stack offset */
    },
    { 
    /* ProcessId */      /* parameter ProcessId */
        &__midl_frag13,
        { 
        /* ProcessId */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    },
    { 
    /* Output */      /* parameter Output */
        &__midl_frag28,
        { 
        /* Output */
            1,
            1,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            1
        },    /* MustSize, MustFree, [out], UseCache */
        (NDR64_UINT16) 0 /* 0x0 */,
        16 /* 0x10 */,   /* Stack offset */
    }
};

static const __midl_frag1_t __midl_frag1 =
(NDR64_UINT32) 0 /* 0x0 */;


#include "poppack.h"


static const FormatInfoRef RpcServerInterface_Ndr64ProcTable[] =
    {
    &__midl_frag17,
    &__midl_frag9,
    &__midl_frag17,
    &__midl_frag24,
    &__midl_frag31
    };


static const MIDL_STUB_DESC RpcServerInterface_StubDesc = 
    {
    (void *)& RpcServerInterface___RpcClientInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    &hRpcServerInterfaceBinding,
    0,
    0,
    0,
    0,
    RpcServerInterface__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x60001, /* Ndr library version */
    0,
    0x801026e, /* MIDL Version 8.1.622 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x2000001, /* MIDL flag */
    0, /* cs routines */
    (void *)& RpcServerInterface_ProxyInfo,   /* proxy/server info */
    0
    };

static const MIDL_SYNTAX_INFO RpcServerInterface_SyntaxInfo [  2 ] = 
    {
    {
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    0,
    RpcServerInterface__MIDL_ProcFormatString.Format,
    RpcServerInterface_FormatStringOffsetTable,
    RpcServerInterface__MIDL_TypeFormatString.Format,
    0,
    0,
    0
    }
    ,{
    {{0x71710533,0xbeba,0x4937,{0x83,0x19,0xb5,0xdb,0xef,0x9c,0xcc,0x36}},{1,0}},
    0,
    0 ,
    (unsigned short *) RpcServerInterface_Ndr64ProcTable,
    0,
    0,
    0,
    0
    }
    };

static const MIDL_STUBLESS_PROXY_INFO RpcServerInterface_ProxyInfo =
    {
    &RpcServerInterface_StubDesc,
    RpcServerInterface__MIDL_ProcFormatString.Format,
    RpcServerInterface_FormatStringOffsetTable,
    (RPC_SYNTAX_IDENTIFIER*)&_RpcTransferSyntax,
    2,
    (MIDL_SYNTAX_INFO*)RpcServerInterface_SyntaxInfo
    
    };

#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* defined(_M_AMD64)*/


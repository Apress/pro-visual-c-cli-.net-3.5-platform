

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Oct 16 23:43:55 2008
 */
/* Compiler settings for vc90.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __vc90_h__
#define __vc90_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ITestCOM_FWD_DEFINED__
#define __ITestCOM_FWD_DEFINED__
typedef interface ITestCOM ITestCOM;
#endif 	/* __ITestCOM_FWD_DEFINED__ */


#ifndef __CTestCOM_FWD_DEFINED__
#define __CTestCOM_FWD_DEFINED__

#ifdef __cplusplus
typedef class CTestCOM CTestCOM;
#else
typedef struct CTestCOM CTestCOM;
#endif /* __cplusplus */

#endif 	/* __CTestCOM_FWD_DEFINED__ */


/* header files for imported files */
#include "docobj.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ITestCOM_INTERFACE_DEFINED__
#define __ITestCOM_INTERFACE_DEFINED__

/* interface ITestCOM */
/* [object][dual][uuid] */ 


EXTERN_C const IID IID_ITestCOM;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F0FD23AE-CAC9-3485-95DC-E5B53A6FB09F")
    ITestCOM : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Square( 
            /* [in] */ LONG Value,
            /* [retval][out] */ LONG *Result) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITestCOMVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITestCOM * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITestCOM * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITestCOM * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITestCOM * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITestCOM * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITestCOM * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITestCOM * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Square )( 
            ITestCOM * This,
            /* [in] */ LONG Value,
            /* [retval][out] */ LONG *Result);
        
        END_INTERFACE
    } ITestCOMVtbl;

    interface ITestCOM
    {
        CONST_VTBL struct ITestCOMVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITestCOM_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITestCOM_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITestCOM_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITestCOM_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITestCOM_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITestCOM_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITestCOM_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITestCOM_Square(This,Value,Result)	\
    ( (This)->lpVtbl -> Square(This,Value,Result) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITestCOM_INTERFACE_DEFINED__ */



#ifndef __TestCOM_LIBRARY_DEFINED__
#define __TestCOM_LIBRARY_DEFINED__

/* library TestCOM */
/* [uuid][version] */ 


EXTERN_C const IID LIBID_TestCOM;

EXTERN_C const CLSID CLSID_CTestCOM;

#ifdef __cplusplus

class DECLSPEC_UUID("876C33E0-4A52-3769-A61A-5E01E4B82579")
CTestCOM;
#endif
#endif /* __TestCOM_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



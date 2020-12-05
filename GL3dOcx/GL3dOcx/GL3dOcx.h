#if !defined(AFX_GL3DOCX_H__A015E028_7691_11D3_955D_8422F5C00000__INCLUDED_)
#define AFX_GL3DOCX_H__A015E028_7691_11D3_955D_8422F5C00000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// GL3dOcx.h : main header file for GL3DOCX.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGL3dOcxApp : See GL3dOcx.cpp for implementation.

class CGL3dOcxApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GL3DOCX_H__A015E028_7691_11D3_955D_8422F5C00000__INCLUDED)

// greet.h : main header file for the GREET application
//

#if !defined(AFX_GREET_H__1064AF85_AE5A_11D3_955D_4491F5C00000__INCLUDED_)
#define AFX_GREET_H__1064AF85_AE5A_11D3_955D_4491F5C00000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGreetApp:
// See greet.cpp for the implementation of this class
//

class CGreetApp : public CWinApp
{
public:
	CGreetApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGreetApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGreetApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GREET_H__1064AF85_AE5A_11D3_955D_4491F5C00000__INCLUDED_)

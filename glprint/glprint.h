// glprint.h : main header file for the GLPRINT application
//

#if !defined(AFX_GLPRINT_H__02F85A45_5671_11D3_955D_8422F5C00000__INCLUDED_)
#define AFX_GLPRINT_H__02F85A45_5671_11D3_955D_8422F5C00000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGlprintApp:
// See glprint.cpp for the implementation of this class
//

class CGlprintApp : public CWinApp
{
public:
	CGlprintApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGlprintApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGlprintApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////


//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GLPRINT_H__02F85A45_5671_11D3_955D_8422F5C00000__INCLUDED_)

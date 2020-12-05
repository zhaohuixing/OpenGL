// Y2KSaver.h : main header file for the Y2KSAVER application
//

#if !defined(AFX_Y2KSAVER_H__B3DDF165_B249_11D3_955D_44B1F5C00000__INCLUDED_)
#define AFX_Y2KSAVER_H__B3DDF165_B249_11D3_955D_44B1F5C00000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "SaverWnd.h"

/////////////////////////////////////////////////////////////////////////////
// CY2KSaverApp:
// See Y2KSaver.cpp for the implementation of this class
//
enum enmCMDline 
{
	 CMD_SETTING,
	 CMD_PREVIEW,
	 CMD_SAVER,
	 CMD_NONE
};


class CY2KSaverApp : public CWinApp
{
public:
	CY2KSaverApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CY2KSaverApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CY2KSaverApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
    
	enmCMDline getCMDline(LPTSTR pszCmd);    
	void DoSaverSetting(void);
	void DoSaverPreview(void);
    void DoScreenSaver(void);
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_Y2KSAVER_H__B3DDF165_B249_11D3_955D_44B1F5C00000__INCLUDED_)

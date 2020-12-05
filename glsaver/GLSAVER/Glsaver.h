// glsaver.h : main header file for the GLSAVER application
//

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		
#include "saverdef.h"
#include "SaverWnd.h"
#include "RegKey.h"

/////////////////////////////////////////////////////////////////////////////
// CGlsaverApp:
// See glsaver.cpp for the implementation of this class
//



class CGlsaverApp : public CWinApp
{
public:
	CGlsaverApp();


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGlsaverApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGlsaverApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

    enmCMDline getCMDline(LPTSTR pszCmd);    
	void DoSaverSetting(void);
	void DoSaverPreview(void);
    void DoScreenSaver(void);

    SAVERSETTING  m_sSetting;

private:
	BOOL ReadSetting(SAVERSETTING* sSetting);
	BOOL WriteSetting(SAVERSETTING& sSetting);
};



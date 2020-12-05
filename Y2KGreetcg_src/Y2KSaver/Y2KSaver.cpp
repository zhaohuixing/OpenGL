// Y2KSaver.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Y2KSaver.h"
#include "SettingDlg.h"
#include "RegKey.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CY2KSaverApp

BEGIN_MESSAGE_MAP(CY2KSaverApp, CWinApp)
	//{{AFX_MSG_MAP(CY2KSaverApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CY2KSaverApp construction

CY2KSaverApp::CY2KSaverApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CY2KSaverApp object

CY2KSaverApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CY2KSaverApp initialization

BOOL CY2KSaverApp::InitInstance()
{

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.
	Enable3dControls();

    enmCMDline cmdLine;	
    
	cmdLine = getCMDline(__argv[1]);

	
	if (__argc == 1 || getCMDline(__argv[1]) == CMD_SETTING)
	     DoSaverSetting();
    else if(getCMDline(__argv[1]) == CMD_PREVIEW)
	{
	     DoSaverPreview();
		 return TRUE;
	}
    else if(getCMDline(__argv[1]) == CMD_SAVER)
    {
		 DoScreenSaver();
		 return TRUE;
	}

	// Nothing happened, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}


enmCMDline CY2KSaverApp::getCMDline(LPTSTR pszCmd)
{
	if (pszCmd[0] == _T('-') || pszCmd[0] == _T('/'))
		pszCmd++;

	LPTSTR  pszChar = pszCmd;
    
	switch(*pszChar)
    {
	    case _T('c'):
			 return CMD_SETTING;
	    case _T('C'):
			 return CMD_SETTING;
	    case _T('p'):
			 return CMD_PREVIEW;
	    case _T('P'):
			 return CMD_PREVIEW;
	    case _T('s'):
			 return CMD_SAVER;
	    case _T('S'):
			 return CMD_SAVER;
        default: 
			 return CMD_NONE;
	}
}


void CY2KSaverApp::DoSaverSetting(void)
{
	CSettingDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();
}


void CY2KSaverApp::DoSaverPreview(void)
{
	CWnd* pParent = CWnd::FromHandle((HWND)atol(__argv[2]));
	ASSERT(pParent != NULL);
	CGLControl* pWnd = new CGLControl();
	CRect rect;
	pParent->GetClientRect(&rect);
	pWnd->SetPlayOn(FALSE);
	pWnd->SetFogStatus(FALSE);
	pWnd->SetWordOnly(TRUE);
	pWnd->Create(WS_EX_TOPMOST, WS_VISIBLE|WS_CHILD, rect, pParent, pParent->GetDlgCtrlID());
	m_pMainWnd = pWnd;
}


void CY2KSaverApp::DoScreenSaver(void)
{
	CRegisterKey regkey;
    BOOL bPlay = FALSE;
	static CSaverWnd* pWnd = new CSaverWnd;
    char Reg_Path[] = "Software\\ScreenSaver\\Y2KSaver";

	if (regkey.Open (HKEY_LOCAL_MACHINE, Reg_Path) == ERROR_SUCCESS)
	{
		if(regkey.Read("PLAY", &bPlay) == ERROR_SUCCESS)
		{
	        regkey.Close();		
		}
		else
        {
			bPlay = FALSE;
	        regkey.Close();		
		}
	}
	else
	{
		bPlay = FALSE;
        regkey.Close();		
	}
    
	pWnd->SetPlayOn(bPlay);
	pWnd->SetMidiName("Saver.mid");
	pWnd->SetFogColors(0.5, 0.5, 0.9, 0.1, 0.25);
	pWnd->Create();
	m_pMainWnd = pWnd;
}








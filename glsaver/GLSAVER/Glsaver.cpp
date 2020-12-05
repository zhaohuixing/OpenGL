// glsaver.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "glsaver.h"
#include "SettingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "ImageWnd.h"

static char Reg_Path[] = "Software\\ScreenSaver\\glSaver";


/////////////////////////////////////////////////////////////////////////////
// CGlsaverApp

BEGIN_MESSAGE_MAP(CGlsaverApp, CWinApp)
	//{{AFX_MSG_MAP(CGlsaverApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGlsaverApp construction


CGlsaverApp::CGlsaverApp()
{
	// TODO: add construction code here,
	m_sSetting.m_enmType = CSG_BOTH;
	m_sSetting.m_enmBallSize = BALL_SMALL;
	m_sSetting.m_enmWaveType = WAVE_RECTANGLE;
    m_sSetting.m_bFog = FALSE;
    m_sSetting.m_iFDensity = MIN_FOG_DENSITY;
    m_sSetting.m_iFColorRed = MAX_FOG_COLOR;
    m_sSetting.m_iFColorGreen = MIN_FOG_COLOR;
    m_sSetting.m_iFColorBlue = MIN_FOG_COLOR;
    m_sSetting.m_iFColorAlpha = MAX_FOG_COLOR;
    m_sSetting.m_enmTextureB = TEX_CHECKER;
    m_sSetting.m_enmTextureW = TEX_CHECKER;
    m_sSetting.m_btTexMasterRed = 255;    
    m_sSetting.m_btTexMasterGreen = 0;    
    m_sSetting.m_btTexMasterBlue = 0;
    m_sSetting.m_btTexSecondRed = 255;    
    m_sSetting.m_btTexSecondGreen = 0;    
    m_sSetting.m_btTexSecondBlue = 255;
    m_sSetting.m_btTexAlpha = 0;    
    m_sSetting.m_iTexChkSizeX = 16;
    m_sSetting.m_iTexChkSizeY = 16;
	m_sSetting.m_iSpeed = MIN_TIME_INTERVAL;    
    m_sSetting.m_iGridNumber = 4;

	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CGlsaverApp object

CGlsaverApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CGlsaverApp initialization

BOOL CGlsaverApp::InitInstance()
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


enmCMDline CGlsaverApp::getCMDline(LPTSTR pszCmd)
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


void CGlsaverApp::DoSaverSetting(void)
{
	
    ReadSetting(&m_sSetting);
	CSettingDlg dlg;
	dlg.SetData(&m_sSetting);
	m_pMainWnd = &dlg;
	if (dlg.DoModal() == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
	    dlg.GetData(&m_sSetting);
        WriteSetting(m_sSetting);
	}

}


void CGlsaverApp::DoSaverPreview(void)
{
	CWnd* pParent = CWnd::FromHandle((HWND)atol(__argv[2]));
	ASSERT(pParent != NULL);
	CImageWnd* pWnd = new CImageWnd();
    ReadSetting(&m_sSetting);
    pWnd->SetSaverSetting(&m_sSetting);
	CRect rect;
	pParent->GetClientRect(&rect);
	pWnd->Create(NULL, WS_VISIBLE|WS_CHILD, rect, pParent, NULL);
	m_pMainWnd = pWnd;
}


void CGlsaverApp::DoScreenSaver(void)
{
    static CSaverWnd* pWnd = new CSaverWnd;
    ReadSetting(&m_sSetting);
	pWnd->SetSaverSetting(&m_sSetting);
	pWnd->Create();
	m_pMainWnd = pWnd;
}


BOOL CGlsaverApp::ReadSetting(SAVERSETTING* sSetting)
{
	CRegisterKey regkey;
	if (regkey.Open (HKEY_CURRENT_USER, Reg_Path) == ERROR_SUCCESS)
	{
		if(regkey.Read("Setting", sSetting) == ERROR_SUCCESS)
		{
	        regkey.Close();		
			return TRUE;
		}
	}
    
	regkey.Close();		
	return FALSE;
}


BOOL CGlsaverApp::WriteSetting(SAVERSETTING& sSetting)
{
	CRegisterKey regkey;
	if (regkey.Open (HKEY_CURRENT_USER, Reg_Path) == ERROR_SUCCESS)
	{
		if(regkey.Write("Setting", sSetting) == ERROR_SUCCESS)
		{
	        regkey.Close();		
			return TRUE;
		}
	}
    
	regkey.Close();		
	return FALSE;
}
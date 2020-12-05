// SettingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SettingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "RegKey.h"

/////////////////////////////////////////////////////////////////////////////
// CSettingDlg dialog

CSettingDlg::CSettingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSettingDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    
	m_bPlayMusic = FALSE;
}

void CSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSettingDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSettingDlg, CDialog)
	//{{AFX_MSG_MAP(CSettingDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSettingDlg message handlers

BOOL CSettingDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	CRegisterKey regkey;
    char Reg_Path[] = "Software\\ScreenSaver\\Y2KSaver";
	if (regkey.Open (HKEY_LOCAL_MACHINE, Reg_Path) == ERROR_SUCCESS)
	{
		regkey.Read("PLAY", &m_bPlayMusic);
	}
    regkey.Close();		
	
	
	CRect rect;
	GetDlgItem(IDC_IMAGE)->GetWindowRect(&rect);
	ScreenToClient(&rect);
      
	((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(m_bPlayMusic);
	m_wndImage.SetPlayOn(m_bPlayMusic);
    m_wndImage.SetMidiName("Set.mid"); 
	m_wndImage.SetFogColors(0.5, 0.5, 0.9, 0.1, 0.25);
	m_wndImage.Create(WS_EX_TOPMOST, WS_VISIBLE|WS_CHILD, rect, this, IDC_IMAGE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSettingDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSettingDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSettingDlg::OnDestroy() 
{
	// TODO: Add your message handler code here
//    m_wndImage.SendMessage(WM_DESTROY);
		
	CDialog::OnDestroy();
}

void CSettingDlg::OnCheck1() 
{
	// TODO: Add your control notification handler code here
	m_bPlayMusic = (!m_bPlayMusic);

	CRegisterKey regkey;
    char Reg_Path[] = "Software\\ScreenSaver\\Y2KSaver";
	
	if (regkey.Open (HKEY_LOCAL_MACHINE, Reg_Path) == ERROR_SUCCESS)
	{
		if(regkey.Write("PLAY", m_bPlayMusic) == ERROR_SUCCESS)
	        m_wndImage.PlayMusic(m_bPlayMusic);
		else  //restore old value
	        m_bPlayMusic = (!m_bPlayMusic);
	}
	else //restore old value
        m_bPlayMusic = (!m_bPlayMusic);

    regkey.Close();		

	((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(m_bPlayMusic);
}

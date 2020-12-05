// SettingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SettingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
	ON_BN_CLICKED(IDC_FOGCHECK, OnFogcheck)
	ON_BN_CLICKED(IDC_BALL, OnBall)
	ON_BN_CLICKED(IDC_WAVE, OnWave)
	ON_BN_CLICKED(IDC_BOTH, OnBoth)
	ON_BN_CLICKED(IDC_BALLSMALL, OnBallsmall)
	ON_BN_CLICKED(IDC_BALLMEDIUM, OnBallmedium)
	ON_BN_CLICKED(IDC_BALLLARGE, OnBalllarge)
	ON_BN_CLICKED(IDC_WAVERECTANGLE, OnWaverectangle)
	ON_BN_CLICKED(IDC_WAVEROUND, OnWaveround)
	ON_BN_CLICKED(IDC_TEXTURESINGLEB, OnTexturesingleB)
	ON_BN_CLICKED(IDC_TEXTURECHECKERB, OnTexturecheckerB)
	ON_BN_CLICKED(IDC_TEXTURENOISEB, OnTexturenoiseB)
	ON_BN_CLICKED(IDC_TEXTURESINGLEW, OnTexturesingleW)
	ON_BN_CLICKED(IDC_TEXTURECHECKERW, OnTexturecheckerW)
	ON_BN_CLICKED(IDC_TEXTURENOISEW, OnTexturenoiseW)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_BN_CLICKED(IDC_BALLLINE, OnBallline)
	ON_BN_CLICKED(IDC_WAVELINE, OnWaveline)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSettingDlg message handlers

/////////////////////////////////////////////////////////////////////////////
// Set saver setting data
/////////////////////////////////////////////////////////////////////////////
void CSettingDlg::SetData(SAVERSETTING*  setting)
{
    memcpy(&m_setting, setting, sizeof(SAVERSETTING));
}


/////////////////////////////////////////////////////////////////////////////
// Get saver setting data
/////////////////////////////////////////////////////////////////////////////
void CSettingDlg::GetData(SAVERSETTING*  setting)
{
    memcpy(setting, &m_setting, sizeof(SAVERSETTING));
}


/////////////////////////////////////////////////////////////////////////////
// Set the dialog box control status based on the saversetting data
/////////////////////////////////////////////////////////////////////////////
void CSettingDlg::SetControl(void)
{
	//set all radio button status
	((CButton*)GetDlgItem(IDC_FOGCHECK))->SetCheck(m_setting.m_bFog == TRUE ? TRUE : FALSE);
	((CButton*)GetDlgItem(IDC_BALLLINE))->SetCheck(m_setting.m_bBallLine == TRUE ? TRUE : FALSE);
	((CButton*)GetDlgItem(IDC_WAVELINE))->SetCheck(m_setting.m_bWaveLine == TRUE ? TRUE : FALSE);
	((CButton*)GetDlgItem(IDC_BALL))->SetCheck(m_setting.m_enmType == CSG_BALL ? TRUE : FALSE);
	((CButton*)GetDlgItem(IDC_WAVE))->SetCheck(m_setting.m_enmType == CSG_WAVE ? TRUE : FALSE);
	((CButton*)GetDlgItem(IDC_BOTH))->SetCheck(m_setting.m_enmType == CSG_BOTH ? TRUE : FALSE);
	((CButton*)GetDlgItem(IDC_BALLSMALL))->SetCheck(m_setting.m_enmBallSize == BALL_SMALL ? TRUE : FALSE);
	((CButton*)GetDlgItem(IDC_BALLMEDIUM))->SetCheck(m_setting.m_enmBallSize == BALL_MEDIUM ? TRUE : FALSE);
	((CButton*)GetDlgItem(IDC_BALLLARGE))->SetCheck(m_setting.m_enmBallSize == BALL_LARGE ? TRUE : FALSE);
	((CButton*)GetDlgItem(IDC_WAVERECTANGLE))->SetCheck(m_setting.m_enmWaveType == WAVE_RECTANGLE ? TRUE : FALSE);
	((CButton*)GetDlgItem(IDC_WAVEROUND))->SetCheck(m_setting.m_enmWaveType == WAVE_ROUND ? TRUE : FALSE);
	((CButton*)GetDlgItem(IDC_TEXTURESINGLEB))->SetCheck(m_setting.m_enmTextureB == TEX_SINGLE ? TRUE : FALSE);
	((CButton*)GetDlgItem(IDC_TEXTURECHECKERB))->SetCheck(m_setting.m_enmTextureB == TEX_CHECKER ? TRUE : FALSE);
	((CButton*)GetDlgItem(IDC_TEXTURENOISEB))->SetCheck(m_setting.m_enmTextureB == TEX_NOISE ? TRUE : FALSE);
	((CButton*)GetDlgItem(IDC_TEXTURESINGLEW))->SetCheck(m_setting.m_enmTextureW == TEX_SINGLE ? TRUE : FALSE);
	((CButton*)GetDlgItem(IDC_TEXTURECHECKERW))->SetCheck(m_setting.m_enmTextureW == TEX_CHECKER ? TRUE : FALSE);
	((CButton*)GetDlgItem(IDC_TEXTURENOISEW))->SetCheck(m_setting.m_enmTextureW == TEX_NOISE ? TRUE : FALSE);


	//set all slider control status
	((CSliderCtrl*)GetDlgItem(IDC_SPEED))->SetRange(MIN_TIME_INTERVAL, MAX_TIME_INTERVAL);
    ((CSliderCtrl*)GetDlgItem(IDC_SPEED))->SetTicFreq(10);
    ((CSliderCtrl*)GetDlgItem(IDC_SPEED))->SetPos(m_setting.m_iSpeed);

	((CSliderCtrl*)GetDlgItem(IDC_SMOOTH))->SetRange(MIN_GRID, MAX_GRID);
    ((CSliderCtrl*)GetDlgItem(IDC_SMOOTH))->SetTicFreq(1);
    ((CSliderCtrl*)GetDlgItem(IDC_SMOOTH))->SetPos(m_setting.m_iGridNumber);

	((CSliderCtrl*)GetDlgItem(IDC_FOGDENSITY))->SetRange(MIN_FOG_DENSITY, MAX_FOG_DENSITY);
    ((CSliderCtrl*)GetDlgItem(IDC_FOGDENSITY))->SetTicFreq(32);
    ((CSliderCtrl*)GetDlgItem(IDC_FOGDENSITY))->SetPos(m_setting.m_iFDensity);
	
	((CSliderCtrl*)GetDlgItem(IDC_FOGRED))->SetRange(MIN_FOG_COLOR, MAX_FOG_COLOR);
    ((CSliderCtrl*)GetDlgItem(IDC_FOGRED))->SetTicFreq(32);
    ((CSliderCtrl*)GetDlgItem(IDC_FOGRED))->SetPos(m_setting.m_iFColorRed);

	((CSliderCtrl*)GetDlgItem(IDC_FOGGREEN))->SetRange(MIN_FOG_COLOR, MAX_FOG_COLOR);
    ((CSliderCtrl*)GetDlgItem(IDC_FOGGREEN))->SetTicFreq(32);
    ((CSliderCtrl*)GetDlgItem(IDC_FOGGREEN))->SetPos(m_setting.m_iFColorGreen);

	((CSliderCtrl*)GetDlgItem(IDC_FOGBLUE))->SetRange(MIN_FOG_COLOR, MAX_FOG_COLOR);
    ((CSliderCtrl*)GetDlgItem(IDC_FOGBLUE))->SetTicFreq(32);
    ((CSliderCtrl*)GetDlgItem(IDC_FOGBLUE))->SetPos(m_setting.m_iFColorBlue);

	((CSliderCtrl*)GetDlgItem(IDC_FOGALPHA))->SetRange(MIN_FOG_COLOR, MAX_FOG_COLOR);
    ((CSliderCtrl*)GetDlgItem(IDC_FOGALPHA))->SetTicFreq(32);
    ((CSliderCtrl*)GetDlgItem(IDC_FOGALPHA))->SetPos(m_setting.m_iFColorAlpha);
	

	((CSliderCtrl*)GetDlgItem(IDC_MASTERRED))->SetRange(0, 255);
    ((CSliderCtrl*)GetDlgItem(IDC_MASTERRED))->SetTicFreq(32);
    ((CSliderCtrl*)GetDlgItem(IDC_MASTERRED))->SetPos(m_setting.m_btTexMasterRed);

	((CSliderCtrl*)GetDlgItem(IDC_MASTERGREEN))->SetRange(0, 255);
    ((CSliderCtrl*)GetDlgItem(IDC_MASTERGREEN))->SetTicFreq(32);
    ((CSliderCtrl*)GetDlgItem(IDC_MASTERGREEN))->SetPos(m_setting.m_btTexMasterGreen);

	((CSliderCtrl*)GetDlgItem(IDC_MASTERBLUE))->SetRange(0, 255);
    ((CSliderCtrl*)GetDlgItem(IDC_MASTERBLUE))->SetTicFreq(32);
    ((CSliderCtrl*)GetDlgItem(IDC_MASTERBLUE))->SetPos(m_setting.m_btTexMasterBlue);

	((CSliderCtrl*)GetDlgItem(IDC_SECONDRED))->SetRange(0, 255);
    ((CSliderCtrl*)GetDlgItem(IDC_SECONDRED))->SetTicFreq(32);
    ((CSliderCtrl*)GetDlgItem(IDC_SECONDRED))->SetPos(m_setting.m_btTexSecondRed);

	((CSliderCtrl*)GetDlgItem(IDC_SECONDGREEN))->SetRange(0, 255);
    ((CSliderCtrl*)GetDlgItem(IDC_SECONDGREEN))->SetTicFreq(32);
    ((CSliderCtrl*)GetDlgItem(IDC_SECONDGREEN))->SetPos(m_setting.m_btTexSecondGreen);

	((CSliderCtrl*)GetDlgItem(IDC_SECONDBLUE))->SetRange(0, 255);
    ((CSliderCtrl*)GetDlgItem(IDC_SECONDBLUE))->SetTicFreq(32);
    ((CSliderCtrl*)GetDlgItem(IDC_SECONDBLUE))->SetPos(m_setting.m_btTexSecondBlue);

	((CSliderCtrl*)GetDlgItem(IDC_ALPHA))->SetRange(0, 255);
    ((CSliderCtrl*)GetDlgItem(IDC_ALPHA))->SetTicFreq(32);
    ((CSliderCtrl*)GetDlgItem(IDC_ALPHA))->SetPos(m_setting.m_btTexAlpha);


	((CSliderCtrl*)GetDlgItem(IDC_CHECKERX))->SetRange(1, 8);
    ((CSliderCtrl*)GetDlgItem(IDC_CHECKERX))->SetTicFreq(1);
    ((CSliderCtrl*)GetDlgItem(IDC_CHECKERX))->SetPos(m_setting.m_iTexChkSizeX);

	((CSliderCtrl*)GetDlgItem(IDC_CHECKERY))->SetRange(1, 8);
    ((CSliderCtrl*)GetDlgItem(IDC_CHECKERY))->SetTicFreq(1);
    ((CSliderCtrl*)GetDlgItem(IDC_CHECKERY))->SetPos(m_setting.m_iTexChkSizeY);


    m_wndImage.SetSaverSetting(&m_setting);
}

BOOL CSettingDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
    SetControl();
	CRect rect;
	GetDlgItem(IDC_IMAGE)->GetWindowRect(&rect);
	ScreenToClient(&rect);
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

void CSettingDlg::OnFogcheck() 
{
	// TODO: Add your control notification handler code here
	m_setting.m_bFog = !m_setting.m_bFog;

    SetControl();	
}

void CSettingDlg::OnBall() 
{
	// TODO: Add your control notification handler code here
    m_setting.m_enmType = CSG_BALL;	

    SetControl();	
}

void CSettingDlg::OnWave() 
{
	// TODO: Add your control notification handler code here
    m_setting.m_enmType = CSG_WAVE;	

    SetControl();	
}

void CSettingDlg::OnBoth() 
{
	// TODO: Add your control notification handler code here
    m_setting.m_enmType = CSG_BOTH;	
    
	m_setting.m_enmBallSize = BALL_SMALL;

    SetControl();	
}

void CSettingDlg::OnBallsmall() 
{
	// TODO: Add your control notification handler code here
	m_setting.m_enmBallSize = BALL_SMALL;

    SetControl();	
}

void CSettingDlg::OnBallmedium() 
{
	// TODO: Add your control notification handler code here
    if(m_setting.m_enmType == CSG_BOTH)	
	   m_setting.m_enmBallSize = BALL_SMALL;
    else
	   m_setting.m_enmBallSize = BALL_MEDIUM;

    SetControl();	
}


void CSettingDlg::OnBalllarge() 
{
	// TODO: Add your control notification handler code here
    if(m_setting.m_enmType == CSG_BOTH)	
	   m_setting.m_enmBallSize = BALL_SMALL;
    else
	   m_setting.m_enmBallSize = BALL_LARGE;

    SetControl();	
}

void CSettingDlg::OnWaverectangle() 
{
	// TODO: Add your control notification handler code here
	m_setting.m_enmWaveType = WAVE_RECTANGLE;
	
    SetControl();	
}

void CSettingDlg::OnWaveround() 
{
	// TODO: Add your control notification handler code here
	m_setting.m_enmWaveType = WAVE_ROUND;
	
    SetControl();	
}


void CSettingDlg::OnTexturesingleB() 
{
	// TODO: Add your control notification handler code here
    m_setting.m_enmTextureB = TEX_SINGLE;
	
    SetControl();	
}

void CSettingDlg::OnTexturecheckerB() 
{
	// TODO: Add your control notification handler code here
	m_setting.m_enmTextureB = TEX_CHECKER;
	
    SetControl();	
}

void CSettingDlg::OnTexturenoiseB() 
{
	// TODO: Add your control notification handler code here
	m_setting.m_enmTextureB = TEX_NOISE;
	
    SetControl();	
}


void CSettingDlg::OnTexturesingleW() 
{
	// TODO: Add your control notification handler code here
    m_setting.m_enmTextureW = TEX_SINGLE;
	
    SetControl();	
}

void CSettingDlg::OnTexturecheckerW() 
{
	// TODO: Add your control notification handler code here
	m_setting.m_enmTextureW = TEX_CHECKER;
	
    SetControl();	
}

void CSettingDlg::OnTexturenoiseW() 
{
	// TODO: Add your control notification handler code here
	m_setting.m_enmTextureW = TEX_NOISE;
	
    SetControl();	
}


void CSettingDlg::OnBallline() 
{
	// TODO: Add your control notification handler code here
    m_setting.m_bBallLine = !m_setting.m_bBallLine;
    
	SetControl();	
}

void CSettingDlg::OnWaveline() 
{
	// TODO: Add your control notification handler code here
	m_setting.m_bWaveLine = !m_setting.m_bWaveLine;	
	
    SetControl();	
}


void CSettingDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	CSliderCtrl* pSlider = (CSliderCtrl*) pScrollBar;
	
    switch(pScrollBar->GetDlgCtrlID()) 
	{
	   case IDC_CHECKERX:
                  m_setting.m_iTexChkSizeX =  
		               ((CSliderCtrl*)GetDlgItem(IDC_CHECKERX))->GetPos();
				  break;
       case IDC_CHECKERY:
                  m_setting.m_iTexChkSizeY = 
					  ((CSliderCtrl*)GetDlgItem(IDC_CHECKERY))->GetPos();
                  break;
       case IDC_FOGALPHA:                   
		          m_setting.m_iFColorAlpha = 
                      ((CSliderCtrl*)GetDlgItem(IDC_FOGALPHA))->GetPos();
				  break;
	   default:
		          break;
	}

    SetControl();	
	
}

void CSettingDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	CSliderCtrl* pSlider = (CSliderCtrl*) pScrollBar;
	
    switch(pScrollBar->GetDlgCtrlID()) 
	{
	   case IDC_SPEED:
                  m_setting.m_iSpeed = 
					  ((CSliderCtrl*)GetDlgItem(IDC_SPEED))->GetPos();
		          break;
       case IDC_SMOOTH:
		          m_setting.m_iGridNumber = 
                      ((CSliderCtrl*)GetDlgItem(IDC_SMOOTH))->GetPos();
                  break;
       case IDC_FOGDENSITY:
		          m_setting.m_iFDensity = 
                      ((CSliderCtrl*)GetDlgItem(IDC_FOGDENSITY))->GetPos();
                  break;
       case IDC_FOGRED:
                  m_setting.m_iFColorRed = 
                      ((CSliderCtrl*)GetDlgItem(IDC_FOGRED))->GetPos();
                  break;
       case IDC_FOGGREEN:
		          m_setting.m_iFColorGreen = 
                      ((CSliderCtrl*)GetDlgItem(IDC_FOGGREEN))->GetPos();
				  break;
       case IDC_FOGBLUE:
		          m_setting.m_iFColorBlue =
                      ((CSliderCtrl*)GetDlgItem(IDC_FOGBLUE))->GetPos();
				  break;
       case IDC_MASTERRED:
		          m_setting.m_btTexMasterRed = 
                      ((CSliderCtrl*)GetDlgItem(IDC_MASTERRED))->GetPos();
                  break;
       case IDC_MASTERGREEN:
		          m_setting.m_btTexMasterGreen = 
                      ((CSliderCtrl*)GetDlgItem(IDC_MASTERGREEN))->GetPos();
                  break;
       case IDC_MASTERBLUE:
		          m_setting.m_btTexMasterBlue =
                      ((CSliderCtrl*)GetDlgItem(IDC_MASTERBLUE))->GetPos();
                  break;
       case IDC_SECONDRED:
		          m_setting.m_btTexSecondRed =
                      ((CSliderCtrl*)GetDlgItem(IDC_SECONDRED))->GetPos();
                  break;
       case IDC_SECONDGREEN:
		          m_setting.m_btTexSecondGreen =
                      ((CSliderCtrl*)GetDlgItem(IDC_SECONDGREEN))->GetPos();
                  break;
       case IDC_SECONDBLUE:
		          m_setting.m_btTexSecondBlue =
                      ((CSliderCtrl*)GetDlgItem(IDC_SECONDBLUE))->GetPos();
                  break;
       case IDC_ALPHA:
		          m_setting.m_btTexAlpha =
                      ((CSliderCtrl*)GetDlgItem(IDC_ALPHA))->GetPos();
                  break;
       default:
		          break;
	}

    SetControl();	
}


void CSettingDlg::OnDestroy() 
{

	// TODO: Add your message handler code here
    m_wndImage.SendMessage(WM_DESTROY);
		
	CDialog::OnDestroy();
}

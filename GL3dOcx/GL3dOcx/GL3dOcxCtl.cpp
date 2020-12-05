// GL3dOcxCtl.cpp : Implementation of the CGL3dOcxCtrl ActiveX Control class.

#include "stdafx.h"
#include "GL3dOcx.h"
#include "GL3dOcxCtl.h"
#include "GL3dOcxPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CGL3dOcxCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CGL3dOcxCtrl, COleControl)
	//{{AFX_MSG_MAP(CGL3dOcxCtrl)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_PAINT()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_PALETTECHANGED()
	ON_WM_QUERYNEWPALETTE()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CGL3dOcxCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CGL3dOcxCtrl)
	DISP_PROPERTY_EX(CGL3dOcxCtrl, "Content", GetContent, SetContent, VT_BSTR)
	DISP_FUNCTION(CGL3dOcxCtrl, "GLRender", GLRender, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CGL3dOcxCtrl, "SetStrText", SetStrText, VT_EMPTY, VTS_BSTR)
	DISP_STOCKPROP_READYSTATE()
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CGL3dOcxCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CGL3dOcxCtrl, COleControl)
	//{{AFX_EVENT_MAP(CGL3dOcxCtrl)
	EVENT_CUSTOM("GLDraw", FireGLDraw, VTS_NONE)
	EVENT_STOCK_READYSTATECHANGE()
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CGL3dOcxCtrl, 1)
	PROPPAGEID(CGL3dOcxPropPage::guid)
END_PROPPAGEIDS(CGL3dOcxCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CGL3dOcxCtrl, "GL3DOCX.GL3dOcxCtrl.1",
	0xa015e022, 0x7691, 0x11d3, 0x95, 0x5d, 0x84, 0x22, 0xf5, 0xc0, 0, 0)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CGL3dOcxCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DGL3dOcx =
		{ 0xa015e020, 0x7691, 0x11d3, { 0x95, 0x5d, 0x84, 0x22, 0xf5, 0xc0, 0, 0 } };
const IID BASED_CODE IID_DGL3dOcxEvents =
		{ 0xa015e021, 0x7691, 0x11d3, { 0x95, 0x5d, 0x84, 0x22, 0xf5, 0xc0, 0, 0 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwGL3dOcxOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_IGNOREACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CGL3dOcxCtrl, IDS_GL3DOCX, _dwGL3dOcxOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CGL3dOcxCtrl::CGL3dOcxCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CGL3dOcxCtrl

BOOL CGL3dOcxCtrl::CGL3dOcxCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_GL3DOCX,
			IDB_GL3DOCX,
			afxRegApartmentThreading,
			_dwGL3dOcxOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CGL3dOcxCtrl::CGL3dOcxCtrl - Constructor

CGL3dOcxCtrl::CGL3dOcxCtrl()
{
	InitializeIIDs(&IID_DGL3dOcx, &IID_DGL3dOcxEvents);

	m_lReadyState = READYSTATE_LOADING;
	// TODO: Call InternalSetReadyState when the readystate changes.

	// TODO: Initialize your control's instance data here.
    m_String = "3DOCX"; 

	m_shininess = 10.0f;
	m_Lightposition[0] = 100.0f;
	m_Lightposition[1] = 0.0f;
	m_Lightposition[2] = 0.0f;
	m_Lightposition[3] = 0.0f;
	m_Lightspecular[0] = 0.3f;
	m_Lightspecular[1] = 0.3f;
	m_Lightspecular[2] = 0.1f;
	m_Lightspecular[3] = 1.0f;
	m_Lightdiffuse[0] = 0.1f;
	m_Lightdiffuse[1] = 0.1f;
	m_Lightdiffuse[2] = 0.1f;
	m_Lightdiffuse[3] = 1.0f;
	m_Lightambient[0] = 0.3f;
	m_Lightambient[1] = 0.3f;
	m_Lightambient[2] = 0.3f;
	m_Lightambient[3] = 1.0f;

	m_cx = 0;
	m_cy = 0;
}


/////////////////////////////////////////////////////////////////////////////
// CGL3dOcxCtrl::~CGL3dOcxCtrl - Destructor

CGL3dOcxCtrl::~CGL3dOcxCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CGL3dOcxCtrl::OnDraw - Drawing function

void CGL3dOcxCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
    FireGLDraw();
}


void CGL3dOcxCtrl::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
    FireGLDraw();
	
	// Do not call COleControl::OnPaint() for painting messages
}



/////////////////////////////////////////////////////////////////////////////
// CGL3dOcxCtrl::DoPropExchange - Persistence support

void CGL3dOcxCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CGL3dOcxCtrl::GetControlFlags -
// Flags to customize MFC's implementation of ActiveX controls.
//
// For information on using these flags, please see MFC technical note
// #nnn, "Optimizing an ActiveX Control".
DWORD CGL3dOcxCtrl::GetControlFlags()
{
	DWORD dwFlags = COleControl::GetControlFlags();


	// The control will not be redrawn when making the transition
	// between the active and inactivate state.
	dwFlags |= noFlickerActivate;

	// The control can receive mouse notifications when inactive.
	// TODO: if you write handlers for WM_SETCURSOR and WM_MOUSEMOVE,
	//		avoid using the m_hWnd member variable without first
	//		checking that its value is non-NULL.
	dwFlags |= pointerInactive;
	return dwFlags;
}


/////////////////////////////////////////////////////////////////////////////
// CGL3dOcxCtrl::OnResetState - Reset control to default state

void CGL3dOcxCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CGL3dOcxCtrl::AboutBox - Display an "About" box to the user

void CGL3dOcxCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_GL3DOCX);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CGL3dOcxCtrl message handlers

void CGL3dOcxCtrl::GLRender() 
{
	// TODO: Add your dispatch handler code here
	int cx, cy;
	GetControlSize(&cx, &cy);
	if(m_cx != cx || m_cy != cy)
	{
	   m_cx = cx;
	   m_cy = cy;
	   SetViewPort();
	}

	dcRender();

}

int CGL3dOcxCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	lpCreateStruct->style |= (WS_CLIPCHILDREN | WS_CLIPSIBLINGS | CS_OWNDC);
	
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	SetupEnv();

    Refresh();

	return 0;
}


void CGL3dOcxCtrl::OnDestroy() 
{
	COleControl::OnDestroy();
	
	// TODO: Add your message handler code here
	wglDeleteContext(m_hRC);
    m_Palette.DeleteObject();
    ReleaseDC(m_pDC);
}


void CGL3dOcxCtrl::SetupEnv(void)
{
	PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW|
		PFD_SUPPORT_OPENGL|
		PFD_DOUBLEBUFFER,  
		PFD_TYPE_RGBA,
		24,
		0,0,0,0,0,0,
        0,0,0,0,0,0,0,
		32,
		0,0,
		PFD_MAIN_PLANE,
		0,
		0,0,0
	};

	//get device context 
	//m_hDC = ::GetDC(this->m_hWnd);
	m_pDC = GetDC();

	int pixelFormat =
		ChoosePixelFormat(m_pDC->m_hDC, &pfd);
	BOOL success = 
		SetPixelFormat(m_pDC->m_hDC, pixelFormat, &pfd);

	DescribePixelFormat(m_pDC->m_hDC, pixelFormat,
		  sizeof(pfd), &pfd);

	if(pfd.dwFlags & PFD_NEED_PALETTE)
        SetupPalette();

	m_hRC = wglCreateContext(m_pDC->m_hDC);

	wglMakeCurrent(m_pDC->m_hDC,m_hRC);

	m_Font.SetXOffset(-0.30f);
	m_Font.SetXScale(1.2f);
	m_Font.SetYScale(1.5f);
	m_Font.SetZScale(1.0f);
	m_Font.SetXRotate(25.0f);
	//m_Font.SetZRotate(-1.0f);

	m_Font.SetFontType(GL_FONT_SOLID);
	m_Font.SetText(m_String);
	m_Font.CreateFont(m_pDC, "Arial Black");

    SetupFontColor();		  

    wglMakeCurrent(m_pDC->m_hDC, NULL);
}


void CGL3dOcxCtrl::SetupPalette(void)
{
	PIXELFORMATDESCRIPTOR pfd;  // Pixel Format Descriptor         
	LOGPALETTE *pPal;			// Pointer to memory for logical palette
	int PixelFormat;			// Pixel format index
    int paletteSize;            // Number of entries in palette 
	BYTE RedMask;               // Range for each color entry (7,7,and 3)
	BYTE GreenMask;
	BYTE BlueMask;

	// Get the pixel format index and retrieve the pixel format description
    PixelFormat = GetPixelFormat(m_pDC->m_hDC);
    DescribePixelFormat(m_pDC->m_hDC, PixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd);
    
	

	// Get the number of entries in palette. 256 colors for 8 bits 
    paletteSize = 1 << pfd.cColorBits;
    
	// Allocate for the logical palette
	pPal = (LOGPALETTE*)
	malloc(sizeof(LOGPALETTE) + paletteSize * sizeof(PALETTEENTRY));
    
	
	// Fill the logical palette header information 
	pPal->palVersion = 0x300;            //support Windows3.0
    pPal->palNumEntries = paletteSize;   //number of colors entries

    // Set the 1st entries of logical palette with the current system palette 
    (void) GetSystemPaletteEntries(m_pDC->m_hDC, 0, paletteSize, &pPal->palPalEntry[0]);

	//Set the RGB mask
	RedMask = (1 << pfd.cRedBits) - 1;
	GreenMask = (1 << pfd.cGreenBits) - 1;
	BlueMask = (1 << pfd.cBlueBits) - 1;

	//Set all entries of the logical palette 
    for (int i=0; i<paletteSize; ++i) 
	{
	    pPal->palPalEntry[i].peRed =
		    (((i >> pfd.cRedShift) & RedMask) * 255) / RedMask;
	    pPal->palPalEntry[i].peGreen =
		    (((i >> pfd.cGreenShift) & GreenMask) * 255) / GreenMask;
	    pPal->palPalEntry[i].peBlue =
		    (((i >> pfd.cBlueShift) & BlueMask) * 255) / BlueMask;
	    pPal->palPalEntry[i].peFlags = 0;
    }

	//Create the palette
    m_Palette.CreatePalette(pPal);

	m_pDC->SelectPalette(&m_Palette, FALSE);
	m_pDC->RealizePalette();

	//Free the memory allocated for the logical palette 
    free(pPal);
}

void CGL3dOcxCtrl::SetupFontColor(void)
{
	float fv[4];
	
	fv[0] = 0.3;
	fv[1] = 0.3;
	fv[2] = 0.3;
	fv[3] = 1.0;
	m_Font.SetEmission(fv);

	fv[0] = 0.4;
	fv[1] = 0.4;
	fv[2] = 0.4;
	fv[3] = 1.0;
	m_Font.SetSpecular(fv);

	fv[0] = 0.4;
	fv[1] = 1.0;
	fv[2] = 0.4;
	fv[3] = 1.0;
	m_Font.SetAmbient(fv);

	fv[0] = 0.3;
	fv[1] = 0.3;
	fv[2] = 0.3;
	fv[3] = 1.0;
	m_Font.SetDiffuse(fv);

	m_Font.SetShininess(0.1f);
}

void CGL3dOcxCtrl::dcRender(void)
{
	wglMakeCurrent(m_pDC->m_hDC, m_hRC);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	
	//clear color buffer
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//set light model
	glLightfv(GL_LIGHT0, GL_AMBIENT, m_Lightambient);//set light ambient
	glLightfv(GL_LIGHT0, GL_DIFFUSE, m_Lightdiffuse);//set light specular
	glLightfv(GL_LIGHT0, GL_SPECULAR, m_Lightspecular);//set light specular
	glLightfv(GL_LIGHT0, GL_POSITION, m_Lightposition);//set light position

	glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(-1.2f, -0.1f, -4.2f);
	
    m_Font.GLDrawText();

	glFlush();


	SwapBuffers(m_pDC->m_hDC);
    wglMakeCurrent(m_pDC->m_hDC, NULL);

}


void CGL3dOcxCtrl::SetViewPort(void)
{
	wglMakeCurrent(m_pDC->m_hDC, m_hRC);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 2.0, 7.0);
	glViewport(0, 0, m_cx, m_cy);
	wglMakeCurrent(m_pDC->m_hDC, NULL);
}

/**********************************************/
/* Property                                   */
/**********************************************/

/* The property of string which is shown */
BSTR CGL3dOcxCtrl::GetContent() 
{
	// TODO: Add your property handler here
	CString strResult = m_Font.GetText();

	return strResult.AllocSysString();
}

void CGL3dOcxCtrl::SetContent(LPCTSTR lpszNewValue) 
{
	// TODO: Add your property handler here
	wglMakeCurrent(m_pDC->m_hDC, m_hRC);
	m_Font.SetText(lpszNewValue);
	m_Font.CreateFont(m_pDC, "Arial Black");
	wglMakeCurrent(m_pDC->m_hDC, NULL);
    Refresh();
}


/**********************************************/
/* Method                                     */
/**********************************************/

/* The property of string which is shown */
void CGL3dOcxCtrl::SetStrText(LPCTSTR strText) 
{
	// TODO: Add your dispatch handler code here
	wglMakeCurrent(m_pDC->m_hDC, m_hRC);
	m_Font.SetText(strText);
	m_Font.CreateFont(m_pDC, "Arial Black");
	wglMakeCurrent(m_pDC->m_hDC, NULL);
    Refresh();
}



void CGL3dOcxCtrl::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
    Refresh();
	
	COleControl::OnLButtonDblClk(nFlags, point);
}

void CGL3dOcxCtrl::OnPaletteChanged(CWnd* pFocusWnd) 
{
	COleControl::OnPaletteChanged(pFocusWnd);
	
	// TODO: Add your message handler code here
    Refresh();

}

BOOL CGL3dOcxCtrl::OnQueryNewPalette() 
{
	// TODO: Add your message handler code here and/or call default
    Refresh();
	
	return COleControl::OnQueryNewPalette();
}

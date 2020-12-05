// 3DFontView.cpp : implementation of the CMy3DFontView class
//

#include "stdafx.h"
#include "3DFont.h"

#include "3DFontDoc.h"
#include "3DFontView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy3DFontView

IMPLEMENT_DYNCREATE(CMy3DFontView, CView)

BEGIN_MESSAGE_MAP(CMy3DFontView, CView)
	//{{AFX_MSG_MAP(CMy3DFontView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_COMMAND(IDM_FONTSOLID, OnFontsolid)
	ON_COMMAND(IDM_FONTWIREFRAME, OnFontwireframe)
	//}}AFX_MSG_MAP
	// Standard printing commands
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy3DFontView construction/destruction

CMy3DFontView::CMy3DFontView()
{
	// TODO: add construction code here
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

}

CMy3DFontView::~CMy3DFontView()
{
}

BOOL CMy3DFontView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMy3DFontView drawing

void CMy3DFontView::OnDraw(CDC* pDC)
{
	CMy3DFontDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
	CPalette* oldPalette;

    //Set logic palette
	oldPalette = m_pDC->SelectPalette(&m_Palette, FALSE);
	m_pDC->RealizePalette();
	
	wglMakeCurrent(m_pDC->GetSafeHdc(), m_hRC);
	DrawGLFont();
	SwapBuffers(m_pDC->GetSafeHdc());
    wglMakeCurrent(m_pDC->GetSafeHdc(), NULL);

	m_pDC->SelectPalette(oldPalette, FALSE);
}

/////////////////////////////////////////////////////////////////////////////
// CMy3DFontView diagnostics

#ifdef _DEBUG
void CMy3DFontView::AssertValid() const
{
	CView::AssertValid();
}

void CMy3DFontView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3DFontDoc* CMy3DFontView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3DFontDoc)));
	return (CMy3DFontDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy3DFontView message handlers

int CMy3DFontView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
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
     
    m_pDC = new CClientDC(this);
	int pixelFormat =
		ChoosePixelFormat(m_pDC->GetSafeHdc(), &pfd);
	BOOL success = 
		SetPixelFormat(m_pDC->GetSafeHdc(), pixelFormat, &pfd);

	DescribePixelFormat(m_pDC->GetSafeHdc(), pixelFormat,
		  sizeof(pfd), &pfd);

	if(pfd.dwFlags & PFD_NEED_PALETTE)
         InitPalette();

	m_hRC = wglCreateContext(m_pDC->GetSafeHdc());

	m_hRC = wglCreateContext(m_pDC->GetSafeHdc());

	
	m_FontX.SetXOffset(-0.4f);
	m_FontX.SetYOffset(-0.4f);
	m_FontX.SetXScale(1.4f);
	m_FontX.SetYScale(1.3f);
	m_FontX.SetZScale(0.8f);
	m_FontX.SetXRotate(-20.0f);
	m_FontX.SetYRotate(-6.0f);
	m_FontX.SetZRotate(90.0f);
	
	m_FontZ.SetXOffset(0.0f);
	m_FontZ.SetXScale(0.5f);
	m_FontZ.SetYScale(2.4f);
	m_FontZ.SetZScale(1.4f);
	m_FontZ.SetXRotate(-30.0f);
	m_FontZ.SetZRotate(1.1f);
	
	m_FontH.SetXOffset(1.2f);
	m_FontH.SetYOffset(1.2f);
	m_FontH.SetXScale(1.4f);
	m_FontH.SetYScale(1.4f);
	m_FontH.SetZScale(0.8f);
	m_FontH.SetZScale(1.4f);
    m_FontH.SetXRotate(-10.0f);
    m_FontH.SetYRotate(-30.0f);
	m_FontH.SetZRotate(-90.0f);


	InitFontColor();

	wglMakeCurrent(m_pDC->m_hDC,m_hRC);
	m_FontX.CreateFont(m_pDC, "Arial Black");
	m_FontZ.CreateFont(m_pDC, "Arial Black");
	m_FontH.CreateFont(m_pDC, "Arial Black");
	m_FontX.SetText("Xing");
	m_FontZ.SetText("Zhao");
	m_FontH.SetText("Hui");

	wglMakeCurrent(NULL,NULL);
	
	return 0;
}

void CMy3DFontView::OnDestroy() 
{
	CView::OnDestroy();
	
	// TODO: Add your message handler code here
	wglDeleteContext(m_hRC);
    m_Palette.DeleteObject();
	ReleaseDC(m_pDC);
}

void CMy3DFontView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
    CClientDC clientDC(this);
	wglMakeCurrent(clientDC.m_hDC, m_hRC);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 2.0, 7.0);
	glViewport(0, 0, cx, cy);
	wglMakeCurrent(NULL, NULL);
}


void CMy3DFontView::InitPalette(void)
{
	PIXELFORMATDESCRIPTOR pfd;  // Pixel Format Descriptor         
	LOGPALETTE *pPal;			// Pointer to memory for logical palette
	int PixelFormat;			// Pixel format index
    int paletteSize;            // Number of entries in palette 
	BYTE RedMask;               // Range for each color entry (7,7,and 3)
	BYTE GreenMask;
	BYTE BlueMask;
    HDC hDC = GetDC()->GetSafeHdc();  //the context device 								

	// Get the pixel format index and retrieve the pixel format description
    PixelFormat = GetPixelFormat(hDC);
    DescribePixelFormat(hDC, PixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd);
    
	
	// Check whether the pixel format and the pixel type
	if (!(pfd.dwFlags & PFD_NEED_PALETTE ||
	  pfd.iPixelType == PFD_TYPE_COLORINDEX))
	    return;

	// Get the number of entries in palette. 256 colors for 8 bits 
    paletteSize = 1 << pfd.cColorBits;
    
	// Allocate for the logical palette
	pPal = (LOGPALETTE*)
	malloc(sizeof(LOGPALETTE) + paletteSize * sizeof(PALETTEENTRY));
    
	
	// Fill the logical palette header information 
	pPal->palVersion = 0x300;            //support Windows3.0
    pPal->palNumEntries = paletteSize;   //number of colors entries

    // Set the 1st entries of logical palette with the current system palette 
    (void) GetSystemPaletteEntries(hDC, 0, paletteSize, &pPal->palPalEntry[0]);

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

	//Free the memory allocated for the logical palette 
    free(pPal);
}


void CMy3DFontView::DrawGLFont(void)
{
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

    glTranslatef(-0.5f, 0.0f, -5.0f);
	
    m_FontX.GLDrawText();
    m_FontZ.GLDrawText();
    m_FontH.GLDrawText();

	glFlush();

}


void CMy3DFontView::InitFontColor()
{
	float fv[4];


	fv[0] = 0.1;
	fv[1] = 0.1;
	fv[2] = 0.1;
	fv[3] = 0.1;
	m_FontX.SetEmission(fv);

	fv[0] = 0.9;
	fv[1] = 0.9;
	fv[2] = 0.9;
	fv[3] = 1.0;
	m_FontX.SetSpecular(fv);

	fv[0] = 0.1;
	fv[1] = 0.1;
	fv[2] = 1.0;
	fv[3] = 1.0;
	m_FontX.SetAmbient(fv);

	fv[0] = 0.1;
	fv[1] = 0.1;
	fv[2] = 0.1;
	fv[3] = 1.0;
	m_FontX.SetDiffuse(fv);

	m_FontX.SetShininess(0.1f);
	
	 
	fv[0] = 0.9;
	fv[1] = 0.1;
	fv[2] = 0.1;
	fv[3] = 1.0;
	m_FontZ.SetEmission(fv);

	fv[0] = 0.9;
	fv[1] = 0.9;
	fv[2] = 0.9;
	fv[3] = 1.0;
	m_FontZ.SetSpecular(fv);

	fv[0] = 1.0;
	fv[1] = 0.1;
	fv[2] = 0.1;
	fv[3] = 1.0;
	m_FontZ.SetAmbient(fv);

	fv[0] = 0.9;
	fv[1] = 0.9;
	fv[2] = 0.9;
	fv[3] = 1.0;
	m_FontZ.SetDiffuse(fv);

	m_FontZ.SetShininess(1.1f);

	fv[0] = 0.1;
	fv[1] = 0.1;
	fv[2] = 0.1;
	fv[3] = 1.0;
	m_FontH.SetEmission(fv);

	fv[0] = 1.0;
	fv[1] = 1.0;
	fv[2] = 1.0;
	fv[3] = 1.0;
	m_FontH.SetSpecular(fv);

	fv[0] = 1.0;
	fv[1] = 1.1;
	fv[2] = 0.5;
	fv[3] = 1.0;
	m_FontH.SetAmbient(fv);

	fv[0] = 0.1;
	fv[1] = 0.1;
	fv[2] = 0.1;
	fv[3] = 0.1;
	m_FontH.SetDiffuse(fv);

	m_FontH.SetShininess(0.1f);

}


void CMy3DFontView::OnFontsolid() 
{
	// TODO: Add your command handler code here
	wglMakeCurrent(m_pDC->m_hDC,m_hRC);
	m_FontX.SetFontType(GL_FONT_SOLID);
	m_FontZ.SetFontType(GL_FONT_SOLID);
	m_FontH.SetFontType(GL_FONT_SOLID);
	
	m_FontX.CreateFont(m_pDC, "Arial Black");
	m_FontZ.CreateFont(m_pDC, "Arial Black");
	m_FontH.CreateFont(m_pDC, "Arial Black");
	wglMakeCurrent(NULL,NULL);
	
	Invalidate(FALSE);
}

void CMy3DFontView::OnFontwireframe() 
{
	// TODO: Add your command handler code here
	wglMakeCurrent(m_pDC->m_hDC,m_hRC);
	m_FontX.SetFontType(GL_FONT_LINE);
	m_FontZ.SetFontType(GL_FONT_LINE);
	m_FontH.SetFontType(GL_FONT_LINE);
	
	m_FontX.CreateFont(m_pDC, "Arial Black");
	m_FontZ.CreateFont(m_pDC, "Arial Black");
	m_FontH.CreateFont(m_pDC, "Arial Black");
	wglMakeCurrent(NULL,NULL);
	
	Invalidate(FALSE);
	
}


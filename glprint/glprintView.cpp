// glprintView.cpp : implementation of the CGlprintView class
//
#include "stdafx.h"
#include "glprint.h"

#include "glprintDoc.h"
#include "glprintView.h"
//#include <gl\glaux.h>
#include "glaux.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGlprintView

IMPLEMENT_DYNCREATE(CGlprintView, CView)

BEGIN_MESSAGE_MAP(CGlprintView, CView)
	//{{AFX_MSG_MAP(CGlprintView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGlprintView construction/destruction

CGlprintView::CGlprintView()
{
	// TODO: add construction code here

}

CGlprintView::~CGlprintView()
{
}

BOOL CGlprintView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGlprintView drawing
void CGlprintView::OnDraw(CDC* pDC)
{
	CGlprintDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
	//if print
	if(pDC->IsPrinting())
	{
		 //draw the image in memory DC to print DC 
		 CRect      drawRect;
		 int        cx, cy;
		 COLORREF	clrOld = pDC->SetTextColor(RGB(250, 10, 10));
		 pDC->TextOut(450,10, "This is a demo of OpenGL print provided by Zhaohui Xing");
		 pDC->SetTextColor(RGB(128, 128, 255));
		 pDC->TextOut(40,80, "Large Size");
		 drawRect.SetRect(40, 160, 2440, 1960);
         pDC->DPtoLP(&drawRect);
		 m_MemImageDC.CopyDataToDC(pDC, drawRect);
		 pDC->TextOut(40,1960, "Medium Size");
		 drawRect.SetRect(500, 2040, 2100, 3240);
         pDC->DPtoLP(&drawRect);
		 m_MemImageDC.CopyDataToDC(pDC, drawRect);
		 pDC->TextOut(40,3260, "Orignal Size");
		 m_MemImageDC.GetMemorySize(&cx, &cy);
		 drawRect.SetRect(1000, 3400, 1000 + cx , 3400 + cy);
         pDC->DPtoLP(&drawRect);
		 m_MemImageDC.CopyDataToDC(pDC, drawRect);
		 pDC->SetTextColor(clrOld);
	}
	else //draw opnGL in current DC
	{
	     CPalette* oldPalette;

         //Set logic palette
	     oldPalette = m_pDC->SelectPalette(&m_Palette, FALSE);
	     m_pDC->RealizePalette();
	
		 //draw openGL object
	     wglMakeCurrent(m_pDC->GetSafeHdc(), m_hRC);
	     DrawObject();
	     SwapBuffers(m_pDC->GetSafeHdc());
         wglMakeCurrent(m_pDC->GetSafeHdc(), NULL);
		 
	    //Prepare the memory DC 
		 CRect rect;
		 GetClientRect(&rect);
	     m_MemImageDC.SetMemorySize(rect.Width(), rect.Height());
		 //copy the image data in current DC to memory
		 m_MemImageDC.CopyDataFromDC(m_pDC, rect);

	     m_pDC->SelectPalette(oldPalette, FALSE);
	}	     
}

/////////////////////////////////////////////////////////////////////////////
// CGlprintView printing

BOOL CGlprintView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGlprintView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGlprintView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGlprintView diagnostics

#ifdef _DEBUG
void CGlprintView::AssertValid() const
{
	CView::AssertValid();
}

void CGlprintView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGlprintDoc* CGlprintView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGlprintDoc)));
	return (CGlprintDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGlprintView message handlers

/********************************************************************/
/* Set up the OpenGL display environment                 		    */
/********************************************************************/
int CGlprintView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
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
         SetPalette();

	m_hRC = wglCreateContext(m_pDC->GetSafeHdc());
	wglMakeCurrent(m_pDC->m_hDC,m_hRC);

	Initialize();

	wglMakeCurrent(NULL,NULL);

	return 0;
}

/********************************************************************/
/* Celan all memory allocated to OpenGL resource           		    */
/********************************************************************/
void CGlprintView::OnDestroy() 
{
	CView::OnDestroy();
	
	// TODO: Add your message handler code here
	wglDeleteContext(m_hRC);
    m_Palette.DeleteObject();
	ReleaseDC(m_pDC);
}


/********************************************************************/
/* If the window size change, adjust the view point for the correct	*/
/* OpenGL diplay                                                    */
/********************************************************************/
void CGlprintView::OnSize(UINT nType, int cx, int cy) 
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


/********************************************************************/
/* Set up the palette for OpenGL display DC                        	*/
/********************************************************************/
void CGlprintView::SetPalette(void)
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


/********************************************************************/
/* Initialize the light setting                                  	*/
/********************************************************************/
void CGlprintView::Initialize(void)
{
	float fv[4];
	
	fv[0] = 0.3f;
	fv[1] = 0.3f;
	fv[2] = 0.3f;
	fv[3] = 1.0f;
	glLightfv(GL_LIGHT0, GL_AMBIENT, fv);//set light ambient
	

	fv[0] = 0.1f;
	fv[1] = 0.1f;
	fv[2] = 0.1f;
	fv[3] = 1.0f;
	glLightfv(GL_LIGHT0, GL_DIFFUSE, fv);//set light specular

	fv[0] = 0.3f;
	fv[1] = 0.3f;
	fv[2] = 0.1f;
	fv[3] = 1.0f;
	glLightfv(GL_LIGHT0, GL_SPECULAR, fv);//set light specular
	
	fv[0] = 100.0f;
	fv[1] = 0.0f;
	fv[2] = 0.0f;
	fv[3] = 0.0f;
	glLightfv(GL_LIGHT0, GL_POSITION, fv);//set light position

	glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}


/********************************************************************/
/* Display the OpenGL object                                     	*/
/********************************************************************/
void CGlprintView::DrawObject(void)
{
	float fv[4];
	float shine;

	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	
	//clear color buffer
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	glPushMatrix();

	shine = 0.3f;
	glMaterialf(GL_FRONT, GL_SHININESS, shine);//set specular

	fv[0] = 0.4f;
	fv[1] = 0.4f;
	fv[2] = 0.4f;
	fv[3] = 0.1f;
	glMaterialfv(GL_FRONT, GL_SPECULAR, fv);//set specular
	glMaterialfv(GL_FRONT, GL_EMISSION, fv);//set specular
	
//draw the wireframe sphere	
	fv[0] = 0.0f;
	fv[1] = 0.0f;
	fv[2] = 0.4f;
	fv[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, fv);//set material
	glTranslatef(0.0f, 0.0f, -6.0f);
    glRotated(45, 1.0, 0.0, 0.0);     
    glRotated(-30, 0.0, 1.0, 0.0);     
    glRotated(60, 0.0, 0.0, 1.0);     
    auxWireSphere(1.0);

//draw the solid cylinder	
	fv[0] = 0.1f;
	fv[1] = 0.4f;
	fv[2] = 0.1f;
	fv[3] = 10.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, fv);//set material
	glTranslatef(0.0f, 0.5f, 0.0f);
	auxSolidCylinder(0.1, 3.0);
	glTranslatef(0.0f, -0.5f, 0.0f);

//draw the solid arrow	
	fv[0] = 0.9f;
	fv[1] = 0.1f;
	fv[2] = 0.1f;
	fv[3] = 10.2f;
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, fv);//set material
	glTranslatef(0.0f, 1.5f, 0.0f);
    glRotated(-90, 1.0, 0.0, 0.0);     
    auxSolidCone(0.4, 0.8);
    glRotated(90, 1.0, 0.0, 0.0);     
	glTranslatef(0.0f, -1.5f, 0.0f);

    glRotated(-60, 0.0, 0.0, 1.0);     
    glRotated(30, 0.0, 1.0, 0.0);     
    glRotated(-45, 1.0, 0.0, 0.0);     
	glTranslatef(0.0f, 0.0f, 6.0f);
   
	glPopMatrix();

	glFlush();

}


/********************************************************************/
/* Save current OpenGL image to DIB file                                     	*/
/********************************************************************/
void CGlprintView::OnFileSave() 
{
	// TODO: Add your command handler code here
	//Set up file dialog setting
	char FileString[] = "DIB File(*.bmp)\0*.bmp\0\0";

	CFileDialog dlg(FALSE,NULL,NULL,OFN_CREATEPROMPT|OFN_OVERWRITEPROMPT,NULL,NULL);
	dlg.m_ofn.lpstrFilter = (LPSTR)FileString;
    dlg.m_ofn.lpstrTitle = "Save DIB File";
	if(dlg.DoModal()==IDOK)
	{
		//Get file name
		CString filename = dlg.GetFileTitle();
		filename += ".";
		CString fileext;
		fileext = dlg.GetFileExt(); 
		if(fileext.IsEmpty())
			filename += "bmp";
		else
			filename += fileext;
		
		//Write image data to disk file
		CFile file;
		CFileException fileexc;
		file.Open(filename,CFile::modeCreate|CFile::modeWrite,&fileexc);
		m_MemImageDC.WriteDataToDIBfile(&file);			
		file.Close();
	}
	
}

/********************************************************************/
/* Save current OpenGL image to DIB file                                     	*/
/********************************************************************/
void CGlprintView::OnFileSaveAs() 
{
	// TODO: Add your command handler code here
	OnFileSave();
}

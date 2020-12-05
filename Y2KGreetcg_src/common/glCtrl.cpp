/**********************************************************/
/*   The glCtrl.cpp                                          
/*                                                         
/*   Created by Xing Zhaohui (xingzhh@yahoo.com),          
/*   Dec 10, 1999                                           
/*                                                        
/*   Implement the basic OpenGL control which contain        
/*   the different OpenGL objects to render in various     
/*   applications                                         
/* 
/**********************************************************/

#include "stdafx.h"
#include "glCtrl.h"
#include "glConstant.h"
#include "resource.h"

#define M_IBALL   20
#define M_2IBALL  40
#define M_DBALL   20.0
#define M_2DBALL  40.0
#define M_TBALL   0.025
 
#define M_RWORD   6.28318


/**********************************************************/
/*   Construction                                         
/**********************************************************/
CGLControl::CGLControl()
{
	m_bHasTimer = FALSE;
	m_iElapse = 100;
	m_bHasFog = TRUE;
    SetPaletteFunc(&SetupPalette);
	m_fFogColors[0] = 0.9f;
    m_fFogColors[1] = 0.9f;
    m_fFogColors[2] = 0.9f;
    m_fFogColors[3] = 0.9f;
	m_fFogDensity = 0.1f;
	m_Palette.DeleteObject();
	m_iBallCount = 0;

	m_iWordCount = 0;  
	m_dWordStep = 1.0;   

	m_dMIDILength = 0;
	m_bMusicOn = FALSE;

	m_bJustWord = FALSE;

}


/**********************************************************/
/*   Destruction                                           
/**********************************************************/
CGLControl::~CGLControl()
{
}


BEGIN_MESSAGE_MAP(CGLControl, CWnd)
	//{{AFX_MSG_MAP(CGLControl)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_PALETTECHANGED()
	ON_WM_QUERYNEWPALETTE()
	ON_WM_TIMER()
	ON_WM_SIZE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/**********************************************************/
/*   Set the function to create palette                    
/**********************************************************/
void CGLControl::SetPaletteFunc(
			void (*PaletteFunc)(CDC* pDC, CPalette& Palette))
{
    SetPalette = *PaletteFunc;
}


/**********************************************************/
/*   Has fog or not
/**********************************************************/
void CGLControl::SetFogStatus(BOOL bFog)
{
	m_bHasFog = bFog;
}


/**********************************************************/
/*   Set fog colors
/**********************************************************/
void CGLControl::SetFogColors(float fRed, float fGreen, 
							  float fBlue, float fAlpha,
							  float fDensity)
{
	m_fFogColors[0] = fRed;
    m_fFogColors[1] = fGreen;
    m_fFogColors[2] = fBlue;
    m_fFogColors[3] = fAlpha;
	m_fFogDensity = fDensity;
}


/**********************************************************/
/*   Set up the light setting for rendering system                    
/**********************************************************/
void CGLControl::SetupLights(void)
{
    float fv4[4];
    
   
    fv4[0] = 0.9f;
    fv4[1] = 0.9f;
    fv4[2] = 0.9f;
    fv4[3] = 10.0f;
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, fv4);

    fv4[0] = 0.9f;
    fv4[1] = 0.9f;
    fv4[2] = 0.9f;
    fv4[3] = 0.9f;
    glLightfv(GL_LIGHT0, GL_AMBIENT, fv4);

    fv4[0] = 200.0f;
    fv4[1] = -60.0f;
    fv4[2] = 60.0f;
    fv4[3] = 10.0f;
    glLightfv(GL_LIGHT0, GL_POSITION, fv4);
    
    fv4[0] = 2.9f;
    fv4[1] = 2.9f;
    fv4[2] = 2.9f;
    fv4[3] = 30.01f;
    glLightfv(GL_LIGHT0, GL_DIFFUSE, fv4);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    
    glEnable(GL_DEPTH_TEST);
	
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
}


/**********************************************************/
/*   Render the OpenGL objects                                   
/**********************************************************/
void CGLControl::DrawObjects(void)
{

	
	if(m_bJustWord)
	{
		m_Word.Render();
	}
	else
	{
	   m_Ball.Render();
	   m_Word.Render();
       m_Cube.Render();
	   m_Dot.Render();
	}
}


/**********************************************************/
/*   Build the OpenGL objects data 
/**********************************************************/
void CGLControl::SetupObjects(void)
{
	if(m_bJustWord)
	{
	    //Set the setting of the word
	    //set the size of texture
	    m_Word.SetTextureSize(2, 8);
	    //set the texture efficiency of the font
	    m_Word.SetTexEfficiency(e_TBall1, 7);
	    //Set the texture function
	    m_Word.SetTextureFunc(&SetChecker);
	    //set the font type 
        m_Word.SetFontType(GL_FONT_SOLID);
	    //set the string of font 
	    m_Word.SetFontText("Happy Y2K");
        //set transform
	    m_Word.SetTranslation(-0.9, 0.0, -4.0);
	    //set scale
	    m_Word.SetScale(0.6, 1.0, 1.6);
	    //set rotation
	    m_Word.SetRotate(0.0, 0.0, 0.0);
	    //build texture
	    m_Word.BuildTexture();
	    //build font
	    m_Word.BuildFont(m_pDC, "Courier");
	}
	else
	{
	
	    //Set the setting of the first ball
	    //set the grid of rendering
	    m_Ball.SetSize(M_IBALL, M_IBALL);  
	    //set the size of texture
	    //set the efficiency of the first ball
        m_Ball.SetEfficiency(e_dBall1, 3);
        //set transform
	    m_Ball.SetTranslation(-0.8, 0.0, -4.0);
	    //set scale
	    m_Ball.SetScale(0.3, 1.0, 0.3);
	    //set rotation
	    m_Ball.SetRotate(10.0, 0.0, 0.0);
        //build texture
	    m_Ball.BuildBMPTexture(IDB_LFACE);
        //build vertex
	    m_Ball.BuildVertex();
	    //set the texture grids of the first ball
        m_Ball.SetTexCoord(0.0, 0.0, M_DBALL, M_2DBALL);

	    //Set the setting of the word
	    //set the size of texture
	    m_Word.SetTextureSize(4, 4);
	    //set the texture efficiency of the font
	    m_Word.SetTexEfficiency(e_TBall2, 7);
	    //Set the texture function
	    m_Word.SetTextureFunc(&SetChecker);
	    //set the font type 
        m_Word.SetFontType(GL_FONT_SOLID);
	    //set the string of font 
	    m_Word.SetFontText("Happy Y2K");
        //set transform
	    m_Word.SetTranslation(-1.3, 1.45, -4.5);
	    //set scale
	    m_Word.SetScale(0.6, 0.8, 2.4);
	    //set rotation
	    m_Word.SetRotate(0.0, 0.0, 0.0);
	    //build texture
	    m_Word.BuildTexture();
	    //build font
	    m_Word.BuildFont(m_pDC, "Courier");

	    //Set the setting of the cube
        //set length
	    m_Cube.SetLength(0.35);
        //set transform
	    m_Cube.SetTranslation(1.0, 0.0, -4.0);
	    //set scale
	    m_Cube.SetScale(1.0, 1.0, 1.0);
	    //set rotation
	    m_Cube.SetRotate(-10.0, -10.0, 0.0);
        //build texture
	    m_Cube.BuildBMPTexture(IDB_SFACE);
        //build vertex
	    m_Cube.BuildVertex();
	    
		//Set the setting of the dot cube
        //set length
	    m_Dot.SetLength(0.20);
        //set transform
	    m_Dot.SetTranslation(0.0, -0.7, -5.0);
	    //set scale
	    m_Dot.SetScale(1.0, 1.0, 1.0);
	    //set rotation
	    m_Dot.SetRotate(-10.0, -10.0, 10.0);
        //build texture
	    m_Dot.BuildBMPTexture(IDB_DOT);
        //build vertex
	    m_Dot.BuildVertex();
	}    

}


/**********************************************************/
/*   Set the MIDI temprary name
/**********************************************************/
void CGLControl::SetMidiName(char* MidiName)
{
	m_MIDIPlayer.SetResName(MidiName);
}


/**********************************************************/
/*   Set MIDI player ON or OFF
/**********************************************************/
void CGLControl::SetPlayOn(BOOL bMusicOn)
{
	m_bMusicOn = bMusicOn;
}


/**********************************************************/
/*   Start or Stop play msuic
/**********************************************************/
void CGLControl::PlayMusic(BOOL bFlag)
{
	if((!m_bMusicOn) && (bFlag))
	{
	    //Set up music and play it
	    m_MIDIPlayer.LoadMIDIFile(IDM_MUSIC);
	    m_dMIDILength = m_MIDIPlayer.GetLength();
	    ASSERT(m_dMIDILength > 0);
	    m_MIDIPlayer.Play();
	}
	if((m_bMusicOn) && (!bFlag))
	{
	    m_MIDIPlayer.Close();
	    m_MIDIPlayer.MoveMIDIFile();
	}

	m_bMusicOn = bFlag;
}

/**********************************************************/
/*   Create the control                                   
/**********************************************************/
BOOL CGLControl::Create(DWORD dwExStyle, 
			DWORD dwStyle, const RECT& rect, 
			CWnd* pParentWnd, UINT nID, 
			CCreateContext* pContext)
{
	// TODO: Add your specialized code here and/or call the base class
    // Register a class with no cursor
	LPCTSTR lpszClassName = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW,
			::LoadCursor(AfxGetResourceHandle(), 
			MAKEINTRESOURCE(IDC_NULLCURSOR)));
	
	//Create window handle
	return CreateEx(dwExStyle, lpszClassName, _T(""), dwStyle, 
		rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, 
		pParentWnd->GetSafeHwnd(), NULL, NULL );
}


/**********************************************************/
/*   When created, initialize every thing                  
/**********************************************************/
int CGLControl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
    //Set up the pixel format descriptor

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
     
	//Get the Device context
	m_pDC = GetDC();			
	
	//Chose the pixel format of current device context
	int pixelFormat =
		ChoosePixelFormat(m_pDC->GetSafeHdc(), &pfd);
	
	//Set pixel fromat
	BOOL success = 
		SetPixelFormat(m_pDC->GetSafeHdc(), pixelFormat, &pfd);

	DescribePixelFormat(m_pDC->GetSafeHdc(), pixelFormat,
		  sizeof(pfd), &pfd);

	//Build the palette for the display device context 
	if(pfd.dwFlags & PFD_NEED_PALETTE)
 	    SetPalette(m_pDC, m_Palette);
	
	//Create the OpenGL rendering device context
	m_hRC = wglCreateContext(m_pDC->GetSafeHdc());

	//Set HGLRC to display device context for setting up 
	//lightting evironment
    wglMakeCurrent(m_pDC->GetSafeHdc(), m_hRC); 
	
	//Set up light setting
	SetupLights();

	//Build the objects
    SetupObjects();

	Invalidate(FALSE);

	SetTimer(1, m_iElapse, NULL);

    m_MIDIPlayer.SetDeviceType("sequencer");
	if(m_bMusicOn)
	{
	    //Set up music and play it
	    m_MIDIPlayer.LoadMIDIFile(IDM_MUSIC);
	    m_dMIDILength = m_MIDIPlayer.GetLength();
	    ASSERT(m_dMIDILength > 0);
	    m_MIDIPlayer.Play();
	}

	m_bHasTimer = TRUE;

	return 0;
}


/**********************************************************/
/*   Render the 3D objects                                 
/**********************************************************/
void CGLControl::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
 
	//Set palette
	if(m_Palette.GetSafeHandle() != NULL)
    {
		m_pDC->SelectPalette(&m_Palette, FALSE);
		m_pDC->RealizePalette();
    }
	
	wglMakeCurrent(m_pDC->GetSafeHdc(), m_hRC);
    
	//Set fog proterty
	if(m_bHasFog)
	{
		glFogi(GL_FOG_MODE, GL_EXP2);
        glFogf(GL_FOG_DENSITY, m_fFogDensity);
        glFogfv(GL_FOG_COLOR, m_fFogColors);
	    glClearColor(m_fFogColors[0], m_fFogColors[1], 
			         m_fFogColors[2], m_fFogColors[3]);
	    glEnable(GL_FOG);
	}
	else
	{
	    glClearColor(0.2F, 0.2F, 0.2F, 1.0F);
	    glDisable(GL_FOG);
	}
    

	//render 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
	
	DrawObjects();	
	glFlush();
	SwapBuffers(m_pDC->GetSafeHdc());
	
	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_FOG);
    glMatrixMode(GL_MODELVIEW);

    
	wglMakeCurrent(m_pDC->GetSafeHdc(), NULL); 
	// Do not call CWnd::OnPaint() for painting messages
}


/**********************************************************/
/*   If the palette was changed, repaint
/**********************************************************/
void CGLControl::OnPaletteChanged(CWnd* pFocusWnd)
{
	CWnd::OnPaletteChanged(pFocusWnd);
	
	// TODO: Add your message handler code here
	Invalidate(FALSE); 
}


/**********************************************************/
/*   If the palette was changed, repaint                      
/**********************************************************/
BOOL CGLControl::OnQueryNewPalette()
{
	// TODO: Add your message handler code here and/or call default
	Invalidate(FALSE); 
	
	return CWnd::OnQueryNewPalette();
}


/**********************************************************/
/*   The timer event                                   
/**********************************************************/
void CGLControl::OnTimer(UINT nIDEvent)
{
	if(m_bJustWord)
	{
        Invalidate(FALSE); 
		return;
	}
	
	//Timer event for 3D objects' animation
    double dBallTexStep;
    double sBX, sBY, sBZ;
    double rWX, rWY, rWZ;
    double rCX, rCY, rCZ;

  
	//Animate the ball
    dBallTexStep = ((double)m_iBallCount)*M_TBALL;
    m_Ball.SetTexCoord(0.0, dBallTexStep, M_DBALL, M_2DBALL);
    m_iBallCount++;
    m_iBallCount = m_iBallCount % (M_2IBALL);
    m_Ball.GetScale(&sBX, &sBY, &sBZ);
    if(m_iBallCount < M_IBALL)
	{
	    sBX += 0.025;
	    if(sBX > 1.3)
           sBX = 1.3; 
	    
		sBZ += 0.025;
        if(sBZ > 1.3)
           sBZ = 1.3;  
	}
    else
	{
	    sBX -= 0.025;
	    if(sBX < 0.3)
           sBX = 0.3;
	    
		sBZ -= 0.025;
		if(sBZ < 0.3)
		   sBZ = 0.3;
	}
	m_Ball.SetScale(sBX, 1.0, sBZ);

    //Animate the word
	m_iWordCount++;
	m_iWordCount = m_iWordCount%10;
	if(m_iWordCount == 0)
	{
	   if(m_dWordStep > 0.0)
	      m_dWordStep = -1.0;   
	   else
          m_dWordStep = 1.0;   
	}
	m_Word.GetRotate(&rWX, &rWY, &rWZ);
    rWY += m_dWordStep*M_RWORD;
	m_Word.SetRotate(0.0, rWY, 0.0);
    
	
	//Animate the cube
    m_Cube.GetRotate(&rCX, &rCY, &rCZ);
    rCX -= 16.0; 
	rCY -= 18.0;
	rCZ -= 13.0;
    
	if(rCX < -3600.0)
	   rCX = 0.0;
	if(rCY < -3600.0)
       rCY = 0.0; 
	if(rCZ < -3600.0)
       rCZ = 0.0; 
	m_Cube.SetRotate(rCX, rCY, rCZ);

	//Animate the dot cube
    m_Dot.GetRotate(&rCX, &rCY, &rCZ);
    rCX += 30.0; 
	rCY += 20.0;
	rCZ += 10.0;
    
	if(rCX > 3600.0)
	   rCX = 0.0;
	if(rCY > 3600.0)
       rCY = 0.0; 
	if(rCZ > 3600.0)
       rCZ = 0.0; 
	m_Dot.SetRotate(rCX, rCY, rCZ);


	Invalidate(FALSE); 
    
	//time event for music
	if(m_bMusicOn)
	{
       DWORD pos = m_MIDIPlayer.GetPosition();
       if(pos >= m_dMIDILength) //if play is over, play again
           m_MIDIPlayer.Play();
	}
}


/**********************************************************/
/*   If the window's size was changed                          
/**********************************************************/
void CGLControl::OnSize(UINT nType, int cx, int cy)
{
	CRect rect;

    CPaintDC dc(this);

	//Set HGLRC to window's display device context
	wglMakeCurrent(dc.m_hDC, m_hRC);

	//Set rendering mode
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	//Set view point of the rendering system
	glFrustum(-1.0, 1.0, -1.0, 1.0, 2.0, 7.0);
	glViewport(0, 0, cx, cy);
	glDrawBuffer(GL_BACK);
	
	wglMakeCurrent(NULL, NULL);
}


/**********************************************************/
/*   If the window was destroyed                            
/**********************************************************/
void CGLControl::OnDestroy()
{
	// TODO: Add your message handler code here
	//Destroy the OpenGL rendering device context
	wglDeleteContext(m_hRC);
	
	//Destroy palette
	if(m_Palette.GetSafeHandle() != NULL)
       m_Palette.DeleteObject();
	
	//Release the window's display device context
	ReleaseDC(m_pDC);

	if(m_bMusicOn)
	{
	   m_MIDIPlayer.Close();
	   m_MIDIPlayer.MoveMIDIFile();
	}

	//Kill the timer event
    if(m_bHasTimer)
	{
	   KillTimer(1);
	}
	
	CWnd::OnDestroy();
}



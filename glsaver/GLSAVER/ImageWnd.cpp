// ImageWnd.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "ImageWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImageWnd

CImageWnd::CImageWnd()
{
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

	FuncPalette = &SetupPalette;

	m_bHasTimer = FALSE;

	m_iElapse = 1;

	m_bBallUp = FALSE;

	InitEverything();

}

CImageWnd::~CImageWnd()
{
	//delete the pointer of the CSG in array
	for(int i = 0; i < m_pCSGArray.GetSize(); i++)
        delete m_pCSGArray[i];
	
	//clean the array buffer
	m_pCSGArray.RemoveAll();   
	m_pCSGArray.FreeExtra();   
}


BEGIN_MESSAGE_MAP(CImageWnd, CWnd)
	//{{AFX_MSG_MAP(CImageWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_PALETTECHANGED()
	ON_WM_QUERYNEWPALETTE()
	ON_WM_TIMER()
	ON_WM_SIZE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CImageWnd message handlers
void CImageWnd::InitEverything(void)
{
	m_fBallA = 0.2f;     
	m_fBallB = 0.2f;    
	m_fBallC = 0.2f;    

    m_fBallX = 0.0f;    
    m_fBallY = 1.85f;    
    m_fBallZ = -5.0f;    

    m_fBallSX = 0.5f;    
    m_fBallSY = 2.5f;    
    m_fBallSZ = 0.5f;    
    
    m_fBallRX = 20.0f;    
    m_fBallRY = 0.0f;    
    m_fBallRZ = 0.0f;    

	m_fWaveA = 1.0f;    
	m_fWaveB = 8.0f;    
	m_fWaveC = 1.5707963268f;    

    m_fWaveX = 0.0f;     
    m_fWaveY = 0.0f;     
    m_fWaveZ = -5.0f;     

    m_fWaveSX = 1.0f;    
    m_fWaveSY = 1.0f;    
    m_fWaveSZ = 1.0f;    
    
    m_fWaveRX = 40.0f;    
    m_fWaveRY = 20.0f;    
    m_fWaveRZ = 0.0f;    

	m_pCSGArray.RemoveAll();   

	//create the ball object
	CSGObject* objball = new CSGObject();
    objball->SetType(TYPE_BALL);
	objball->SetEfficiency(m_fBallA, m_fBallB, m_fBallC);
    objball->SetTranslate(m_fBallX, m_fBallY, m_fBallZ);
    objball->SetScale(m_fBallSX, m_fBallSY, m_fBallSZ);
	m_pCSGArray.Add(objball);

	//create the wave object
	CSGObject* objwave = new CSGObject();
    objwave->SetType(TYPE_WAVE);
    objwave->SetTranslate(m_fWaveX, m_fWaveY, m_fWaveZ);
    objwave->SetScale(m_fWaveSX, m_fWaveSY, m_fWaveSZ);
    objwave->SetRotation(m_fWaveRX, m_fWaveRY, m_fWaveRZ);
    m_pCSGArray.Add(objwave);
}


void CImageWnd::Initialize(void)
{
    float fv4[4];
    int iv1[1];
    
   
    fv4[0] = 0.02f;
    fv4[1] = 0.02f;
    fv4[2] = 0.02f;
    fv4[3] = 10.0f;
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, fv4);

    fv4[0] = 0.2f;
    fv4[1] = 0.2f;
    fv4[2] = 0.2f;
    fv4[3] = 0.1f;
    glLightfv(GL_LIGHT0, GL_AMBIENT, fv4);

    fv4[0] = 120.0f;
    fv4[1] = 90.0f;
    fv4[2] = 110.0f;
    fv4[3] = 30.0f;
    glLightfv(GL_LIGHT0, GL_POSITION, fv4);
    
    fv4[0] = 0.9f;
    fv4[1] = 0.9f;
    fv4[2] = 2.9f;
    fv4[3] = 3000.01f;
    glLightfv(GL_LIGHT0, GL_DIFFUSE, fv4);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);

    
    fv4[0] = 0.6f;
    fv4[1] = 0.6f;
    fv4[2] = 0.6f;
    fv4[3] = 1.0f;
    glMaterialfv(GL_FRONT, GL_SPECULAR, fv4);
    iv1[0] = 40;
    glMaterialiv(GL_FRONT, GL_SHININESS, iv1);

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


void CImageWnd::SetSaverSetting(SAVERSETTING* setting)
{
	//set configration
    memcpy(&m_sSetting, setting, sizeof(SAVERSETTING));
}


void CImageWnd::SetupCSGData(void)
{
	BYTE  chkx, chky;
    float dv;

	//set timer
	if(!m_bHasTimer)
	{
		m_iElapse = m_sSetting.m_iSpeed;
		SetTimer(1, m_iElapse, NULL);
        m_bHasTimer = TRUE;
	}
	else
	{
		if(m_iElapse != m_sSetting.m_iSpeed)
        {
			KillTimer(1);
            m_iElapse = m_sSetting.m_iSpeed;
			SetTimer(1, m_iElapse, NULL);
		}
	}


	//set the object setting
	for(int i = 0; i < m_pCSGArray.GetSize(); i++)
	{
		//if the object is sphere
		if(m_pCSGArray[i]->GetType() == TYPE_BALL)
		{
			//if the saver showing object is ball or ball & wave
			if(m_sSetting.m_enmType == CSG_BALL ||
               m_sSetting.m_enmType == CSG_BOTH)
			{
				//set the sphere equation
				m_pCSGArray[i]->SetVertexFunc(&CreateSpere);
                
				//set the function for calculating the index of vertexs					
				m_pCSGArray[i]->SetIndiceFunc(&SetIndices);
				
				//set the number of grid to render
				m_pCSGArray[i]->SetSize(m_sSetting.m_iGridNumber,
					                    m_sSetting.m_iGridNumber);

				//set drawing state 
                m_pCSGArray[i]->SetDrawState(m_sSetting.m_bBallLine);

				//set the efficiencies of sphere equation
	            m_pCSGArray[i]->SetEfficiency(m_fBallA, m_fBallB, m_fBallC);
                
				//set the translate 
				m_pCSGArray[i]->SetTranslate(m_fBallX, m_fBallY, m_fBallZ);
                
				//set rotation
				m_pCSGArray[i]->SetRotation(m_fBallRX, m_fBallRY, m_fBallRZ);
				
				//set scale 
				if(m_sSetting.m_enmType == CSG_BALL)
				{
					if(m_sSetting.m_enmBallSize == BALL_SMALL)
                       m_pCSGArray[i]->SetScale(m_fBallSX, m_fBallSY, m_fBallSZ);
					else if(m_sSetting.m_enmBallSize == BALL_MEDIUM)
                       m_pCSGArray[i]->SetScale(2.5f*m_fBallSX, 
					                            2.5f*m_fBallSY, 
												2.5f*m_fBallSZ);
					else if(m_sSetting.m_enmBallSize == BALL_LARGE)
                       m_pCSGArray[i]->SetScale(4.0f*m_fBallSX, 
					                            4.0f*m_fBallSY, 
												4.0f*m_fBallSZ);
				}
				else if(m_sSetting.m_enmType == CSG_BOTH)
				{
                    m_pCSGArray[i]->SetScale(1.0f*m_fBallSX, 
						                     1.0f*m_fBallSY, 
											 1.0f*m_fBallSZ);
				}

                //set texture type and texture color
				if(m_sSetting.m_enmTextureB == TEX_SINGLE)
				    m_pCSGArray[i]->SetTextureFunc(&SingleColor);
                else if(m_sSetting.m_enmTextureB == TEX_CHECKER)
                    m_pCSGArray[i]->SetTextureFunc(&CheckerTexture);
				else if(m_sSetting.m_enmTextureB == TEX_NOISE)
                    m_pCSGArray[i]->SetTextureFunc(&NoiseTexture);
                m_pCSGArray[i]->SetAlpha(m_sSetting.m_btTexAlpha);
                
				chkx = (int)(pow(2.0,(double)m_sSetting.m_iTexChkSizeX));
				chky = (int)(pow(2.0,(double)m_sSetting.m_iTexChkSizeY));

				m_pCSGArray[i]->SetTexSize(chkx, chky);
                m_pCSGArray[i]->SetTexFactor(m_sSetting.m_btTexMasterRed*1.0f,
                                             m_sSetting.m_btTexMasterGreen*1.0f,
											 m_sSetting.m_btTexMasterBlue*1.0f);

                m_pCSGArray[i]->SetTexDiscrete(m_sSetting.m_btTexSecondRed*1.0f,
                                               m_sSetting.m_btTexSecondGreen*1.0f,
											   m_sSetting.m_btTexSecondBlue*1.0f);
                
			}
		}
		//if the object is wave
		if(m_pCSGArray[i]->GetType() == TYPE_WAVE)
		{
			//if the saver showing object is wave or wave & wave
			if(m_sSetting.m_enmType == CSG_WAVE ||
               m_sSetting.m_enmType == CSG_BOTH)
			{
				//set the the wave type and equation
				if(m_sSetting.m_enmWaveType == WAVE_RECTANGLE)
				{
				   m_pCSGArray[i]->SetVertexFunc(&CreateWaveSquare);
				   dv = WAVEUNITT/m_sSetting.m_iGridNumber;
				   
				   //set the number of grid to render
				   m_pCSGArray[i]->SetSize(m_sSetting.m_iGridNumber*2,
					                    m_sSetting.m_iGridNumber*2);
				   m_pCSGArray[i]->SetEfficiency(m_fWaveA*2.0f, m_fWaveB, m_fWaveC);

				}
				else if(m_sSetting.m_enmWaveType == WAVE_ROUND)
				{
				   m_pCSGArray[i]->SetVertexFunc(&CreateWaveRound);
                   dv = WAVEUNITR/m_sSetting.m_iGridNumber;
				   //set the number of grid to render
				   m_pCSGArray[i]->SetSize(m_sSetting.m_iGridNumber,
					                    m_sSetting.m_iGridNumber);
				   m_pCSGArray[i]->SetEfficiency(m_fWaveA, m_fWaveB, m_fWaveC);
				}
			    m_pCSGArray[i]->SetDiscrete(dv, dv, dv); 

				//set the function for calculating the index of vertexs					
				m_pCSGArray[i]->SetIndiceFunc(&SetIndices);
				

                //set drawing state 
                m_pCSGArray[i]->SetDrawState(m_sSetting.m_bWaveLine);

				//set the efficiencies of wave equation
	            m_pCSGArray[i]->SetEfficiency(m_fWaveA, m_fWaveB, m_fWaveC);
                
				//set the translate 
				m_pCSGArray[i]->SetTranslate(m_fWaveX, m_fWaveY, m_fWaveZ);
                
				//set rotation
				m_pCSGArray[i]->SetRotation(m_fWaveRX, m_fWaveRY, m_fWaveRZ);

				//set scale 
                m_pCSGArray[i]->SetScale(1.0f, 1.0f, 1.0f);

                //set texture type and texture color
				if(m_sSetting.m_enmTextureW == TEX_SINGLE)
				    m_pCSGArray[i]->SetTextureFunc(&SingleColor);
                else if(m_sSetting.m_enmTextureW == TEX_CHECKER)
                    m_pCSGArray[i]->SetTextureFunc(&CheckerTexture);
				else if(m_sSetting.m_enmTextureW == TEX_NOISE)
                    m_pCSGArray[i]->SetTextureFunc(&NoiseTexture);
                m_pCSGArray[i]->SetAlpha(m_sSetting.m_btTexAlpha);
				chkx = (int)(pow(2.0,(double)(m_sSetting.m_iTexChkSizeX)));
				chky = (int)(pow(2.0,(double)(m_sSetting.m_iTexChkSizeY)));
                m_pCSGArray[i]->SetTexSize(chkx, chky);
                m_pCSGArray[i]->SetTexFactor(m_sSetting.m_btTexMasterRed*1.0f,
                                             m_sSetting.m_btTexMasterGreen*1.0f,
											 m_sSetting.m_btTexMasterBlue*1.0f);

                m_pCSGArray[i]->SetTexDiscrete(m_sSetting.m_btTexSecondRed*1.0f,
                                               m_sSetting.m_btTexSecondGreen*1.0f,
											   m_sSetting.m_btTexSecondBlue*1.0f);
			}
        }
	}
}


//draw the object
void CImageWnd::DrawObject(void)
{
	for(int i = 0; i < m_pCSGArray.GetSize(); i++)
	{
 	    glPushMatrix();
		//if the object is sphere
		if(m_pCSGArray[i]->GetType() == TYPE_BALL)
		{
			//if the saver showing object is ball or ball & wave
			if(m_sSetting.m_enmType == CSG_BALL ||
               m_sSetting.m_enmType == CSG_BOTH)
			{
				//draw the object
				m_pCSGArray[i]->DrawObject();
			}
		}
		//if the object is wave
		if(m_pCSGArray[i]->GetType() == TYPE_WAVE)
		{
			//if the saver showing object is wave or wave & wave
			if(m_sSetting.m_enmType == CSG_WAVE ||
               m_sSetting.m_enmType == CSG_BOTH)
			{
				//draw the object
				m_pCSGArray[i]->DrawObject();
			}
        }
	    glPopMatrix();
        glFlush();
	}
}


BOOL CImageWnd::Create(DWORD dwExStyle, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
    // Register a class with no cursor
	LPCTSTR lpszClassName= AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW,
			::LoadCursor(AfxGetResourceHandle(), 
			MAKEINTRESOURCE(IDC_NULLCURSOR)));
	
	return CreateEx(dwExStyle, lpszClassName, _T(""), dwStyle, 
		rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, 
		pParentWnd->GetSafeHwnd(), NULL, NULL );
}

int CImageWnd::OnCreate(LPCREATESTRUCT lpCreateStruct) 
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
	m_hDC = ::GetDC(m_hWnd);			
	
	int pixelFormat =
		ChoosePixelFormat(m_hDC, &pfd);
	BOOL success = 
		SetPixelFormat(m_hDC, pixelFormat, &pfd);

	DescribePixelFormat(m_hDC, pixelFormat,
		  sizeof(pfd), &pfd);

	if(pfd.dwFlags & PFD_NEED_PALETTE)
 	    (*FuncPalette)(m_hDC, m_hPalette);
	
	m_hRC = wglCreateContext(m_hDC);

    wglMakeCurrent(m_hDC, m_hRC); 
	
	Initialize();

	SetupCSGData();

	Invalidate(FALSE); 

	return 0;
}

void CImageWnd::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	float fDensity;
    float fColor[4]; 
    
	if(m_hPalette)
    {
		SelectPalette(m_hDC, m_hPalette, FALSE);
		RealizePalette(m_hDC);
    }
	wglMakeCurrent(m_hDC, m_hRC);


	//check and set fog setting
	if(m_sSetting.m_bFog)
	{
	    fDensity = (float)(m_sSetting.m_iFDensity/256);
        fColor[0] = (float)(m_sSetting.m_iFColorRed/255);
        fColor[1] = (float)(m_sSetting.m_iFColorGreen/255);
        fColor[2] = (float)(m_sSetting.m_iFColorBlue/255);
        fColor[3] = (float)(m_sSetting.m_iFColorAlpha/128);
        
		glFogi(GL_FOG_MODE, GL_EXP2);
        glFogf(GL_FOG_DENSITY, fDensity);
        glFogfv(GL_FOG_COLOR, fColor);
	    glClearColor(fColor[0], fColor[1], fColor[2], fColor[3]);
	    glEnable(GL_FOG);
    } 
	else 
	{
	    glClearColor(0.2F, 0.2F, 0.2F, 1.0F);
	    glDisable(GL_FOG);
    }
    
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
	
	DrawObject();	
	
	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_FOG);
	SwapBuffers(m_hDC);
    glMatrixMode(GL_MODELVIEW);

    wglMakeCurrent(m_hDC, NULL); 
	// Do not call CWnd::OnPaint() for painting messages
}

void CImageWnd::OnPaletteChanged(CWnd* pFocusWnd) 
{
	CWnd::OnPaletteChanged(pFocusWnd);
	
	// TODO: Add your message handler code here
	Invalidate(FALSE); 
}

BOOL CImageWnd::OnQueryNewPalette() 
{
	// TODO: Add your message handler code here and/or call default
	Invalidate(FALSE); 
	
	return CWnd::OnQueryNewPalette();
}

void CImageWnd::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	m_fWaveC -= 0.104719753f;
    if(m_fWaveC < 0.0f)
       m_fWaveC = 6.28318530717959f;

    m_fBallRY += 30.0f;
	if(m_fBallRY > 360.0f)
       m_fBallRY = 0.0f;
    
    if(m_bBallUp == FALSE)
	{
       m_fBallSX += 0.03f;
       m_fBallSZ += 0.03f;
       m_fBallSY -= 0.05f; 
       m_fBallY -= 0.055f;
	   if(m_fBallY <= 0.20f)
       {
           m_fBallY = 0.20f;
		   m_bBallUp = TRUE;
	   }
	}
	else if(m_bBallUp == TRUE)
	{
       m_fBallSX -= 0.03f;
       m_fBallSZ -= 0.03f;
       m_fBallSY += 0.05f; 
       m_fBallY += 0.055f;
	   if(m_fBallY >= 1.85f)
       {
           m_fBallY = 1.85f;
		   m_bBallUp = FALSE;
	   }
	}


	SetupCSGData();
   
	Invalidate(FALSE); 
}

void CImageWnd::PostNcDestroy() 
{
	// TODO: Add your specialized code here and/or call the base class
//	delete this; 
}

void CImageWnd::OnSize(UINT nType, int cx, int cy) 
{
	// TODO: Add your message handler code here
	CRect rect;

    CPaintDC dc(this);
	wglMakeCurrent(dc.m_hDC, m_hRC);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GetClientRect(&rect);
	glFrustum(-1.0, 1.0, -1.0, 1.0, 2.0, 7.0);
	glViewport(0, 0, cx, cy);
	
	wglMakeCurrent(NULL, NULL);
}



void CImageWnd::OnDestroy() 
{
	// TODO: Add your message handler code here
	wglDeleteContext(m_hRC);
	
	if(m_hPalette)
       DeleteObject(m_hPalette);
	
	::ReleaseDC(m_hWnd, m_hDC);
	
    if(m_bHasTimer)
	   KillTimer(1);
	
	CWnd::OnDestroy();
}

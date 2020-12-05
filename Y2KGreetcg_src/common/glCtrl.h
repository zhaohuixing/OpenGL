/**********************************************************/
/*   The glCtrl.h                                          
/*                                                         
/*   Created by Xing Zhaohui (xingzhh@yahoo.com),          
/*   Dec 10, 1999                                           
/*                                                        
/*   Declare the basic OpenGL control which contain        
/*   the different OpenGL objects to render in various     
/*   applications                                         
/* 
/**********************************************************/

#ifndef __GLCTRL_H__
#define __GLCTRL_H__

#include "glObjdef.h"

#include "CMCIPlayer.h"

/////////////////////////////////////////////////////////////////////////////
// CGLControl


class CGLControl : public CWnd
{
// Construction
public:
	CGLControl();
	~CGLControl();

// Attributes
public:
	CPalette  m_Palette; //Logical palette for rendering
	HGLRC     m_hRC;     //Rendering device context of OpenGL
	CDC*      m_pDC;	 //Current device context

	BOOL      m_bHasTimer;//flag for timer in this child window
    int       m_iElapse;  //timer click
	
	int       m_iBallCount;  //Counter of the animation of the ball
	int       m_iBallHide;   //flag of hiding the  ball

	int       m_iWordCount;  //Counter of the animation of the word
	double    m_dWordStep;   //Step of the word rotation
	

	BOOL      m_bHasFog;  //Has fog
	BOOL      m_bIsInit;  //flag for check whether initialize

    float     m_fFogColors[4]; //The fog colors value 
    float     m_fFogDensity;   //The fog density 

    glEllipsoid m_Ball;   //object of ball   
    glWord      m_Word;   //object of word 
    glCube      m_Cube;   //object of cube
    glCube      m_Dot;    //object of cube

    CMCIPlayer  m_MIDIPlayer; //MIDI player
    DWORD       m_dMIDILength;//MIDI data block size
	BOOL        m_bMusicOn;   //Play music or not

	BOOL        m_bJustWord;  //Just show Font

	void        SetWordOnly(BOOL bOnly){m_bJustWord = bOnly;};
// Operations
public:
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGLControl)
	public:
	virtual BOOL Create(DWORD dwExStyle, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	//}}AFX_VIRTUAL

// Implementation
public:

	XGLFUNC(void, SetPalette, (CDC* pDC, CPalette& Palette));

	void SetPaletteFunc(void (*PaletteFunc)(CDC* pDC, CPalette& Palette));
	void SetFogStatus(BOOL bFog);
	void SetFogColors(float fRed, float fGreen, float fBlue, float fAlpha, float fDensity);
	void SetupLights(void);
	void DrawObjects(void);
	void SetupObjects(void);
    void SetMidiName(char* MidiName); 
	void SetPlayOn(BOOL bMusicOn);
	void PlayMusic(BOOL bFlag);

	// Generated message map functions
	//{{AFX_MSG(CGLControl)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnPaletteChanged(CWnd* pFocusWnd);
	afx_msg BOOL OnQueryNewPalette();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


#endif
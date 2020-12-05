#if !defined(AFX_IMAGEWND_H__506A7CB1_D198_11D2_8F1E_00805FBDCBE4__INCLUDED_)
#define AFX_IMAGEWND_H__506A7CB1_D198_11D2_8F1E_00805FBDCBE4__INCLUDED_

// ImageWnd.h : header file
//
#include <afxtempl.h>

#include "saverdef.h"
#include "csg.h"

/////////////////////////////////////////////////////////////////////////////
// CImageWnd window

class CImageWnd : public CWnd
{
// Construction
public:
	CImageWnd();

// Attributes
public:
	HPALETTE m_hPalette; //Logical palette for rendering
	HGLRC    m_hRC;      //Rendering device context of OpenGL
	HDC      m_hDC;		 //Current device context

	BOOL     m_bHasTimer;//flag for timer in this child window
    int      m_iElapse;  //timer click

	BOOL     m_bBallUp;  //flag for the direction of ball movement
	
    SAVERSETTING  m_sSetting;

	float   m_fBallA;    //Effiency "a" of the sphere
	float   m_fBallB;    //Effiency "b" of the sphere
	float   m_fBallC;    //Effiency "c" of the sphere

    float   m_fBallX;    //Transfer in X-axis of sphere
    float   m_fBallY;    //Transfer in Y-axis of sphere
    float   m_fBallZ;    //Transfer in Z-axis of sphere

    float   m_fBallSX;   //Scale in X-axis of sphere
    float   m_fBallSY;   //Scale in Y-axis of sphere
    float   m_fBallSZ;   //Scale in Z-axis of sphere
    
    float   m_fBallRX;   //Rotate in X-axis of sphere
    float   m_fBallRY;   //Rotate in Y-axis of sphere
    float   m_fBallRZ;   //Rotate in Z-axis of sphere

	float   m_fWaveA;    //Effiency "a" of the wave
	float   m_fWaveB;    //Effiency "b" of the wave
	float   m_fWaveC;    //Effiency "c" of the wave

    float   m_fWaveX;    //Transfer in X-axis of wave
    float   m_fWaveY;    //Transfer in Y-axis of wave
    float   m_fWaveZ;    //Transfer in Z-axis of wave

    float   m_fWaveSX;    //Scale in X-axis of wave
    float   m_fWaveSY;    //Scale in Y-axis of wave
    float   m_fWaveSZ;    //Scale in Z-axis of wave
    
    float   m_fWaveRX;    //Rotate in X-axis of wave
    float   m_fWaveRY;    //Rotate in Y-axis of wave
    float   m_fWaveRZ;    //Rotate in Z-axis of wave

	CTypedPtrArray<CObArray, CSGObject*> m_pCSGArray;  //array of object 
	
// Operations
public:
	void Initialize(void);

	void SetSaverSetting(SAVERSETTING* setting);
 
    void SetupCSGData(void);

	void DrawObject(void);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageWnd)
	public:
	virtual BOOL Create(DWORD dwExStyle, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CImageWnd();

	// Generated message map functions
	void(*FuncPalette)(HDC hDC, HPALETTE hPalette);
	
	void InitEverything(void);


	BOOL      m_bIsInit;       //flag for check whether initialize
	//{{AFX_MSG(CImageWnd)
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

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEWND_H__506A7CB1_D198_11D2_8F1E_00805FBDCBE4__INCLUDED_)

#if !defined(AFX_GL3DOCXCTL_H__A015E030_7691_11D3_955D_8422F5C00000__INCLUDED_)
#define AFX_GL3DOCXCTL_H__A015E030_7691_11D3_955D_8422F5C00000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
#include <gl/gl.h>
#include "GLFont.h"

// GL3dOcxCtl.h : Declaration of the CGL3dOcxCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CGL3dOcxCtrl : See GL3dOcxCtl.cpp for implementation.

class CGL3dOcxCtrl : public COleControl
{
	DECLARE_DYNCREATE(CGL3dOcxCtrl)

// Constructor
public:
	CGL3dOcxCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGL3dOcxCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	virtual DWORD GetControlFlags();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CGL3dOcxCtrl();

	DECLARE_OLECREATE_EX(CGL3dOcxCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CGL3dOcxCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CGL3dOcxCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CGL3dOcxCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CGL3dOcxCtrl)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnPaletteChanged(CWnd* pFocusWnd);
	afx_msg BOOL OnQueryNewPalette();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CGL3dOcxCtrl)
	afx_msg BSTR GetContent();
	afx_msg void SetContent(LPCTSTR lpszNewValue);
	afx_msg void GLRender();
	afx_msg void SetStrText(LPCTSTR strText);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CGL3dOcxCtrl)
	void FireGLDraw()
		{FireEvent(eventidGLDraw,EVENT_PARAM(VTS_NONE));}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CGL3dOcxCtrl)
	dispidContent = 1L,
	dispidGLRender = 2L,
	dispidSetStrText = 3L,
	eventidGLDraw = 1L,
	//}}AFX_DISP_ID
	};


private:
	CPalette m_Palette; //the logic palette
	HGLRC    m_hRC;		//Rendering context
    CDC*     m_pDC;		//Device Context

	int      m_cx;
	int      m_cy;


	CGLFont  m_Font;    //GL font control
	CString  m_String;	//the string to be shown

	float    m_shininess;
	float    m_Lightposition[4];
	float    m_Lightspecular[4];
	float    m_Lightdiffuse[4];
	float    m_Lightambient[4];

	void SetupEnv(void);
	void SetupPalette(void);
    void SetupFontColor(void);
    void dcRender(void);
	void SetViewPort(void);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GL3DOCXCTL_H__A015E030_7691_11D3_955D_8422F5C00000__INCLUDED)

// 3DFontView.h : interface of the CMy3DFontView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_3DFONTVIEW_H__4431AE0D_2C62_11D3_955D_8422F5C00000__INCLUDED_)
#define AFX_3DFONTVIEW_H__4431AE0D_2C62_11D3_955D_8422F5C00000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
#include <gl/gl.h>
#include "..\common\GLFont.h"


class CMy3DFontView : public CView
{
protected: // create from serialization only
	CMy3DFontView();
	DECLARE_DYNCREATE(CMy3DFontView)

// Attributes
public:
	CMy3DFontDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy3DFontView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMy3DFontView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	float m_shininess;
	float m_Lightposition[4];
	float m_Lightspecular[4];
	float m_Lightdiffuse[4];
	float m_Lightambient[4];
	
	
	CPalette m_Palette; //the logic palette
	HGLRC    m_hRC;
    CDC*     m_pDC;

	CGLFont  m_FontX;
	CGLFont  m_FontZ;
	CGLFont  m_FontH;


	void InitPalette(void);
	void DrawGLFont(void);
	void InitFontColor(void);

// Generated message map functions
protected:
	//{{AFX_MSG(CMy3DFontView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnFontsolid();
	afx_msg void OnFontwireframe();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 3DFontView.cpp
inline CMy3DFontDoc* CMy3DFontView::GetDocument()
   { return (CMy3DFontDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_3DFONTVIEW_H__4431AE0D_2C62_11D3_955D_8422F5C00000__INCLUDED_)

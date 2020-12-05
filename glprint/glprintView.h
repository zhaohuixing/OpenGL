// glprintView.h : interface of the CGlprintView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GLPRINTVIEW_H__02F85A4D_5671_11D3_955D_8422F5C00000__INCLUDED_)
#define AFX_GLPRINTVIEW_H__02F85A4D_5671_11D3_955D_8422F5C00000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <gl/gl.h>
#include "GLMemDC.h"


class CGlprintView : public CView
{
protected: // create from serialization only
	CGlprintView();
	DECLARE_DYNCREATE(CGlprintView)

// Attributes
public:
	CGlprintDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGlprintView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGlprintView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CPalette m_Palette; //the logic palette
	HGLRC    m_hRC;
    CDC*     m_pDC;

	CGLMemoryDC    m_MemImageDC;

	void SetPalette(void);
	void Initialize(void);
	void DrawObject(void);

// Generated message map functions
protected:
	//{{AFX_MSG(CGlprintView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnFileSave();
	afx_msg void OnFileSaveAs();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in glprintView.cpp
inline CGlprintDoc* CGlprintView::GetDocument()
   { return (CGlprintDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GLPRINTVIEW_H__02F85A4D_5671_11D3_955D_8422F5C00000__INCLUDED_)

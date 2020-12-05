// glprintDoc.h : interface of the CGlprintDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GLPRINTDOC_H__02F85A4B_5671_11D3_955D_8422F5C00000__INCLUDED_)
#define AFX_GLPRINTDOC_H__02F85A4B_5671_11D3_955D_8422F5C00000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CGlprintDoc : public CDocument
{
protected: // create from serialization only
	CGlprintDoc();
	DECLARE_DYNCREATE(CGlprintDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGlprintDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGlprintDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGlprintDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GLPRINTDOC_H__02F85A4B_5671_11D3_955D_8422F5C00000__INCLUDED_)

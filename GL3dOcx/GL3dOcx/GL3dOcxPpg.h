#if !defined(AFX_GL3DOCXPPG_H__A015E032_7691_11D3_955D_8422F5C00000__INCLUDED_)
#define AFX_GL3DOCXPPG_H__A015E032_7691_11D3_955D_8422F5C00000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// GL3dOcxPpg.h : Declaration of the CGL3dOcxPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CGL3dOcxPropPage : See GL3dOcxPpg.cpp.cpp for implementation.

class CGL3dOcxPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CGL3dOcxPropPage)
	DECLARE_OLECREATE_EX(CGL3dOcxPropPage)

// Constructor
public:
	CGL3dOcxPropPage();

// Dialog Data
	//{{AFX_DATA(CGL3dOcxPropPage)
	enum { IDD = IDD_PROPPAGE_GL3DOCX };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CGL3dOcxPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GL3DOCXPPG_H__A015E032_7691_11D3_955D_8422F5C00000__INCLUDED)

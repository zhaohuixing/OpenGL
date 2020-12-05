// greetDlg.h : header file
//

#if !defined(AFX_GREETDLG_H__1064AF87_AE5A_11D3_955D_4491F5C00000__INCLUDED_)
#define AFX_GREETDLG_H__1064AF87_AE5A_11D3_955D_4491F5C00000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGreetDlg dialog
#include "glCtrl.h"


class CGreetDlg : public CDialog
{
// Construction
public:
	CGreetDlg(CWnd* pParent = NULL);	// standard constructor

	CGLControl    m_ShowWnd;

// Dialog Data
	//{{AFX_DATA(CGreetDlg)
	enum { IDD = IDD_GREET_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGreetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGreetDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GREETDLG_H__1064AF87_AE5A_11D3_955D_4491F5C00000__INCLUDED_)

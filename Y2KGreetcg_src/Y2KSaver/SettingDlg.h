// SettingDlg.h : header file
//

#if !defined(AFX_SETTINGDLG_H__BCD721E6_CDB8_11D2_8F19_00805FBDCBE4__INCLUDED_)
#define AFX_SETTINGDLG_H__BCD721E6_CDB8_11D2_8F19_00805FBDCBE4__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CSettingDlg dialog
#include "resource.h"
#include "glCtrl.h"

class CSettingDlg : public CDialog
{
// Construction
public:
	CSettingDlg(CWnd* pParent = NULL);	// standard constructor

    CGLControl   m_wndImage;
    
    BOOL         m_bPlayMusic;

// Dialog Data
	//{{AFX_DATA(CSettingDlg)
	enum { IDD = IDD_Y2K_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSettingDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

    void SetControl(void);
     

	// Generated message map functions
	//{{AFX_MSG(CSettingDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
	afx_msg void OnCheck1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETTINGDLG_H__BCD721E6_CDB8_11D2_8F19_00805FBDCBE4__INCLUDED_)

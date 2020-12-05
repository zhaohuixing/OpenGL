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
#include "saverdef.h"
#include "ImageWnd.h"

class CSettingDlg : public CDialog
{
// Construction
public:
	CSettingDlg(CWnd* pParent = NULL);	// standard constructor

	SAVERSETTING  m_setting;
    CImageWnd     m_wndImage;

	void SetData(SAVERSETTING*  setting);
	void GetData(SAVERSETTING*  setting);


// Dialog Data
	//{{AFX_DATA(CSettingDlg)
	enum { IDD = IDD_GLSAVER_DIALOG };
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
	afx_msg void OnFogcheck();
	afx_msg void OnBall();
	afx_msg void OnWave();
	afx_msg void OnBoth();
	afx_msg void OnBallsmall();
	afx_msg void OnBallmedium();
	afx_msg void OnBalllarge();
	afx_msg void OnWaverectangle();
	afx_msg void OnWaveround();
	afx_msg void OnTexturesingleB();
	afx_msg void OnTexturecheckerB();
	afx_msg void OnTexturenoiseB();
	afx_msg void OnTexturesingleW();
	afx_msg void OnTexturecheckerW();
	afx_msg void OnTexturenoiseW();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBallline();
	afx_msg void OnWaveline();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETTINGDLG_H__BCD721E6_CDB8_11D2_8F19_00805FBDCBE4__INCLUDED_)

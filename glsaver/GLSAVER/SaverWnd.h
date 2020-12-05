// SaverWnd.h: interface for the CSaverWnd class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SAVERWND_H__A8CFF7E1_D4B0_11D2_955D_8422F5C00000__INCLUDED_)
#define AFX_SAVERWND_H__A8CFF7E1_D4B0_11D2_955D_8422F5C00000__INCLUDED_


#include "ImageWnd.h"

class CSaverWnd : public CImageWnd  
{
public:
	CSaverWnd();
	virtual ~CSaverWnd();

	BOOL Create();


	CPoint  m_ptLast;
	// Generated message map functions
protected:
	//{{AFX_MSG(CSaverWnd)
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnDestroy();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg BOOL OnNcActivate(BOOL bActive);
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg void OnActivateApp(BOOL bActive, DWORD hTask);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFX_SAVERWND_H__A8CFF7E1_D4B0_11D2_955D_8422F5C00000__INCLUDED_)

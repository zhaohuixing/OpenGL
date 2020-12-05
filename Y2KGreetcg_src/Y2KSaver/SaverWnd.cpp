// SaverWnd.cpp: implementation of the CSaverWnd class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SaverWnd.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSaverWnd::CSaverWnd()
{
	m_ptLast = CPoint(-1, -1);
}

CSaverWnd::~CSaverWnd()
{

}

BEGIN_MESSAGE_MAP(CSaverWnd, CGLControl)
	//{{AFX_MSG_MAP(CSaverWnd)
	ON_WM_SYSCOMMAND()
	ON_WM_DESTROY()
	ON_WM_SETCURSOR()
	ON_WM_NCACTIVATE()
	ON_WM_ACTIVATE()
	ON_WM_ACTIVATEAPP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_MBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_SYSKEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CSaverWnd message handlers

BOOL CSaverWnd::Create() 
{
	CRect rect(0, 0, ::GetSystemMetrics(SM_CXSCREEN),
		::GetSystemMetrics(SM_CYSCREEN));

	return CGLControl::Create(WS_EX_TOPMOST, WS_VISIBLE|WS_POPUP, rect, NULL, 
		0, NULL);
}

void CSaverWnd::OnSysCommand(UINT nID, LPARAM lParam) 
{
	if ((nID == SC_SCREENSAVE) || (nID == SC_CLOSE))
		return;
	CGLControl::OnSysCommand(nID, lParam);
}

void CSaverWnd::OnDestroy() 
{
	PostQuitMessage(0);
	CGLControl::OnDestroy();
}

BOOL CSaverWnd::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	SetCursor(NULL);
	return TRUE;
}

BOOL CSaverWnd::OnNcActivate(BOOL bActive) 
{
	if (!bActive)
		return FALSE;
	return CGLControl::OnNcActivate(bActive);
}

void CSaverWnd::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized) 
{
	if (nState == WA_INACTIVE)
		PostMessage(WM_CLOSE);
	CGLControl::OnActivate(nState, pWndOther, bMinimized);
}

void CSaverWnd::OnActivateApp(BOOL bActive, DWORD hTask) 
{
	if (!bActive)
		PostMessage(WM_CLOSE);
	CGLControl::OnActivateApp(bActive, hTask);
}

void CSaverWnd::OnMouseMove(UINT nFlags, CPoint point) 
{
	if (m_ptLast == CPoint(-1,-1))
		m_ptLast = point;
	else if (m_ptLast != point)
		PostMessage(WM_CLOSE);
	CGLControl::OnMouseMove(nFlags, point);
}

void CSaverWnd::OnLButtonDown(UINT nFlags, CPoint point) 
{
	PostMessage(WM_CLOSE);
	CGLControl::OnLButtonDown(nFlags, point);
}

void CSaverWnd::OnMButtonDown(UINT nFlags, CPoint point) 
{
	if (m_ptLast == CPoint(-1,-1))
		m_ptLast = point;
	else if (m_ptLast != point)
		PostMessage(WM_CLOSE);
	CGLControl::OnMButtonDown(nFlags, point);
}

void CSaverWnd::OnRButtonDown(UINT nFlags, CPoint point) 
{
	PostMessage(WM_CLOSE);
	CGLControl::OnRButtonDown(nFlags, point);
}

void CSaverWnd::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	PostMessage(WM_CLOSE);
	CGLControl::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CSaverWnd::OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	PostMessage(WM_CLOSE);
	CGLControl::OnSysKeyDown(nChar, nRepCnt, nFlags);
}

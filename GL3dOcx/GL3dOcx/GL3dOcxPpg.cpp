// GL3dOcxPpg.cpp : Implementation of the CGL3dOcxPropPage property page class.

#include "stdafx.h"
#include "GL3dOcx.h"
#include "GL3dOcxPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CGL3dOcxPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CGL3dOcxPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CGL3dOcxPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CGL3dOcxPropPage, "GL3DOCX.GL3dOcxPropPage.1",
	0xa015e023, 0x7691, 0x11d3, 0x95, 0x5d, 0x84, 0x22, 0xf5, 0xc0, 0, 0)


/////////////////////////////////////////////////////////////////////////////
// CGL3dOcxPropPage::CGL3dOcxPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CGL3dOcxPropPage

BOOL CGL3dOcxPropPage::CGL3dOcxPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_GL3DOCX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CGL3dOcxPropPage::CGL3dOcxPropPage - Constructor

CGL3dOcxPropPage::CGL3dOcxPropPage() :
	COlePropertyPage(IDD, IDS_GL3DOCX_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CGL3dOcxPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CGL3dOcxPropPage::DoDataExchange - Moves data between page and properties

void CGL3dOcxPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CGL3dOcxPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CGL3dOcxPropPage message handlers

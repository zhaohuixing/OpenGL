// glprintDoc.cpp : implementation of the CGlprintDoc class
//

#include "stdafx.h"
#include "glprint.h"

#include "glprintDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGlprintDoc

IMPLEMENT_DYNCREATE(CGlprintDoc, CDocument)

BEGIN_MESSAGE_MAP(CGlprintDoc, CDocument)
	//{{AFX_MSG_MAP(CGlprintDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGlprintDoc construction/destruction

CGlprintDoc::CGlprintDoc()
{
	// TODO: add one-time construction code here

}

CGlprintDoc::~CGlprintDoc()
{
}

BOOL CGlprintDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGlprintDoc serialization

void CGlprintDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CGlprintDoc diagnostics

#ifdef _DEBUG
void CGlprintDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGlprintDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGlprintDoc commands

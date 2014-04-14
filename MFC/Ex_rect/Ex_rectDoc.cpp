// Ex_rectDoc.cpp : implementation of the CEx_rectDoc class
//

#include "stdafx.h"
#include "Ex_rect.h"

#include "Ex_rectDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_rectDoc

IMPLEMENT_DYNCREATE(CEx_rectDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_rectDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_rectDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_rectDoc construction/destruction

CEx_rectDoc::CEx_rectDoc()
{
	// TODO: add one-time construction code here

}

CEx_rectDoc::~CEx_rectDoc()
{
}

BOOL CEx_rectDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_rectDoc serialization

void CEx_rectDoc::Serialize(CArchive& ar)
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
// CEx_rectDoc diagnostics

#ifdef _DEBUG
void CEx_rectDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_rectDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_rectDoc commands

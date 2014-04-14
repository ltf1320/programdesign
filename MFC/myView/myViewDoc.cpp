// myViewDoc.cpp : implementation of the CMyViewDoc class
//

#include "stdafx.h"
#include "myView.h"

#include "myViewDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyViewDoc

IMPLEMENT_DYNCREATE(CMyViewDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyViewDoc, CDocument)
	//{{AFX_MSG_MAP(CMyViewDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyViewDoc construction/destruction

CMyViewDoc::CMyViewDoc()
{
	// TODO: add one-time construction code here

}

CMyViewDoc::~CMyViewDoc()
{
}

BOOL CMyViewDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyViewDoc serialization

void CMyViewDoc::Serialize(CArchive& ar)
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
// CMyViewDoc diagnostics

#ifdef _DEBUG
void CMyViewDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyViewDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyViewDoc commands

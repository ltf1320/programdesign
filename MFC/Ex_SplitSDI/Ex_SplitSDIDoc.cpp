// Ex_SplitSDIDoc.cpp : implementation of the CEx_SplitSDIDoc class
//

#include "stdafx.h"
#include "Ex_SplitSDI.h"

#include "Ex_SplitSDIDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_SplitSDIDoc

IMPLEMENT_DYNCREATE(CEx_SplitSDIDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_SplitSDIDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_SplitSDIDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_SplitSDIDoc construction/destruction

CEx_SplitSDIDoc::CEx_SplitSDIDoc()
{
	// TODO: add one-time construction code here

}

CEx_SplitSDIDoc::~CEx_SplitSDIDoc()
{
}

BOOL CEx_SplitSDIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_SplitSDIDoc serialization

void CEx_SplitSDIDoc::Serialize(CArchive& ar)
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
// CEx_SplitSDIDoc diagnostics

#ifdef _DEBUG
void CEx_SplitSDIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_SplitSDIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_SplitSDIDoc commands

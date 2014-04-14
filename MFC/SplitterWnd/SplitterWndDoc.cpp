// SplitterWndDoc.cpp : implementation of the CSplitterWndDoc class
//

#include "stdafx.h"
#include "SplitterWnd.h"

#include "SplitterWndDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSplitterWndDoc

IMPLEMENT_DYNCREATE(CSplitterWndDoc, CDocument)

BEGIN_MESSAGE_MAP(CSplitterWndDoc, CDocument)
	//{{AFX_MSG_MAP(CSplitterWndDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSplitterWndDoc construction/destruction

CSplitterWndDoc::CSplitterWndDoc()
{
	// TODO: add one-time construction code here

}

CSplitterWndDoc::~CSplitterWndDoc()
{
}

BOOL CSplitterWndDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSplitterWndDoc serialization

void CSplitterWndDoc::Serialize(CArchive& ar)
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
// CSplitterWndDoc diagnostics

#ifdef _DEBUG
void CSplitterWndDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSplitterWndDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSplitterWndDoc commands

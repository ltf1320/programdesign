// 20120619_2Doc.cpp : implementation of the CMy20120619_2Doc class
//

#include "stdafx.h"
#include "20120619_2.h"

#include "20120619_2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy20120619_2Doc

IMPLEMENT_DYNCREATE(CMy20120619_2Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy20120619_2Doc, CDocument)
	//{{AFX_MSG_MAP(CMy20120619_2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy20120619_2Doc construction/destruction

CMy20120619_2Doc::CMy20120619_2Doc()
{
	// TODO: add one-time construction code here

}

CMy20120619_2Doc::~CMy20120619_2Doc()
{
}

BOOL CMy20120619_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMy20120619_2Doc serialization

void CMy20120619_2Doc::Serialize(CArchive& ar)
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
// CMy20120619_2Doc diagnostics

#ifdef _DEBUG
void CMy20120619_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy20120619_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy20120619_2Doc commands

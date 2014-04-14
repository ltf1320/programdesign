// Ex_Rect2Doc.cpp : implementation of the CEx_Rect2Doc class
//

#include "stdafx.h"
#include "Ex_Rect2.h"

#include "Ex_Rect2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_Rect2Doc

IMPLEMENT_DYNCREATE(CEx_Rect2Doc, CDocument)

BEGIN_MESSAGE_MAP(CEx_Rect2Doc, CDocument)
	//{{AFX_MSG_MAP(CEx_Rect2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_Rect2Doc construction/destruction



CEx_Rect2Doc::~CEx_Rect2Doc()
{
}

BOOL CEx_Rect2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_Rect2Doc serialization

void CEx_Rect2Doc::Serialize(CArchive& ar)
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
// CEx_Rect2Doc diagnostics

#ifdef _DEBUG
void CEx_Rect2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_Rect2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_Rect2Doc commands

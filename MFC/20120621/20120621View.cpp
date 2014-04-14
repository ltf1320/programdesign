// 20120621View.cpp : implementation of the CMy20120621View class
//

#include "stdafx.h"
#include "20120621.h"

#include "20120621Doc.h"
#include "20120621View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy20120621View

IMPLEMENT_DYNCREATE(CMy20120621View, CView)

BEGIN_MESSAGE_MAP(CMy20120621View, CView)
	//{{AFX_MSG_MAP(CMy20120621View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy20120621View construction/destruction

CMy20120621View::CMy20120621View()
{
	// TODO: add construction code here

}

CMy20120621View::~CMy20120621View()
{
}

BOOL CMy20120621View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMy20120621View drawing

void CMy20120621View::OnDraw(CDC* pDC)
{
	CMy20120621Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMy20120621View printing

BOOL CMy20120621View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy20120621View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy20120621View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMy20120621View diagnostics

#ifdef _DEBUG
void CMy20120621View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20120621View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20120621Doc* CMy20120621View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20120621Doc)));
	return (CMy20120621Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy20120621View message handlers

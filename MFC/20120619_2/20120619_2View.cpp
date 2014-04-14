// 20120619_2View.cpp : implementation of the CMy20120619_2View class
//

#include "stdafx.h"
#include "20120619_2.h"

#include "20120619_2Doc.h"
#include "20120619_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy20120619_2View

IMPLEMENT_DYNCREATE(CMy20120619_2View, CView)

BEGIN_MESSAGE_MAP(CMy20120619_2View, CView)
	//{{AFX_MSG_MAP(CMy20120619_2View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy20120619_2View construction/destruction

CMy20120619_2View::CMy20120619_2View()
{
	// TODO: add construction code here

}

CMy20120619_2View::~CMy20120619_2View()
{
}

BOOL CMy20120619_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMy20120619_2View drawing

void CMy20120619_2View::OnDraw(CDC* pDC)
{
	CMy20120619_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMy20120619_2View printing

BOOL CMy20120619_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy20120619_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy20120619_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMy20120619_2View diagnostics

#ifdef _DEBUG
void CMy20120619_2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20120619_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20120619_2Doc* CMy20120619_2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20120619_2Doc)));
	return (CMy20120619_2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy20120619_2View message handlers

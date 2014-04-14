// SplitterWndView.cpp : implementation of the CSplitterWndView class
//

#include "stdafx.h"
#include "SplitterWnd.h"

#include "SplitterWndDoc.h"
#include "SplitterWndView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSplitterWndView

IMPLEMENT_DYNCREATE(CSplitterWndView, CView)

BEGIN_MESSAGE_MAP(CSplitterWndView, CView)
	//{{AFX_MSG_MAP(CSplitterWndView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSplitterWndView construction/destruction

CSplitterWndView::CSplitterWndView()
{
	// TODO: add construction code here

}

CSplitterWndView::~CSplitterWndView()
{
}

BOOL CSplitterWndView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSplitterWndView drawing

void CSplitterWndView::OnDraw(CDC* pDC)
{
	CSplitterWndDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSplitterWndView printing

BOOL CSplitterWndView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSplitterWndView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSplitterWndView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSplitterWndView diagnostics

#ifdef _DEBUG
void CSplitterWndView::AssertValid() const
{
	CView::AssertValid();
}

void CSplitterWndView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSplitterWndDoc* CSplitterWndView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSplitterWndDoc)));
	return (CSplitterWndDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSplitterWndView message handlers

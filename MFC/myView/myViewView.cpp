// myViewView.cpp : implementation of the CMyViewView class
//

#include "stdafx.h"
#include "myView.h"

#include "myViewDoc.h"
#include "myViewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyViewView

IMPLEMENT_DYNCREATE(CMyViewView, CView)

BEGIN_MESSAGE_MAP(CMyViewView, CView)
	//{{AFX_MSG_MAP(CMyViewView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyViewView construction/destruction

CMyViewView::CMyViewView()
{
	// TODO: add construction code here

}

CMyViewView::~CMyViewView()
{
}

BOOL CMyViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyViewView drawing

void CMyViewView::OnDraw(CDC* pDC)
{
	CMyViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMyViewView printing

BOOL CMyViewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyViewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyViewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyViewView diagnostics

#ifdef _DEBUG
void CMyViewView::AssertValid() const
{
	CView::AssertValid();
}

void CMyViewView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyViewDoc* CMyViewView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyViewDoc)));
	return (CMyViewDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyViewView message handlers

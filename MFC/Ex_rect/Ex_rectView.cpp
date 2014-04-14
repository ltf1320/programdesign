// Ex_rectView.cpp : implementation of the CEx_rectView class
//

#include "stdafx.h"
#include "Ex_rect.h"

#include "Ex_rectDoc.h"
#include "Ex_rectView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_rectView

IMPLEMENT_DYNCREATE(CEx_rectView, CView)

BEGIN_MESSAGE_MAP(CEx_rectView, CView)
	//{{AFX_MSG_MAP(CEx_rectView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_rectView construction/destruction

CEx_rectView::CEx_rectView()
{
	// TODO: add construction code here

}

CEx_rectView::~CEx_rectView()
{
}

BOOL CEx_rectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_rectView drawing

void CEx_rectView::OnDraw(CDC* pDC)
{
	CEx_rectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEx_rectView printing

BOOL CEx_rectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_rectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_rectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_rectView diagnostics

#ifdef _DEBUG
void CEx_rectView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_rectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_rectDoc* CEx_rectView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_rectDoc)));
	return (CEx_rectDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_rectView message handlers

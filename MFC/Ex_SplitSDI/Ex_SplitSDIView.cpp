// Ex_SplitSDIView.cpp : implementation of the CEx_SplitSDIView class
//

#include "stdafx.h"
#include "Ex_SplitSDI.h"

#include "Ex_SplitSDIDoc.h"
#include "Ex_SplitSDIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_SplitSDIView

IMPLEMENT_DYNCREATE(CEx_SplitSDIView, CView)

BEGIN_MESSAGE_MAP(CEx_SplitSDIView, CView)
	//{{AFX_MSG_MAP(CEx_SplitSDIView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_SplitSDIView construction/destruction

CEx_SplitSDIView::CEx_SplitSDIView()
{
	// TODO: add construction code here

}

CEx_SplitSDIView::~CEx_SplitSDIView()
{
}

BOOL CEx_SplitSDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_SplitSDIView drawing

void CEx_SplitSDIView::OnDraw(CDC* pDC)
{
	CEx_SplitSDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEx_SplitSDIView printing

BOOL CEx_SplitSDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_SplitSDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_SplitSDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_SplitSDIView diagnostics

#ifdef _DEBUG
void CEx_SplitSDIView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_SplitSDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_SplitSDIDoc* CEx_SplitSDIView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_SplitSDIDoc)));
	return (CEx_SplitSDIDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_SplitSDIView message handlers

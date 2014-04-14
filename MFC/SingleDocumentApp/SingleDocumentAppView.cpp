// SingleDocumentAppView.cpp : implementation of the CSingleDocumentAppView class
//

#include "stdafx.h"
#include "SingleDocumentApp.h"

#include "SingleDocumentAppDoc.h"
#include "SingleDocumentAppView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSingleDocumentAppView

IMPLEMENT_DYNCREATE(CSingleDocumentAppView, CView)

BEGIN_MESSAGE_MAP(CSingleDocumentAppView, CView)
	//{{AFX_MSG_MAP(CSingleDocumentAppView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSingleDocumentAppView construction/destruction

CSingleDocumentAppView::CSingleDocumentAppView()
{
	// TODO: add construction code here

}

CSingleDocumentAppView::~CSingleDocumentAppView()
{
}

BOOL CSingleDocumentAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSingleDocumentAppView drawing

void CSingleDocumentAppView::OnDraw(CDC* pDC)
{
	CSingleDocumentAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSingleDocumentAppView printing

BOOL CSingleDocumentAppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSingleDocumentAppView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSingleDocumentAppView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSingleDocumentAppView diagnostics

#ifdef _DEBUG
void CSingleDocumentAppView::AssertValid() const
{
	CView::AssertValid();
}

void CSingleDocumentAppView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSingleDocumentAppDoc* CSingleDocumentAppView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSingleDocumentAppDoc)));
	return (CSingleDocumentAppDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSingleDocumentAppView message handlers

// Ex_Rect2View.cpp : implementation of the CEx_Rect2View class
//

#include "stdafx.h"
#include "Ex_Rect2.h"

#include "Ex_Rect2Doc.h"
#include "Ex_Rect2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_Rect2View

IMPLEMENT_DYNCREATE(CEx_Rect2View, CFormView)

BEGIN_MESSAGE_MAP(CEx_Rect2View, CFormView)
	//{{AFX_MSG_MAP(CEx_Rect2View)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit)
	ON_EN_CHANGE(IDC_EDIT2, OnChangeEdit)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_Rect2View construction/destruction

CEx_Rect2View::CEx_Rect2View()
	: CFormView(CEx_Rect2View::IDD)
{
	m_bEditOK=FALSE;
	//{{AFX_DATA_INIT(CEx_Rect2View)
	m_CoorX = 0;
	m_CoorY = 0;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CEx_Rect2View::~CEx_Rect2View()
{
}

void CEx_Rect2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEx_Rect2View)
	DDX_Control(pDX, IDC_SPIN2, m_SpinY);
	DDX_Control(pDX, IDC_SPIN1, m_SpinX);
	DDX_Text(pDX, IDC_EDIT1, m_CoorX);
	DDX_Text(pDX, IDC_EDIT2, m_CoorY);
	//}}AFX_DATA_MAP
}

BOOL CEx_Rect2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CEx_Rect2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	ResizeParentToFit();
	CEx_Rect2Doc* pDoc=(CEx_Rect2Doc*)GetDocument();
	m_CoorX=pDoc->m_ptRect.x;
	m_SpinX.SetRange(0,1024);
	UpdateData(0);
	m_bEditOK=TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CEx_Rect2View printing

BOOL CEx_Rect2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_Rect2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_Rect2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CEx_Rect2View::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CEx_Rect2View diagnostics

#ifdef _DEBUG
void CEx_Rect2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CEx_Rect2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CEx_Rect2Doc* CEx_Rect2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_Rect2Doc)));
	return (CEx_Rect2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_Rect2View message handlers

void CEx_Rect2View::OnChangeEdit() 
{
	if(!m_bEditOK) return;
	UpdateData(1);
	CEx_Rect2Doc *pDoc=(CEx_Rect2Doc*)GetDocument();
	pDoc->m_ptRect.x=m_CoorX;
	pDoc->m_ptRect.y=m_CoorY;
	CPoint pt(m_CoorX,m_CoorY);
	pDoc->UpdateAllViews(NULL,2,(CObject *)&pt);
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CEx_Rect2View::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	if(lHint==1)
	{
		CPoint* pPoint=(CPoint*)pHint;
		m_CoorX=pPoint->x;
		m_CoorY=pPoint->y;
		UpdateData(0);
		CEx_Rect2Doc* pDoc=(CEx_Rect2Doc*)GetDocument();
		pDoc->m_ptRect=*pPoint;
	}
}

BOOL CEx_Rect2View::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

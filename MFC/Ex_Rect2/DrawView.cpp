// DrawView.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Rect2.h"
#include "DrawView.h"
#include "Ex_Rect2Doc.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawView

IMPLEMENT_DYNCREATE(CDrawView, CView)

CDrawView::CDrawView()
{

}


BEGIN_MESSAGE_MAP(CDrawView, CView)
	//{{AFX_MSG_MAP(CDrawView)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawView drawing

void CDrawView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	CRect rc(m_ptDraw.x-5,m_ptDraw.y-5,m_ptDraw.x+5,m_ptDraw.y+5);
	pDC->Rectangle(rc);
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CDrawView diagnostics

#ifdef _DEBUG
void CDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawView message handlers

void CDrawView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	CEx_Rect2Doc* pDoc=(CEx_Rect2Doc*)m_pDocument;
	m_ptDraw=pDoc->m_ptRect;
}

void CDrawView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{

	if(lHint==2)
	{
		CPoint *pPoint=(CPoint*)pHint;
		m_ptDraw=*pPoint;
		Invalidate();
	}
}

CDrawView::~CDrawView()
{
}

void CDrawView::OnLButtonDown(UINT nFlags, CPoint point) 
{

	m_ptDraw=point;
	GetDocument()->UpdateAllViews(NULL,1,(CObject*)&m_ptDraw);
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}

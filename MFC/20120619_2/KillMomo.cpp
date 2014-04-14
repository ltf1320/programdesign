// KillMomo.cpp : implementation file
//

#include "stdafx.h"
#include "20120619_2.h"
#include "KillMomo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// KillMomo

IMPLEMENT_DYNCREATE(KillMomo, CFormView)

KillMomo::KillMomo()
	: CFormView(KillMomo::IDD)
{
	//{{AFX_DATA_INIT(KillMomo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

KillMomo::~KillMomo()
{
}

void KillMomo::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(KillMomo)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(KillMomo, CFormView)
	//{{AFX_MSG_MAP(KillMomo)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// KillMomo diagnostics

#ifdef _DEBUG
void KillMomo::AssertValid() const
{
	CFormView::AssertValid();
}

void KillMomo::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// KillMomo message handlers

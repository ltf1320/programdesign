// Dialog2.cpp : implementation file
//

#include "stdafx.h"
#include "20120621.h"
#include "Dialog2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dialog2 dialog


Dialog2::Dialog2(CWnd* pParent /*=NULL*/)
	: CDialog(Dialog2::IDD, pParent)
{
	//{{AFX_DATA_INIT(Dialog2)
	m_N1 = 0;
	m_N2 = 0;
	//}}AFX_DATA_INIT

}


void Dialog2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Dialog2)
	DDX_Text(pDX, IDC_N1, m_N1);
	DDX_Text(pDX, IDC_N2, m_N2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Dialog2, CDialog)
	//{{AFX_MSG_MAP(Dialog2)
	ON_BN_CLICKED(IDC_CAL, OnCal)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Dialog2 message handlers

void Dialog2::OnCal() 
{
	UpdateData(1);
	m_N2=1;
	for(int i=1;i<=m_N1;++i)
		m_N2*=i;
	UpdateData(0);
}

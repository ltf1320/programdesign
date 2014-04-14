// Dialog.cpp : implementation file
//

#include "stdafx.h"
#include "20120621.h"
#include "Dialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dialog dialog


Dialog::Dialog(CWnd* pParent /*=NULL*/)
	: CDialog(Dialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(Dialog)
	m_N1 = _T("");
	m_N2 = 0;
	m_N3 = _T("");
	//}}AFX_DATA_INIT
	
}


void Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Dialog)
	DDX_Text(pDX, IDC_N1, m_N1);
	DDX_Text(pDX, IDC_N2, m_N2);
	DDX_Text(pDX, IDC_N3, m_N3);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Dialog, CDialog)
	//{{AFX_MSG_MAP(Dialog)
	ON_BN_CLICKED(IDC_Start, OnStart)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Dialog message handlers


void Dialog::OnStart() 
{
	UpdateData(1);
	m_N3.Format("Momo is %s killed %d times",m_N1,m_N2);
	UpdateData(0);	
}

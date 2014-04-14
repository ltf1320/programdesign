// 20120619Dlg.h : header file
//

#if !defined(AFX_20120619DLG_H__A0B074CC_A8C6_4314_A7E2_990BECCAACF2__INCLUDED_)
#define AFX_20120619DLG_H__A0B074CC_A8C6_4314_A7E2_990BECCAACF2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy20120619Dlg dialog

class CMy20120619Dlg : public CDialog
{
// Construction
public:
	CMy20120619Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy20120619Dlg)
	enum { IDD = IDD_MY20120619_DIALOG };
	double	m_A;
	double	m_B;
	double	m_C;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy20120619Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy20120619Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_20120619DLG_H__A0B074CC_A8C6_4314_A7E2_990BECCAACF2__INCLUDED_)

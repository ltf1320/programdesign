#if !defined(AFX_DIALOG2_H__54077710_F844_4391_8F68_0525EFD13098__INCLUDED_)
#define AFX_DIALOG2_H__54077710_F844_4391_8F68_0525EFD13098__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Dialog2 dialog

class Dialog2 : public CDialog
{
// Construction
public:
	Dialog2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Dialog2)
	enum { IDD = IDD_DIALOG1 };
	long	m_N1;
	long	m_N2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Dialog2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Dialog2)
	afx_msg void OnCal();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG2_H__54077710_F844_4391_8F68_0525EFD13098__INCLUDED_)

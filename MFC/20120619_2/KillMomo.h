#if !defined(AFX_KILLMOMO_H__75574E36_D76A_4160_B074_770ECDC20A18__INCLUDED_)
#define AFX_KILLMOMO_H__75574E36_D76A_4160_B074_770ECDC20A18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// KillMomo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// KillMomo form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class KillMomo : public CFormView
{
protected:
	KillMomo();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(KillMomo)

// Form Data
public:
	//{{AFX_DATA(KillMomo)
	enum { IDD = IDD_KILLMOMO_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(KillMomo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~KillMomo();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(KillMomo)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KILLMOMO_H__75574E36_D76A_4160_B074_770ECDC20A18__INCLUDED_)

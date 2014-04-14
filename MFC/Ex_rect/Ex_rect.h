// Ex_rect.h : main header file for the EX_RECT application
//

#if !defined(AFX_EX_RECT_H__6D0FD42D_A5E7_4EDD_B1F6_DC53731241CB__INCLUDED_)
#define AFX_EX_RECT_H__6D0FD42D_A5E7_4EDD_B1F6_DC53731241CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_rectApp:
// See Ex_rect.cpp for the implementation of this class
//

class CEx_rectApp : public CWinApp
{
public:
	CEx_rectApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_rectApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_rectApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_RECT_H__6D0FD42D_A5E7_4EDD_B1F6_DC53731241CB__INCLUDED_)

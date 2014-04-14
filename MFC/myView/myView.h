// myView.h : main header file for the MYVIEW application
//

#if !defined(AFX_MYVIEW_H__A3470A4C_A001_4A77_885B_39524A6DFDE3__INCLUDED_)
#define AFX_MYVIEW_H__A3470A4C_A001_4A77_885B_39524A6DFDE3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyViewApp:
// See myView.cpp for the implementation of this class
//

class CMyViewApp : public CWinApp
{
public:
	CMyViewApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyViewApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMyViewApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYVIEW_H__A3470A4C_A001_4A77_885B_39524A6DFDE3__INCLUDED_)

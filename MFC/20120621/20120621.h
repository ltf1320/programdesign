// 20120621.h : main header file for the 20120621 application
//

#if !defined(AFX_20120621_H__7D0974C2_91CB_462E_941C_226FE2E0F4E9__INCLUDED_)
#define AFX_20120621_H__7D0974C2_91CB_462E_941C_226FE2E0F4E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy20120621App:
// See 20120621.cpp for the implementation of this class
//

class CMy20120621App : public CWinApp     
{
public:
	CMy20120621App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy20120621App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMy20120621App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_20120621_H__7D0974C2_91CB_462E_941C_226FE2E0F4E9__INCLUDED_)
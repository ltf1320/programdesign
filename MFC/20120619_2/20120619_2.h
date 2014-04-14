// 20120619_2.h : main header file for the 20120619_2 application
//

#if !defined(AFX_20120619_2_H__33A327FC_C6EB_4C51_B120_3D40C40F1805__INCLUDED_)
#define AFX_20120619_2_H__33A327FC_C6EB_4C51_B120_3D40C40F1805__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy20120619_2App:
// See 20120619_2.cpp for the implementation of this class
//

class CMy20120619_2App : public CWinApp
{
public:
	CMy20120619_2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy20120619_2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMy20120619_2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_20120619_2_H__33A327FC_C6EB_4C51_B120_3D40C40F1805__INCLUDED_)

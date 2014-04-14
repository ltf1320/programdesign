// 20120619_1.h : main header file for the 20120619_1 application
//

#if !defined(AFX_20120619_1_H__EE467AF7_BA52_47AE_A224_1E8F42E68C98__INCLUDED_)
#define AFX_20120619_1_H__EE467AF7_BA52_47AE_A224_1E8F42E68C98__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy20120619_1App:
// See 20120619_1.cpp for the implementation of this class
//

class CMy20120619_1App : public CWinApp
{
public:
	CMy20120619_1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy20120619_1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMy20120619_1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_20120619_1_H__EE467AF7_BA52_47AE_A224_1E8F42E68C98__INCLUDED_)

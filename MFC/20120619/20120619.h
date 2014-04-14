// 20120619.h : main header file for the 20120619 application
//

#if !defined(AFX_20120619_H__384A8973_ED99_4E67_BE8D_21386634B9F2__INCLUDED_)
#define AFX_20120619_H__384A8973_ED99_4E67_BE8D_21386634B9F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy20120619App:
// See 20120619.cpp for the implementation of this class
//

class CMy20120619App : public CWinApp
{
public:
	CMy20120619App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy20120619App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy20120619App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_20120619_H__384A8973_ED99_4E67_BE8D_21386634B9F2__INCLUDED_)

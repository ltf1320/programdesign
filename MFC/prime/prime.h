// prime.h : main header file for the PRIME application
//

#if !defined(AFX_PRIME_H__9C8C0754_CB67_4CD4_92EC_0D4DC3033021__INCLUDED_)
#define AFX_PRIME_H__9C8C0754_CB67_4CD4_92EC_0D4DC3033021__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPrimeApp:
// See prime.cpp for the implementation of this class
//

class CPrimeApp : public CWinApp
{
public:
	CPrimeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrimeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPrimeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRIME_H__9C8C0754_CB67_4CD4_92EC_0D4DC3033021__INCLUDED_)

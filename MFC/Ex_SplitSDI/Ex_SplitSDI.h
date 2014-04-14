// Ex_SplitSDI.h : main header file for the EX_SPLITSDI application
//

#if !defined(AFX_EX_SPLITSDI_H__02521FA5_8C94_4139_AF0E_0FC9A801CC7B__INCLUDED_)
#define AFX_EX_SPLITSDI_H__02521FA5_8C94_4139_AF0E_0FC9A801CC7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_SplitSDIApp:
// See Ex_SplitSDI.cpp for the implementation of this class
//

class CEx_SplitSDIApp : public CWinApp
{
public:
	CEx_SplitSDIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_SplitSDIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_SplitSDIApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_SPLITSDI_H__02521FA5_8C94_4139_AF0E_0FC9A801CC7B__INCLUDED_)

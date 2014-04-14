// SingleDocumentApp.h : main header file for the SINGLEDOCUMENTAPP application
//

#if !defined(AFX_SINGLEDOCUMENTAPP_H__D2ABFD4E_5A60_45E7_95C8_4AE3BC9B3369__INCLUDED_)
#define AFX_SINGLEDOCUMENTAPP_H__D2ABFD4E_5A60_45E7_95C8_4AE3BC9B3369__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSingleDocumentAppApp:
// See SingleDocumentApp.cpp for the implementation of this class
//

class CSingleDocumentAppApp : public CWinApp
{
public:
	CSingleDocumentAppApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSingleDocumentAppApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSingleDocumentAppApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINGLEDOCUMENTAPP_H__D2ABFD4E_5A60_45E7_95C8_4AE3BC9B3369__INCLUDED_)

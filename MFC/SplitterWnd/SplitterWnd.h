// SplitterWnd.h : main header file for the SPLITTERWND application
//

#if !defined(AFX_SPLITTERWND_H__41515D91_29AE_44B1_82C8_896ADB7777B0__INCLUDED_)
#define AFX_SPLITTERWND_H__41515D91_29AE_44B1_82C8_896ADB7777B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSplitterWndApp:
// See SplitterWnd.cpp for the implementation of this class
//

class CSplitterWndApp : public CWinApp
{
public:
	CSplitterWndApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSplitterWndApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSplitterWndApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPLITTERWND_H__41515D91_29AE_44B1_82C8_896ADB7777B0__INCLUDED_)

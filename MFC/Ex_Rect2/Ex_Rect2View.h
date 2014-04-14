// Ex_Rect2View.h : interface of the CEx_Rect2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_RECT2VIEW_H__D8CE8EAB_FCD4_4EF6_BBCB_1F7D3421C3DB__INCLUDED_)
#define AFX_EX_RECT2VIEW_H__D8CE8EAB_FCD4_4EF6_BBCB_1F7D3421C3DB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CEx_Rect2Doc;
class CEx_Rect2View;

class CEx_Rect2View : public CFormView
{
protected: // create from serialization only
	CEx_Rect2View();
	DECLARE_DYNCREATE(CEx_Rect2View)
public:
	//{{AFX_DATA(CEx_Rect2View)
	enum { IDD = IDD_EX_RECT2_FORM };
	CSpinButtonCtrl	m_SpinY;
	CSpinButtonCtrl	m_SpinX;
	int		m_CoorX;
	int		m_CoorY;
	//}}AFX_DATA
	BOOL m_bEditOK;
// Attributes
public:
	CEx_Rect2Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_Rect2View)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_Rect2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_Rect2View)
	afx_msg void OnChangeEdit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_Rect2View.cpp
inline CEx_Rect2Doc* CEx_Rect2View::GetDocument()
   { return (CEx_Rect2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_RECT2VIEW_H__D8CE8EAB_FCD4_4EF6_BBCB_1F7D3421C3DB__INCLUDED_)

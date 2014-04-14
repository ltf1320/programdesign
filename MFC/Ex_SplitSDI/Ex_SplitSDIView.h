// Ex_SplitSDIView.h : interface of the CEx_SplitSDIView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_SPLITSDIVIEW_H__524AE2A4_7A4E_44A6_A5ED_5C869962AA03__INCLUDED_)
#define AFX_EX_SPLITSDIVIEW_H__524AE2A4_7A4E_44A6_A5ED_5C869962AA03__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_SplitSDIView : public CView
{
protected: // create from serialization only
	CEx_SplitSDIView();
	DECLARE_DYNCREATE(CEx_SplitSDIView)

// Attributes
public:
	CEx_SplitSDIDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_SplitSDIView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_SplitSDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_SplitSDIView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_SplitSDIView.cpp
inline CEx_SplitSDIDoc* CEx_SplitSDIView::GetDocument()
   { return (CEx_SplitSDIDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_SPLITSDIVIEW_H__524AE2A4_7A4E_44A6_A5ED_5C869962AA03__INCLUDED_)

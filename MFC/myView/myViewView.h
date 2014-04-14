// myViewView.h : interface of the CMyViewView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYVIEWVIEW_H__45A93289_380C_4E9D_AEA6_0E0BE551B8E8__INCLUDED_)
#define AFX_MYVIEWVIEW_H__45A93289_380C_4E9D_AEA6_0E0BE551B8E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyViewView : public CView
{
protected: // create from serialization only
	CMyViewView();
	DECLARE_DYNCREATE(CMyViewView)

// Attributes
public:
	CMyViewDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyViewView)
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
	virtual ~CMyViewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyViewView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in myViewView.cpp
inline CMyViewDoc* CMyViewView::GetDocument()
   { return (CMyViewDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYVIEWVIEW_H__45A93289_380C_4E9D_AEA6_0E0BE551B8E8__INCLUDED_)

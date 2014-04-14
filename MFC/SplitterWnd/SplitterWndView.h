// SplitterWndView.h : interface of the CSplitterWndView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPLITTERWNDVIEW_H__05C80804_6976_4739_9BCB_2A55CF8984F2__INCLUDED_)
#define AFX_SPLITTERWNDVIEW_H__05C80804_6976_4739_9BCB_2A55CF8984F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSplitterWndView : public CView
{
protected: // create from serialization only
	CSplitterWndView();
	DECLARE_DYNCREATE(CSplitterWndView)

// Attributes
public:
	CSplitterWndDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSplitterWndView)
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
	virtual ~CSplitterWndView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSplitterWndView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SplitterWndView.cpp
inline CSplitterWndDoc* CSplitterWndView::GetDocument()
   { return (CSplitterWndDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPLITTERWNDVIEW_H__05C80804_6976_4739_9BCB_2A55CF8984F2__INCLUDED_)

// SingleDocumentAppView.h : interface of the CSingleDocumentAppView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SINGLEDOCUMENTAPPVIEW_H__F5F997CF_00B6_4610_A476_85E950639DD1__INCLUDED_)
#define AFX_SINGLEDOCUMENTAPPVIEW_H__F5F997CF_00B6_4610_A476_85E950639DD1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSingleDocumentAppView : public CView
{
protected: // create from serialization only
	CSingleDocumentAppView();
	DECLARE_DYNCREATE(CSingleDocumentAppView)

// Attributes
public:
	CSingleDocumentAppDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSingleDocumentAppView)
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
	virtual ~CSingleDocumentAppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSingleDocumentAppView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SingleDocumentAppView.cpp
inline CSingleDocumentAppDoc* CSingleDocumentAppView::GetDocument()
   { return (CSingleDocumentAppDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINGLEDOCUMENTAPPVIEW_H__F5F997CF_00B6_4610_A476_85E950639DD1__INCLUDED_)

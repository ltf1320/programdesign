// 20120619_1View.h : interface of the CMy20120619_1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_20120619_1VIEW_H__C780E891_0731_41B3_990C_1D3B48C07678__INCLUDED_)
#define AFX_20120619_1VIEW_H__C780E891_0731_41B3_990C_1D3B48C07678__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMy20120619_1View : public CView
{
protected: // create from serialization only
	CMy20120619_1View();
	DECLARE_DYNCREATE(CMy20120619_1View)

// Attributes
public:
	CMy20120619_1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy20120619_1View)
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
	virtual ~CMy20120619_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy20120619_1View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 20120619_1View.cpp
inline CMy20120619_1Doc* CMy20120619_1View::GetDocument()
   { return (CMy20120619_1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_20120619_1VIEW_H__C780E891_0731_41B3_990C_1D3B48C07678__INCLUDED_)

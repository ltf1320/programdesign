// 20120621View.h : interface of the CMy20120621View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_20120621VIEW_H__5CE8F4E9_3749_4E84_84C8_11477AA7A866__INCLUDED_)
#define AFX_20120621VIEW_H__5CE8F4E9_3749_4E84_84C8_11477AA7A866__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMy20120621View : public CView
{
protected: // create from serialization only
	CMy20120621View();
	DECLARE_DYNCREATE(CMy20120621View)

// Attributes
public:
	CMy20120621Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy20120621View)
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
	virtual ~CMy20120621View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy20120621View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 20120621View.cpp
inline CMy20120621Doc* CMy20120621View::GetDocument()
   { return (CMy20120621Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_20120621VIEW_H__5CE8F4E9_3749_4E84_84C8_11477AA7A866__INCLUDED_)

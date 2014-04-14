// 20120619_2View.h : interface of the CMy20120619_2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_20120619_2VIEW_H__E1C2A0D1_B0D3_4BE5_8454_56D57CBBFFE6__INCLUDED_)
#define AFX_20120619_2VIEW_H__E1C2A0D1_B0D3_4BE5_8454_56D57CBBFFE6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMy20120619_2View : public CView
{
protected: // create from serialization only
	CMy20120619_2View();
	DECLARE_DYNCREATE(CMy20120619_2View)

// Attributes
public:
	CMy20120619_2Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy20120619_2View)
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
	virtual ~CMy20120619_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy20120619_2View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 20120619_2View.cpp
inline CMy20120619_2Doc* CMy20120619_2View::GetDocument()
   { return (CMy20120619_2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_20120619_2VIEW_H__E1C2A0D1_B0D3_4BE5_8454_56D57CBBFFE6__INCLUDED_)

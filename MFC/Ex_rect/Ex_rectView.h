// Ex_rectView.h : interface of the CEx_rectView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_RECTVIEW_H__28AFF2B7_05D8_4F31_9C28_AC7CFD67F1BB__INCLUDED_)
#define AFX_EX_RECTVIEW_H__28AFF2B7_05D8_4F31_9C28_AC7CFD67F1BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_rectView : public CView
{
protected: // create from serialization only
	CEx_rectView();
	DECLARE_DYNCREATE(CEx_rectView)

// Attributes
public:
	CEx_rectDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_rectView)
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
	virtual ~CEx_rectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_rectView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_rectView.cpp
inline CEx_rectDoc* CEx_rectView::GetDocument()
   { return (CEx_rectDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_RECTVIEW_H__28AFF2B7_05D8_4F31_9C28_AC7CFD67F1BB__INCLUDED_)

#if !defined(AFX_DEMOVIEW_H__B0BB1BBD_B689_4A19_8C37_C8D688CD065A__INCLUDED_)
#define AFX_DEMOVIEW_H__B0BB1BBD_B689_4A19_8C37_C8D688CD065A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DemoView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDemoView view

class CDemoView : public CView
{
protected:
	CDemoView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CDemoView)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CDemoView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMOVIEW_H__B0BB1BBD_B689_4A19_8C37_C8D688CD065A__INCLUDED_)

// Ex_Rect2Doc.h : interface of the CEx_Rect2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_RECT2DOC_H__03EDBFF4_9017_46B4_A0A6_AFC65BADFBD2__INCLUDED_)
#define AFX_EX_RECT2DOC_H__03EDBFF4_9017_46B4_A0A6_AFC65BADFBD2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_Rect2Doc : public CDocument
{
protected: // create from serialization only
//	CEx_Rect2Doc();
	CEx_Rect2Doc()
{
	m_ptRect.x=m_ptRect.y=0;
}

	DECLARE_DYNCREATE(CEx_Rect2Doc);

// Attributes
public:

// Operations
public:
	CPoint m_ptRect;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_Rect2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_Rect2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_Rect2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};




/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_RECT2DOC_H__03EDBFF4_9017_46B4_A0A6_AFC65BADFBD2__INCLUDED_)


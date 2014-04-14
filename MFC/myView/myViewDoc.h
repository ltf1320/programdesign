// myViewDoc.h : interface of the CMyViewDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYVIEWDOC_H__90C98700_C3F5_4786_B81D_DFD9B8B5AF30__INCLUDED_)
#define AFX_MYVIEWDOC_H__90C98700_C3F5_4786_B81D_DFD9B8B5AF30__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyViewDoc : public CDocument
{
protected: // create from serialization only
	CMyViewDoc();
	DECLARE_DYNCREATE(CMyViewDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyViewDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyViewDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyViewDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYVIEWDOC_H__90C98700_C3F5_4786_B81D_DFD9B8B5AF30__INCLUDED_)

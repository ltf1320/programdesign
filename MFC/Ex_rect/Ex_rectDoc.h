// Ex_rectDoc.h : interface of the CEx_rectDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_RECTDOC_H__83C2301C_55E9_4E5F_B9E9_A6B5C4F56929__INCLUDED_)
#define AFX_EX_RECTDOC_H__83C2301C_55E9_4E5F_B9E9_A6B5C4F56929__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_rectDoc : public CDocument
{
protected: // create from serialization only
	CEx_rectDoc();
	DECLARE_DYNCREATE(CEx_rectDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_rectDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_rectDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_rectDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_RECTDOC_H__83C2301C_55E9_4E5F_B9E9_A6B5C4F56929__INCLUDED_)

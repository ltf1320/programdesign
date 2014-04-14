// SingleDocumentAppDoc.h : interface of the CSingleDocumentAppDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SINGLEDOCUMENTAPPDOC_H__A3557213_E914_4C65_AF06_9E60728540C9__INCLUDED_)
#define AFX_SINGLEDOCUMENTAPPDOC_H__A3557213_E914_4C65_AF06_9E60728540C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSingleDocumentAppDoc : public CDocument
{
protected: // create from serialization only
	CSingleDocumentAppDoc();
	DECLARE_DYNCREATE(CSingleDocumentAppDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSingleDocumentAppDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSingleDocumentAppDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSingleDocumentAppDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINGLEDOCUMENTAPPDOC_H__A3557213_E914_4C65_AF06_9E60728540C9__INCLUDED_)

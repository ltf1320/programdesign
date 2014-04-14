// SplitterWndDoc.h : interface of the CSplitterWndDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPLITTERWNDDOC_H__27E31B01_BBC4_4E35_B8D4_0A1B7FFFA049__INCLUDED_)
#define AFX_SPLITTERWNDDOC_H__27E31B01_BBC4_4E35_B8D4_0A1B7FFFA049__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSplitterWndDoc : public CDocument
{
protected: // create from serialization only
	CSplitterWndDoc();
	DECLARE_DYNCREATE(CSplitterWndDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSplitterWndDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSplitterWndDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSplitterWndDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPLITTERWNDDOC_H__27E31B01_BBC4_4E35_B8D4_0A1B7FFFA049__INCLUDED_)

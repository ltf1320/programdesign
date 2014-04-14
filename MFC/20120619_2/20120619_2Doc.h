// 20120619_2Doc.h : interface of the CMy20120619_2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_20120619_2DOC_H__6AA60483_D5AC_4972_B5C8_235CE598B018__INCLUDED_)
#define AFX_20120619_2DOC_H__6AA60483_D5AC_4972_B5C8_235CE598B018__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMy20120619_2Doc : public CDocument
{
protected: // create from serialization only
	CMy20120619_2Doc();
	DECLARE_DYNCREATE(CMy20120619_2Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy20120619_2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMy20120619_2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy20120619_2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_20120619_2DOC_H__6AA60483_D5AC_4972_B5C8_235CE598B018__INCLUDED_)

// 20120619_1Doc.h : interface of the CMy20120619_1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_20120619_1DOC_H__C448FF4F_836C_4FC8_9A98_454283744B2B__INCLUDED_)
#define AFX_20120619_1DOC_H__C448FF4F_836C_4FC8_9A98_454283744B2B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMy20120619_1Doc : public CDocument
{
protected: // create from serialization only
	CMy20120619_1Doc();
	DECLARE_DYNCREATE(CMy20120619_1Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy20120619_1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMy20120619_1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy20120619_1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_20120619_1DOC_H__C448FF4F_836C_4FC8_9A98_454283744B2B__INCLUDED_)

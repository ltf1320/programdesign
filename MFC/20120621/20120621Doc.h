// 20120621Doc.h : interface of the CMy20120621Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_20120621DOC_H__F7151D96_E181_4044_9F93_22AF274439D4__INCLUDED_)
#define AFX_20120621DOC_H__F7151D96_E181_4044_9F93_22AF274439D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMy20120621Doc : public CDocument
{
protected: // create from serialization only
	CMy20120621Doc();
	DECLARE_DYNCREATE(CMy20120621Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy20120621Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMy20120621Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy20120621Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_20120621DOC_H__F7151D96_E181_4044_9F93_22AF274439D4__INCLUDED_)

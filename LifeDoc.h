// LifeDoc.h : interface of the CLifeDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIFEDOC_H__D69833BF_4C83_47FE_AFFA_6046760233CB__INCLUDED_)
#define AFX_LIFEDOC_H__D69833BF_4C83_47FE_AFFA_6046760233CB__INCLUDED_

#include "Field.h"
#include "FieldDlg.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLifeDoc : public CDocument
{
protected: // create from serialization only
	CLifeDoc();
	DECLARE_DYNCREATE(CLifeDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLifeDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	CSize GetSize();
	void PutCell(CPoint point, char temp);
	char GetCell(CPoint point);
	CPoint PointToCell(CPoint point);
	CPoint PointToFloor(CPoint point);
	CPoint PointToNear(CPoint point);
	virtual ~CLifeDoc();
	BOOL m_select;
	BOOL m_selected;
	BOOL m_redraw;
	BOOL m_timer;
	CField m_field;
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	void OnUpdateIndicatorTime(CCmdUI *pCmdUI);
	void OnUpdateIndicatorBorn(CCmdUI *pCmdUI);
	void OnUpdateIndicatorDead(CCmdUI *pCmdUI);
	void OnUpdateIndicatorTotal(CCmdUI *pCmdUI);
	//{{AFX_MSG(CLifeDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIFEDOC_H__D69833BF_4C83_47FE_AFFA_6046760233CB__INCLUDED_)

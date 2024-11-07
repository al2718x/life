// LifeView.h : interface of the CLifeView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIFEVIEW_H__FE287DF9_F72C_4E85_8F7D_A57513E7DEF8__INCLUDED_)
#define AFX_LIFEVIEW_H__FE287DF9_F72C_4E85_8F7D_A57513E7DEF8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLifeView : public CScrollView
{
protected: // create from serialization only
	CLifeView();
	DECLARE_DYNCREATE(CLifeView)

// Attributes
public:
	CLifeDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLifeView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLifeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLifeView)
	afx_msg void OnHelpHelp();
	afx_msg void OnToolsSetup();
	afx_msg void OnToolsGo();
	afx_msg void OnToolsRun();
	afx_msg void OnToolsStop();
	afx_msg void OnUpdateToolsGo(CCmdUI* pCmdUI);
	afx_msg void OnUpdateToolsRun(CCmdUI* pCmdUI);
	afx_msg void OnUpdateToolsStop(CCmdUI* pCmdUI);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnToolsRandomfill();
	afx_msg void OnToolsClear();
	afx_msg void OnToolsSelect();
	afx_msg void OnUpdateToolsSelect(CCmdUI* pCmdUI);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnToolsFliphorizontal();
	afx_msg void OnToolsFlipvertical();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnViewRefresh();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnToolsDefault();
	afx_msg void OnFileReload();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void DrawSelection();
	CPoint m_selStart;
	CPoint m_selEnd;
	CPoint m_selOld;
	CPoint m_selFrom;
//	int m_cntPrev;
};

#ifndef _DEBUG  // debug version in LifeView.cpp
inline CLifeDoc* CLifeView::GetDocument()
   { return (CLifeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIFEVIEW_H__FE287DF9_F72C_4E85_8F7D_A57513E7DEF8__INCLUDED_)

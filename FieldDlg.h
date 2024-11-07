#if !defined(AFX_FIELDDLG_H__4714C145_B2B8_4DDD_BE20_9E0478253258__INCLUDED_)
#define AFX_FIELDDLG_H__4714C145_B2B8_4DDD_BE20_9E0478253258__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FieldDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFieldDlg dialog

class CFieldDlg : public CDialog
{
// Construction
public:
	COLORREF m_colorGrid;
	COLORREF m_colorVoid;
	COLORREF m_colorDead;
	COLORREF m_colorBorn;
	COLORREF m_colorLive;
	CFieldDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFieldDlg)
	enum { IDD = IDD_FIELDDIALOG };
	BOOL	m_rect;
	BOOL	m_grid;
	int		m_interval;
	int		m_x;
	int		m_y;
	int		m_size;
	BOOL	m_trace;
	int		m_step;
	CString	m_comment;
	CEdit*	m_edit;
	BOOL	m_paintBG;
	BOOL	m_torus;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFieldDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFieldDlg)
	afx_msg void OnColorgrid();
	afx_msg void OnColorlive();
	afx_msg void OnColorborn();
	afx_msg void OnColordead();
	afx_msg void OnColorvoid();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FIELDDLG_H__4714C145_B2B8_4DDD_BE20_9E0478253258__INCLUDED_)

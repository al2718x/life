// FieldDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Life.h"
#include "FieldDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFieldDlg dialog


CFieldDlg::CFieldDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFieldDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFieldDlg)
	m_rect = FALSE;
	m_grid = FALSE;
	m_interval = 0;
	m_x = 0;
	m_y = 0;
	m_size = 0;
	m_trace = FALSE;
	m_step = 0;
	m_paintBG = FALSE;
	m_torus = FALSE;
	//}}AFX_DATA_INIT
}


void CFieldDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFieldDlg)
	DDX_Check(pDX, IDC_RECT, m_rect);
	DDX_Check(pDX, IDC_GRID, m_grid);
	DDX_Text(pDX, IDC_INTERVAL, m_interval);
	DDV_MinMaxInt(pDX, m_interval, 10, 10000);
	DDX_Text(pDX, IDC_X, m_x);
	DDV_MinMaxInt(pDX, m_x, 5, 500);
	DDX_Text(pDX, IDC_Y, m_y);
	DDV_MinMaxInt(pDX, m_y, 5, 500);
	DDX_Text(pDX, IDC_SIZEXY, m_size);
	DDV_MinMaxInt(pDX, m_size, 3, 60);
	DDX_Check(pDX, IDC_TRACE, m_trace);
	DDX_Text(pDX, IDC_STEP, m_step);
	DDV_MinMaxInt(pDX, m_step, 1, 1000);
	DDX_Text(pDX, IDC_EDIT, m_comment);
	DDV_MaxChars(pDX, m_comment, 200);
	DDX_Check(pDX, IDC_PAINTBG, m_paintBG);
	DDX_Check(pDX, IDC_TORUS, m_torus);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFieldDlg, CDialog)
	//{{AFX_MSG_MAP(CFieldDlg)
	ON_BN_CLICKED(IDC_COLORGRID, OnColorgrid)
	ON_BN_CLICKED(IDC_COLORLIVE, OnColorlive)
	ON_BN_CLICKED(IDC_COLORBORN, OnColorborn)
	ON_BN_CLICKED(IDC_COLORDEAD, OnColordead)
	ON_BN_CLICKED(IDC_COLORVOID, OnColorvoid)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFieldDlg message handlers

void CFieldDlg::OnColorgrid() 
{
	CColorDialog dlg(m_colorGrid);
	if (dlg.DoModal() == IDOK) m_colorGrid = dlg.GetColor();
}

void CFieldDlg::OnColorvoid() 
{
	CColorDialog dlg(m_colorVoid);
	if (dlg.DoModal() == IDOK) m_colorVoid = dlg.GetColor();
}

void CFieldDlg::OnColordead() 
{
	CColorDialog dlg(m_colorDead);
	if (dlg.DoModal() == IDOK) m_colorDead = dlg.GetColor();
}

void CFieldDlg::OnColorborn() 
{
	CColorDialog dlg(m_colorBorn);
	if (dlg.DoModal() == IDOK) m_colorBorn = dlg.GetColor();
}

void CFieldDlg::OnColorlive() 
{
	CColorDialog dlg(m_colorLive);
	if (dlg.DoModal() == IDOK) m_colorLive = dlg.GetColor();
}

int CFieldDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_edit = new CEdit;
	m_edit->Create(WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOVSCROLL | ES_MULTILINE | ES_WANTRETURN, CRect(12, 160, 282, 244), this, IDC_EDIT);
//	m_edit->SetLimitText(200);

	return 0;
}

void CFieldDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	delete m_edit;
}

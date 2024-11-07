// LifeView.cpp : implementation of the CLifeView class
//

#include "stdafx.h"
#include "Life.h"

#include "LifeDoc.h"
#include "LifeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLifeView

IMPLEMENT_DYNCREATE(CLifeView, CScrollView)

BEGIN_MESSAGE_MAP(CLifeView, CScrollView)
	//{{AFX_MSG_MAP(CLifeView)
	ON_COMMAND(ID_HELP_HELP, OnHelpHelp)
	ON_COMMAND(ID_TOOLS_SETUP, OnToolsSetup)
	ON_COMMAND(ID_TOOLS_GO, OnToolsGo)
	ON_COMMAND(ID_TOOLS_RUN, OnToolsRun)
	ON_COMMAND(ID_TOOLS_STOP, OnToolsStop)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_GO, OnUpdateToolsGo)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_RUN, OnUpdateToolsRun)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_STOP, OnUpdateToolsStop)
	ON_WM_TIMER()
	ON_WM_SETCURSOR()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_SIZE()
	ON_WM_SETFOCUS()
	ON_COMMAND(ID_TOOLS_RANDOMFILL, OnToolsRandomfill)
	ON_COMMAND(ID_TOOLS_CLEAR, OnToolsClear)
	ON_COMMAND(ID_TOOLS_SELECT, OnToolsSelect)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_SELECT, OnUpdateToolsSelect)
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_TOOLS_FLIPHORIZONTAL, OnToolsFliphorizontal)
	ON_COMMAND(ID_TOOLS_FLIPVERTICAL, OnToolsFlipvertical)
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_VIEW_REFRESH, OnViewRefresh)
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_TOOLS_DEFAULT, OnToolsDefault)
	ON_COMMAND(ID_FILE_RELOAD, OnFileReload)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLifeView construction/destruction

CLifeView::CLifeView()
{
	// TODO: add construction code here
}

CLifeView::~CLifeView()
{
}

BOOL CLifeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLifeView drawing

void CLifeView::OnDraw(CDC* pDC)
{
	CLifeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	if (pDoc->m_redraw){
		CDC *pDC = GetDC();
		pDoc->m_field.DrawFull(pDC);
		if (pDoc->m_selected) DrawSelection();
		ReleaseDC(pDC);
		pDoc->m_redraw = FALSE;
	}
	else pDoc->m_field.DrawArr(pDC);
	//SetScrollSizes(MM_TEXT, pDoc->GetSize());
}

void CLifeView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 10;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/////////////////////////////////////////////////////////////////////////////
// CLifeView diagnostics

#ifdef _DEBUG
void CLifeView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CLifeView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CLifeDoc* CLifeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLifeDoc)));
	return (CLifeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLifeView message handlers

void CLifeView::OnHelpHelp()
{
	char hlp[256];
	GetModuleFileName(NULL, hlp, 255);
	int pos = strlen(hlp)-3;
	hlp[pos++] = 'h';
	hlp[pos++] = 'l';
	hlp[pos] = 'p';
	::WinHelp(m_hWnd, hlp, HELP_CONTENTS, 0);
}

void CLifeView::OnToolsSetup()
{
	CLifeDoc *pDoc = GetDocument();
	CFieldDlg dlg;
	dlg.m_paintBG = pDoc->m_field.m_paintBG;
	dlg.m_grid = pDoc->m_field.m_grid;
	dlg.m_rect = pDoc->m_field.m_rect;
	dlg.m_trace = pDoc->m_field.m_trace;
	dlg.m_torus = pDoc->m_field.m_torus;
	dlg.m_x = pDoc->m_field.m_Xcount;
	dlg.m_y = pDoc->m_field.m_Ycount;
	dlg.m_size = pDoc->m_field.m_size;
	dlg.m_interval = pDoc->m_field.m_interval;
	dlg.m_step = pDoc->m_field.m_step;
	dlg.m_colorGrid = pDoc->m_field.m_colorGrid;
	dlg.m_colorVoid = pDoc->m_field.m_colorVoid;
	dlg.m_colorDead = pDoc->m_field.m_colorDead;
	dlg.m_colorBorn = pDoc->m_field.m_colorBorn;
	dlg.m_colorLive = pDoc->m_field.m_colorLive;
	dlg.m_comment = pDoc->m_field.m_comment;
	if (dlg.DoModal() == IDOK){
		pDoc->m_field.m_paintBG = dlg.m_paintBG;
		pDoc->m_field.m_grid = dlg.m_grid;
		pDoc->m_field.m_rect = dlg.m_rect;
		pDoc->m_field.m_trace = dlg.m_trace;
		pDoc->m_field.m_torus = dlg.m_torus;
		pDoc->m_field.m_Xcount = dlg.m_x;
		pDoc->m_field.m_Ycount = dlg.m_y;
		pDoc->m_field.m_size = dlg.m_size;
		pDoc->m_field.m_colorGrid = dlg.m_colorGrid;
		pDoc->m_field.m_colorVoid = dlg.m_colorVoid;
		pDoc->m_field.m_colorDead = dlg.m_colorDead;
		pDoc->m_field.m_colorBorn = dlg.m_colorBorn;
		pDoc->m_field.m_colorLive = dlg.m_colorLive;
		pDoc->m_field.m_step = dlg.m_step;
		pDoc->m_field.m_comment = dlg.m_comment;
		if (pDoc->m_field.m_interval != dlg.m_interval){
			pDoc->m_field.m_interval = dlg.m_interval;
			if (pDoc->m_timer){
				OnToolsStop();
				OnToolsRun();
			}
		}
		pDoc->SetModifiedFlag();
		Invalidate();
	}
	else{
		if (pDoc->m_selected){
			pDoc->m_selected = FALSE;
			pDoc->m_redraw = TRUE;
			Invalidate();
		}
	}
	pDoc->m_selected = FALSE;
	pDoc->m_select = FALSE;
}

void CLifeView::OnToolsGo()
{
/*	WINDOWPLACEMENT pPl;
	pPl.length = sizeof(WINDOWPLACEMENT);
	::GetWindowPlacement(theApp.m_hInstance, &pPl);
	if (pPl.showCmd == SW_SHOWNORMAL) pPl.showCmd = SW_SHOWMAXIMIZED;
	else pPl.showCmd = SW_SHOWNORMAL;
	::SetWindowPlacement(theApp.m_hInstance, &pPl);
*/
	CLifeDoc *pDoc = GetDocument();
	CDC *pDC = GetDC();
	pDoc->m_field.Go(pDC);
	ReleaseDC(pDC);
	pDoc->SetModifiedFlag();
}

void CLifeView::OnToolsRun()
{
	CLifeDoc *pDoc = GetDocument();
	pDoc->SetModifiedFlag();
	pDoc->m_timer = TRUE;
//	m_cntPrev = -1;
	SetTimer(ID_TIMER, pDoc->m_field.m_interval, NULL);
}

void CLifeView::OnToolsStop()
{
	KillTimer(ID_TIMER);
	GetDocument()->m_timer = FALSE;
}

void CLifeView::OnUpdateToolsGo(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(!GetDocument()->m_timer);
}

void CLifeView::OnUpdateToolsRun(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(!GetDocument()->m_timer);
}

void CLifeView::OnUpdateToolsStop(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(GetDocument()->m_timer);
}

void CLifeView::OnTimer(UINT nIDEvent)
{
	CLifeDoc *pDoc = GetDocument();
	if (pDoc->m_timer){
		CDC *pDC = GetDC();
		pDoc->m_field.Go(pDC);
		ReleaseDC(pDC);
		if ((pDoc->m_field.m_cntDead == 0) && (pDoc->m_field.m_cntBorn == 0)) OnToolsStop();
//		if ((pDoc->m_field.m_autoStop) && (pDoc->m_field.m_cntDead == pDoc->m_field.m_cntBorn) && (m_cntPrev == pDoc->m_field.m_cntBorn)) OnToolsStop();
//		m_cntPrev = pDoc->m_field.m_cntBorn;
	}
	else OnToolsStop();
	CScrollView::OnTimer(nIDEvent);
}

BOOL CLifeView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	if (GetDocument()->m_selected) SetCursor(AfxGetApp()->LoadStandardCursor(IDC_SIZEALL));
	else SetCursor(AfxGetApp()->LoadStandardCursor(IDC_CROSS));
	return TRUE;
//	return CScrollView::OnSetCursor(pWnd, nHitTest, message);
}

void CLifeView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CLifeDoc *pDoc = GetDocument();
	if (pDoc->m_select){
		m_selStart = pDoc->PointToNear(point);
		m_selEnd.x = point.x+1;
		m_selEnd.y = point.y+1;
		DrawSelection();
	}
	else{
		if (pDoc->m_selected){
			m_selFrom = m_selStart;
			m_selOld = point;
		}
		else{
			if (pDoc->GetCell(point) == F_LIVE) pDoc->PutCell(point, F_VOID);
			else pDoc->PutCell(point, F_LIVE);
			//Invalidate();
			CRect rect(CPoint(pDoc->PointToFloor(point)), CSize(pDoc->m_field.m_size, pDoc->m_field.m_size));
			InvalidateRect(rect, FALSE);
		}
	}
	CScrollView::OnLButtonDown(nFlags, point);
}

void CLifeView::OnLButtonUp(UINT nFlags, CPoint point)
{
	CLifeDoc *pDoc = GetDocument();
	if (pDoc->m_select){
		DrawSelection();
		m_selEnd = pDoc->PointToNear(point);
		pDoc->m_select = FALSE;
		if ((m_selStart.x != m_selEnd.x) && (m_selStart.y != m_selEnd.y)){
			pDoc->m_selected = TRUE;
			DrawSelection();
		}
	}
	else{
		if (pDoc->m_selected){
			m_selStart = pDoc->PointToNear(m_selStart);
			m_selEnd = pDoc->PointToNear(m_selEnd);
			pDoc->m_field.FillArrRect(pDoc->PointToCell(m_selFrom), CRect(pDoc->PointToCell(m_selStart), pDoc->PointToCell(m_selEnd)), (nFlags & MK_CONTROL));
			pDoc->SetModifiedFlag();
			pDoc->m_selected = FALSE;
			pDoc->m_redraw = TRUE;
			Invalidate();
		}
	}
	CScrollView::OnLButtonUp(nFlags, point);
}

void CLifeView::OnMouseMove(UINT nFlags, CPoint point)
{
	CLifeDoc *pDoc = GetDocument();
	if (pDoc->m_select){
		if (nFlags & MK_LBUTTON){
			DrawSelection();
			m_selEnd = point;
			DrawSelection();
		}
	}
	else{
		if (pDoc->m_selected){
			if (nFlags & MK_LBUTTON){
				DrawSelection();
				CPoint dd = point;
				dd.x -= m_selOld.x;
				dd.y -= m_selOld.y;
				m_selOld = point;
				m_selStart.x += dd.x;
				m_selStart.y += dd.y;
				m_selEnd.x += dd.x;
				m_selEnd.y += dd.y;
				DrawSelection();
			}
		}
		else{
			if (nFlags & MK_LBUTTON){
				pDoc->PutCell(point, F_LIVE);
				CRect rect(CPoint(pDoc->PointToFloor(point)), CSize(pDoc->m_field.m_size, pDoc->m_field.m_size));
				InvalidateRect(rect, FALSE);
			}
			if (nFlags & MK_RBUTTON){
				pDoc->PutCell(point, F_VOID);
				CRect rect(CPoint(pDoc->PointToFloor(point)), CSize(pDoc->m_field.m_size, pDoc->m_field.m_size));
				InvalidateRect(rect, FALSE);
			}
		}
	}
	CScrollView::OnMouseMove(nFlags, point);
}

void CLifeView::OnSize(UINT nType, int cx, int cy)
{
	CScrollView::OnSize(nType, cx, cy);
	GetDocument()->m_redraw = TRUE;
}

void CLifeView::OnSetFocus(CWnd* pOldWnd)
{
	CScrollView::OnSetFocus(pOldWnd);
	GetDocument()->m_redraw = TRUE;
}

void CLifeView::OnToolsRandomfill()
{
	CLifeDoc *pDoc = GetDocument();
	if (pDoc->m_selected) pDoc->m_field.FillArrRandom(CRect(pDoc->PointToCell(m_selStart), pDoc->PointToCell(m_selEnd)));
	else pDoc->m_field.FillArrRandom(CRect(0, 0, pDoc->m_field.m_Xcount, pDoc->m_field.m_Ycount));
	pDoc->m_select = pDoc->m_selected = FALSE;
	pDoc->SetModifiedFlag();
	pDoc->m_redraw = TRUE;
	Invalidate();
}

void CLifeView::OnToolsClear()
{
	CLifeDoc *pDoc = GetDocument();
	pDoc->m_timer = FALSE;
	pDoc->m_field.m_time = 0;
	if (pDoc->m_selected) pDoc->m_field.FillArr(CRect(pDoc->PointToCell(m_selStart), pDoc->PointToCell(m_selEnd)), F_VOID);
	else pDoc->m_field.FillArr(CRect(0, 0, ARR_SIZE, ARR_SIZE), F_VOID);
	pDoc->m_select = pDoc->m_selected = FALSE;
	pDoc->SetModifiedFlag();
	pDoc->m_redraw = TRUE;
	Invalidate();
}

void CLifeView::OnToolsFliphorizontal()
{
	CLifeDoc *pDoc = GetDocument();
	if (pDoc->m_selected) pDoc->m_field.FlipArrH(CRect(pDoc->PointToCell(m_selStart), pDoc->PointToCell(m_selEnd)));
	else pDoc->m_field.FlipArrH(CRect(1, 1, pDoc->m_field.m_Xcount-1, pDoc->m_field.m_Ycount-1));
	pDoc->m_select = pDoc->m_selected = FALSE;
	pDoc->SetModifiedFlag();
	pDoc->m_redraw = TRUE;
	Invalidate();
}

void CLifeView::OnToolsFlipvertical()
{
	CLifeDoc *pDoc = GetDocument();
	if (pDoc->m_selected) pDoc->m_field.FlipArrV(CRect(pDoc->PointToCell(m_selStart), pDoc->PointToCell(m_selEnd)));
	else pDoc->m_field.FlipArrV(CRect(1, 1, pDoc->m_field.m_Xcount-1, pDoc->m_field.m_Ycount-1));
	pDoc->m_select = pDoc->m_selected = FALSE;
	pDoc->SetModifiedFlag();
	pDoc->m_redraw = TRUE;
	Invalidate();
}

void CLifeView::OnToolsSelect()
{
	CLifeDoc *pDoc = GetDocument();
	if (pDoc->m_select) pDoc->m_select = FALSE;
	else pDoc->m_select = TRUE;
	if (pDoc->m_selected){
		pDoc->m_selected = FALSE;
		pDoc->m_redraw = TRUE;
		Invalidate();
	}
	pDoc->m_selected = FALSE;
}

void CLifeView::OnUpdateToolsSelect(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(GetDocument()->m_select);
	pCmdUI->Enable(!GetDocument()->m_timer);
}

void CLifeView::DrawSelection()
{
	CDC *pDC = GetDC();
	CRect rect(m_selStart, m_selEnd);
	if (rect.left > rect.right){
		int n = rect.left;
		rect.left = rect.right;
		rect.right = n;
	}
	if (rect.top > rect.bottom){
		int n = rect.top;
		rect.top = rect.bottom;
		rect.bottom = n;
	}
	DrawFocusRect(*pDC, rect);
	ReleaseDC(pDC);
}

void CLifeView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CLifeDoc *pDoc = GetDocument();
	if (pDoc->m_selected){
		switch (nChar){
		case VK_LEFT:{
			DrawSelection();
			m_selStart.x -= pDoc->m_field.m_size;
			m_selEnd.x -= pDoc->m_field.m_size;
			DrawSelection();
			break;
		}
		case VK_RIGHT:{
			DrawSelection();
			m_selStart.x += pDoc->m_field.m_size;
			m_selEnd.x += pDoc->m_field.m_size;
			DrawSelection();
			break;
		}
		case VK_UP:{
			DrawSelection();
			m_selStart.y -= pDoc->m_field.m_size;
			m_selEnd.y -= pDoc->m_field.m_size;
			DrawSelection();
			break;
		}
		case VK_DOWN:{
			DrawSelection();
			m_selStart.y += pDoc->m_field.m_size;
			m_selEnd.y += pDoc->m_field.m_size;
			DrawSelection();
		}
		}
	}
	CScrollView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CLifeView::OnViewRefresh()
{
	GetDocument()->m_redraw = TRUE;
	Invalidate();
}

BOOL CLifeView::OnEraseBkgnd(CDC* pDC)
{
	if (GetDocument()->m_field.m_paintBG){
		CBrush brush(GetDocument()->m_field.m_colorVoid);
		CBrush *brushOld = pDC->SelectObject(&brush);
		CRect rect;
		pDC->GetClipBox(&rect);
		pDC->PatBlt(rect.left, rect.top, rect.Width(), rect.Height(), PATCOPY);
		pDC->SelectObject(brushOld);
		return TRUE;
	}
	else return CScrollView::OnEraseBkgnd(pDC);
}

void CLifeView::OnToolsDefault()
{
	CLifeDoc *pDoc = GetDocument();
	pDoc->m_field.SetDefault(FALSE);
	pDoc->m_redraw = TRUE;
	pDoc->m_selected = FALSE;
	pDoc->m_select = FALSE;
	Invalidate();
}

void CLifeView::OnFileReload()
{
	CLifeDoc *pDoc = GetDocument();
	CString name = pDoc->GetPathName();
	if (name != ""){
		pDoc->OnNewDocument();
		pDoc->OnOpenDocument(name);
		pDoc->SetPathName(name);
		Invalidate();
	}
}

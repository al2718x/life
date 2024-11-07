// LifeDoc.cpp : implementation of the CLifeDoc class
//

#include "stdafx.h"
#include "Life.h"

#include "LifeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLifeDoc

IMPLEMENT_DYNCREATE(CLifeDoc, CDocument)

BEGIN_MESSAGE_MAP(CLifeDoc, CDocument)
	//{{AFX_MSG_MAP(CLifeDoc)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_TIME, OnUpdateIndicatorTime)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_BORN, OnUpdateIndicatorBorn)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_DEAD, OnUpdateIndicatorDead)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_TOTAL, OnUpdateIndicatorTotal)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLifeDoc construction/destruction

CLifeDoc::CLifeDoc()
{
	// TODO: add one-time construction code here
	m_select = m_selected = m_timer = FALSE;

}

CLifeDoc::~CLifeDoc()
{
}

BOOL CLifeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	m_select = m_selected = m_timer = FALSE;
	m_field.SetDefault();

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CLifeDoc serialization

void CLifeDoc::Serialize(CArchive& ar)
{
	m_field.Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CLifeDoc diagnostics

#ifdef _DEBUG
void CLifeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLifeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLifeDoc commands

void CLifeDoc::PutCell(CPoint point, char temp)
{
	CPoint p = PointToCell(point);
	if (m_field.PutArr(p.x, p.y, temp)) SetModifiedFlag();
}

char CLifeDoc::GetCell(CPoint point)
{
	CPoint p = PointToCell(point);
	return m_field.GetArr(p.x, p.y);
}

CPoint CLifeDoc::PointToCell(CPoint point)
{
	point.x /= m_field.m_size;
	point.y /= m_field.m_size;
	return point;
}

CPoint CLifeDoc::PointToFloor(CPoint point)
{
	point = PointToCell(point);
	point.x *= m_field.m_size;
	point.y *= m_field.m_size;
	return point;
}

CPoint CLifeDoc::PointToNear(CPoint point)
{
	CPoint newPoint = PointToCell(point);
	newPoint.x *= m_field.m_size;
	newPoint.y *= m_field.m_size;
	if ((point.x - newPoint.x) > m_field.m_size / 2) newPoint.x += m_field.m_size;
	if ((point.y - newPoint.y) > m_field.m_size / 2) newPoint.y += m_field.m_size;
	return newPoint;
}

CSize CLifeDoc::GetSize()
{
	return CSize(m_field.m_Xcount*m_field.m_size+2, m_field.m_Ycount*m_field.m_size+2);
}

void CLifeDoc::OnUpdateIndicatorTime(CCmdUI *pCmdUI)
{
	CString strTmp;
	strTmp.Format("Time = %d", m_field.m_time);
	pCmdUI->Enable(TRUE);
	pCmdUI->SetText(strTmp);
}

void CLifeDoc::OnUpdateIndicatorBorn(CCmdUI *pCmdUI)
{
	CString strTmp;
	strTmp.Format("Born = %d", m_field.m_cntBorn);
	pCmdUI->Enable(TRUE);
	pCmdUI->SetText(strTmp);
}

void CLifeDoc::OnUpdateIndicatorDead(CCmdUI *pCmdUI)
{
	CString strTmp;
	strTmp.Format("Dead = %d", m_field.m_cntDead);
	pCmdUI->Enable(TRUE);
	pCmdUI->SetText(strTmp);
}

void CLifeDoc::OnUpdateIndicatorTotal(CCmdUI *pCmdUI)
{
	CString strTmp;
	strTmp.Format("Total = %d", m_field.m_cntLive + m_field.m_cntBorn);
	pCmdUI->Enable(TRUE);
	pCmdUI->SetText(strTmp);
}

BOOL CLifeDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	m_select = m_selected = m_timer = FALSE;
	m_redraw = TRUE;
	return TRUE;
}

// Field.cpp: implementation of the CField class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Life.h"
#include "Field.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_SERIAL (CField, CObject, 1)

CField::CField()
{
	srand( (unsigned)time(NULL) );
	SetDefault();
}

CField::~CField()
{

}

void CField::DrawGrid(CDC *pDC)
{
	CPen pen(PS_SOLID, 1, m_colorGrid);
	CPen *penOld = pDC->SelectObject(&pen);
	CPoint point[3];
	int maxX = m_Xcount * m_size, maxY = m_Ycount * m_size;
	if (m_grid){
		for (int x=0, nx=0; nx <= m_Xcount; x+=m_size, nx++){
			point[0].x = x;
			point[0].y = 0;
			point[1].x = x;
			point[1].y = maxY;
			pDC->Polyline(point, 2);
		}
		for (int y=0, ny=0; ny <= m_Ycount; y+=m_size, ny++){
			point[0].x = 0;
			point[0].y = y;
			point[1].x = maxX;
			point[1].y = y;
			pDC->Polyline(point, 2);
		}
	}
	point[0].x = 0;
	point[0].y = maxY;
	point[1].x = maxX;
	point[1].y = maxY;
	point[2].x = maxX;
	point[2].y = 0;
	pDC->Polyline(point, 3);
	pDC->SelectObject(penOld);
}

void CField::FillArr(CRect cells, char temp)
{
	int xa = GetMin(cells.left, cells.right);
	int xb = GetMax(cells.left, cells.right);
	int ya = GetMin(cells.top, cells.bottom);
	int yb = GetMax(cells.top, cells.bottom);
	for (int a = xa; a < xb; a++)
		for (int b = ya; b < yb; b++){
			m_arr[a][b] = temp;
			m_arrOld[a][b] = F_NONE;
		}
}

void CField::FillArrRandom(CRect cells)
{
	int xa = GetMin(cells.left, cells.right);
	int xb = GetMax(cells.left, cells.right);
	int ya = GetMin(cells.top, cells.bottom);
	int yb = GetMax(cells.top, cells.bottom);
	for (int a = xa; a < xb; a++)
		for (int b = ya; b < yb; b++){
			m_arr[a][b] = rand() % 4;
			m_arrOld[a][b] = F_NONE;
		}
}

void CField::DrawArr(CDC *pDC)
{
	m_cntLive = m_cntBorn = m_cntDead = 0;
	CPen *pen, *penOld;
	CBrush *brush, *brushOld;

	pen = new CPen(PS_SOLID, 1, m_colorVoid);
	brush = new CBrush(m_colorVoid);
	penOld = pDC->SelectObject(pen);
	brushOld = pDC->SelectObject(brush);
	for (int x=0, nx=0; nx < m_Xcount; x+=m_size, nx++)
		for (int y=0, ny=0; ny < m_Ycount; y+=m_size, ny++){
			if (m_arr[nx][ny] == F_VOID){
				if (m_arr[nx][ny] != m_arrOld[nx][ny]) pDC->Rectangle(x+1, y+1, x+m_size, y+m_size);
//					if (m_rect) pDC->Rectangle(x+1, y+1, x+m_size, y+m_size);
//					else pDC->Ellipse(x+1, y+1, x+m_size, y+m_size);
			}
		}
	pDC->SelectObject(brushOld);
	pDC->SelectObject(penOld);
	delete pen;
	delete brush;

	pen = new CPen(PS_SOLID, 1, m_colorDead);
	brush = new CBrush(m_colorDead);
	penOld = pDC->SelectObject(pen);
	brushOld = pDC->SelectObject(brush);
	for (x=0, nx=0; nx < m_Xcount; x+=m_size, nx++)
		for (int y=0, ny=0; ny < m_Ycount; y+=m_size, ny++){
			if (m_arr[nx][ny] == F_DEAD){
				m_cntDead++;
				if (m_arr[nx][ny] != m_arrOld[nx][ny]){
					if (m_rect) pDC->Rectangle(x+1, y+1, x+m_size, y+m_size);
					else pDC->Ellipse(x+1, y+1, x+m_size, y+m_size);
				}
			}
		}
	pDC->SelectObject(brushOld);
	pDC->SelectObject(penOld);
	delete pen;
	delete brush;

	pen = new CPen(PS_SOLID, 1, m_colorBorn);
	brush = new CBrush(m_colorBorn);
	penOld = pDC->SelectObject(pen);
	brushOld = pDC->SelectObject(brush);
	for (x=0, nx=0; nx < m_Xcount; x+=m_size, nx++)
		for (int y=0, ny=0; ny < m_Ycount; y+=m_size, ny++){
			if (m_arr[nx][ny] == F_BORN){
				m_cntBorn++;
				if (m_arr[nx][ny] != m_arrOld[nx][ny]){
					if (m_rect) pDC->Rectangle(x+1, y+1, x+m_size, y+m_size);
					else pDC->Ellipse(x+1, y+1, x+m_size, y+m_size);
				}
			}
		}
	pDC->SelectObject(brushOld);
	pDC->SelectObject(penOld);
	delete pen;
	delete brush;

	pen = new CPen(PS_SOLID, 1, m_colorLive);
	brush = new CBrush(m_colorLive);
	penOld = pDC->SelectObject(pen);
	brushOld = pDC->SelectObject(brush);
	for (x=0, nx=0; nx < m_Xcount; x+=m_size, nx++)
		for (int y=0, ny=0; ny < m_Ycount; y+=m_size, ny++){
			if (m_arr[nx][ny] == F_LIVE){
				m_cntLive++;
				if (m_arr[nx][ny] != m_arrOld[nx][ny]){
					if (m_rect) pDC->Rectangle(x+1, y+1, x+m_size, y+m_size);
					else pDC->Ellipse(x+1, y+1, x+m_size, y+m_size);
				}
			}
		}
	pDC->SelectObject(brushOld);
	pDC->SelectObject(penOld);
	delete pen;
	delete brush;
}

void CField::DrawFull(CDC *pDC)
{
	m_cntLive = m_cntBorn = m_cntDead = 0;
	CPen *pen, *penOld;
	CBrush *brush, *brushOld;

	pen = new CPen(PS_SOLID, 1, m_colorVoid);
	brush = new CBrush(m_colorVoid);
	penOld = pDC->SelectObject(pen);
	brushOld = pDC->SelectObject(brush);

	pDC->Rectangle(0, 0, m_Xcount * m_size, m_Ycount * m_size);

	pDC->SelectObject(brushOld);
	pDC->SelectObject(penOld);
	delete pen;
	delete brush;

	DrawGrid(pDC);

	pen = new CPen(PS_SOLID, 1, m_colorDead);
	brush = new CBrush(m_colorDead);
	penOld = pDC->SelectObject(pen);
	brushOld = pDC->SelectObject(brush);
	for (int x=0, nx=0; nx < m_Xcount; x+=m_size, nx++)
		for (int y=0, ny=0; ny < m_Ycount; y+=m_size, ny++){
			if (m_arr[nx][ny] == F_DEAD){
				m_cntDead++;
//				if (m_arr[nx][ny] != m_arrOld[nx][ny]){
					if (m_rect) pDC->Rectangle(x+1, y+1, x+m_size, y+m_size);
					else pDC->Ellipse(x+1, y+1, x+m_size, y+m_size);
//				}
			}
		}
	pDC->SelectObject(brushOld);
	pDC->SelectObject(penOld);
	delete pen;
	delete brush;

	pen = new CPen(PS_SOLID, 1, m_colorBorn);
	brush = new CBrush(m_colorBorn);
	penOld = pDC->SelectObject(pen);
	brushOld = pDC->SelectObject(brush);
	for (x=0, nx=0; nx < m_Xcount; x+=m_size, nx++)
		for (int y=0, ny=0; ny < m_Ycount; y+=m_size, ny++){
			if (m_arr[nx][ny] == F_BORN){
				m_cntBorn++;
				if (m_arr[nx][ny] != m_arrOld[nx][ny]){
					if (m_rect) pDC->Rectangle(x+1, y+1, x+m_size, y+m_size);
					else pDC->Ellipse(x+1, y+1, x+m_size, y+m_size);
				}
			}
		}
	pDC->SelectObject(brushOld);
	pDC->SelectObject(penOld);
	delete pen;
	delete brush;

	pen = new CPen(PS_SOLID, 1, m_colorLive);
	brush = new CBrush(m_colorLive);
	penOld = pDC->SelectObject(pen);
	brushOld = pDC->SelectObject(brush);
	for (x=0, nx=0; nx < m_Xcount; x+=m_size, nx++)
		for (int y=0, ny=0; ny < m_Ycount; y+=m_size, ny++){
			if (m_arr[nx][ny] == F_LIVE){
				m_cntLive++;
//				if (m_arr[nx][ny] != m_arrOld[nx][ny]){
					if (m_rect) pDC->Rectangle(x+1, y+1, x+m_size, y+m_size);
					else pDC->Ellipse(x+1, y+1, x+m_size, y+m_size);
//				}
			}
		}
	pDC->SelectObject(brushOld);
	pDC->SelectObject(penOld);
	delete pen;
	delete brush;
}
/*
BOOL CField::PutArr(int x, int y, char temp)
{
	if ((x < 1) || (x >= m_Xcount-1) || (y < 1) || (y >= m_Ycount-1)) return FALSE;
	m_arr[x][y] = temp;
	m_arrOld[x][y] = F_NONE;
	return TRUE;
}
*/
BOOL CField::PutArr(int x, int y, char temp)
{
	if ((x < 0) || (x >= m_Xcount) || (y < 0) || (y >= m_Ycount)) return FALSE;
	m_arr[x][y] = temp;
	m_arrOld[x][y] = F_NONE;
	return TRUE;
}

void CField::FillArrRect(CPoint cellsFrom, CRect cellsTo, BOOL copy)
{
	int dx = cellsFrom.x - cellsTo.left;
	int dy = cellsFrom.y - cellsTo.top;
	int xa = GetMin(cellsTo.left, cellsTo.right);
	int xb = GetMax(cellsTo.left, cellsTo.right);
	int ya = GetMin(cellsTo.top, cellsTo.bottom);
	int yb = GetMax(cellsTo.top, cellsTo.bottom);
	char arr[ARR_SIZE][ARR_SIZE];
	for (int x = xa; x < xb; x++)
		for (int y = ya; y < yb; y++){
			arr[x][y] = GetArr(x + dx, y + dy);
		}
	if (!copy){
		for (int x = xa; x < xb; x++)
			for (int y = ya; y < yb; y++){
				PutArr(x + dx, y + dy, F_VOID);
			}
	}
	for (x = xa; x < xb; x++)
		for (int y = ya; y < yb; y++){
			PutArr(x, y, arr[x][y]);
		}
}

void CField::FlipArrH(CRect cells)
{
	int xa = GetMin(cells.left, cells.right);
	int xb = GetMax(cells.left, cells.right);
	int ya = GetMin(cells.top, cells.bottom);
	int yb = GetMax(cells.top, cells.bottom);
	char arr[ARR_SIZE][ARR_SIZE];
	for (int a = xa; a < xb; a++)
		for (int b = ya; b < yb; b++){
			arr[a][b] = GetArr(a, b);
		}
	for (a = xa; a < xb; a++)
		for (int b = ya; b < yb; b++){
			PutArr(a, b, arr[xb + xa - a - 1][b]);
		}
}

void CField::FlipArrV(CRect cells)
{
	int xa = GetMin(cells.left, cells.right);
	int xb = GetMax(cells.left, cells.right);
	int ya = GetMin(cells.top, cells.bottom);
	int yb = GetMax(cells.top, cells.bottom);
	char arr[ARR_SIZE][ARR_SIZE];
	for (int a = xa; a < xb; a++)
		for (int b = ya; b < yb; b++){
			arr[a][b] = GetArr(a, b);
		}
	for (a = xa; a < xb; a++)
		for (int b = ya; b < yb; b++){
			PutArr(a, b, arr[a][yb + ya - b - 1]);
		}
}

char CField::GetArr(int x, int y)
{
	if ((x < 0) || (x >= m_Xcount) || (y < 0) || (y >= m_Ycount)) return F_NONE;
	return m_arr[x][y];
}

void CField::Serialize(CArchive &ar)
{
	CObject::Serialize(ar);
	long hdrSign;
	short hdrVer;
	if (ar.IsStoring()){
//		ar << (long)HDR_SIGN << (short)HDR_VER << hdrEmpty << m_grid << m_rect << m_trace << m_autoStop << m_Xcount << m_Ycount << m_size << m_interval << m_step << m_colorGrid << m_colorVoid << m_colorDead << m_colorBorn << m_colorLive;
		ar << (long)HDR_SIGN << (short)HDR_VER << m_paintBG << m_grid << m_rect << m_trace << m_torus << m_Xcount << m_Ycount << m_size << m_interval << m_step << m_colorGrid << m_colorVoid << m_colorDead << m_colorBorn << m_colorLive;
		for (int x = 0; x < m_Xcount; x++)
			for (int y = 0; y < m_Ycount; y++) ar << m_arr[x][y];
		ar << m_comment;
	}
	else{
		ar >> hdrSign;
		if (hdrSign != HDR_SIGN) AfxMessageBox("Invalid file header", MB_ICONERROR | MB_OK);
		else{
			ar >> hdrVer >> m_paintBG >> m_grid >> m_rect >> m_trace >> m_torus >> m_Xcount >> m_Ycount >> m_size >> m_interval >> m_step >> m_colorGrid >> m_colorVoid >> m_colorDead >> m_colorBorn >> m_colorLive;
			FillArr(CRect(0, 0, ARR_SIZE, ARR_SIZE), F_VOID);
			for (int x = 0; x < m_Xcount; x++)
				for (int y = 0; y < m_Ycount; y++) ar >> m_arr[x][y];
			if (hdrVer == HDR_VER) ar >> m_comment;
		}
	}
}
/*
void CField::Go(CDC *pDC)
{
	for (int a = 1; a <= m_step; a++){

	for (int x = 0; x < m_Xcount; x++)
		for (int y = 0; y < m_Ycount; y++){
			m_arrOld[x][y] = m_arr[x][y];
			switch (m_arr[x][y]){
				case F_BORN: m_arr[x][y] = F_LIVE; break;
				case F_DEAD: if (!m_trace) m_arr[x][y] = F_VOID;
			}
		}
	for (x = 1; x < m_Xcount-1; x++)
		for (int y = 1; y < m_Ycount-1; y++){
			if (m_arrOld[x][y] >= F_BORN){
				int n = GetNeighbours(x, y);
				if ((n < 2) || (n > 3)) m_arr[x][y] = F_DEAD;
			}
		}
	for (x = 1; x < m_Xcount-1; x++)
		for (int y = 1; y < m_Ycount-1; y++){
			if (m_arrOld[x][y] <= F_DEAD)
				if (GetNeighbours(x, y) == 3) m_arr[x][y] = F_BORN;
		}
	m_time++;

	}
	if (m_step == 1) DrawArr(pDC);
	else DrawFull(pDC);
}

int CField::GetNeighbours(int x, int y)
{
	int cnt = 0;
	if ((m_arrOld[x-1][y-1] == F_LIVE) || (m_arrOld[x-1][y-1] == F_BORN)) cnt++;
	if ((m_arrOld[x][y-1] == F_LIVE) || (m_arrOld[x][y-1] == F_BORN)) cnt++;
	if ((m_arrOld[x+1][y-1] == F_LIVE) || (m_arrOld[x+1][y-1] == F_BORN)) cnt++;
	if ((m_arrOld[x-1][y] == F_LIVE) || (m_arrOld[x-1][y] == F_BORN)) cnt++;
	if ((m_arrOld[x+1][y] == F_LIVE) || (m_arrOld[x+1][y] == F_BORN)) cnt++;
	if ((m_arrOld[x-1][y+1] == F_LIVE) || (m_arrOld[x-1][y+1] == F_BORN)) cnt++;
	if ((m_arrOld[x][y+1] == F_LIVE) || (m_arrOld[x][y+1] == F_BORN)) cnt++;
	if ((m_arrOld[x+1][y+1] == F_LIVE) || (m_arrOld[x+1][y+1] == F_BORN)) cnt++;
	return cnt;
}
*/
void CField::Go(CDC *pDC)
{
	for (int a = 1; a <= m_step; a++){

	for (int x = 0; x < m_Xcount; x++)
		for (int y = 0; y < m_Ycount; y++){
			m_arrOld[x][y] = m_arr[x][y];
			switch (m_arr[x][y]){
				case F_BORN: m_arr[x][y] = F_LIVE; break;
				case F_DEAD: if (!m_trace) m_arr[x][y] = F_VOID;
			}
		}
	for (x = 0; x < m_Xcount; x++)
		for (int y = 0; y < m_Ycount; y++){
			if (m_arrOld[x][y] >= F_BORN){
				int n = GetNeighbours(x, y);
				if ((n < 2) || (n > 3)) m_arr[x][y] = F_DEAD;
			}
		}
	for (x = 0; x < m_Xcount; x++)
		for (int y = 0; y < m_Ycount; y++){
			if (m_arrOld[x][y] <= F_DEAD)
				if (GetNeighbours(x, y) == 3) m_arr[x][y] = F_BORN;
		}
	m_time++;

	}
	if (m_step == 1) DrawArr(pDC);
	else DrawFull(pDC);
}

int CField::GetNeighbours(int x, int y)
{
	if (m_torus) return GetNeighboursTorus(x, y);
	else return GetNeighboursRect(x, y);
}

int CField::GetNeighboursRect(int x, int y)
{
	if ((x == 0) && (x == m_Xcount - 1) && (y == 0) && (y == m_Ycount - 1)) return 0;
	int cnt = 0;
	if ((m_arrOld[x-1][y-1] == F_LIVE) || (m_arrOld[x-1][y-1] == F_BORN)) cnt++;
	if ((m_arrOld[x][y-1] == F_LIVE) || (m_arrOld[x][y-1] == F_BORN)) cnt++;
	if ((m_arrOld[x+1][y-1] == F_LIVE) || (m_arrOld[x+1][y-1] == F_BORN)) cnt++;
	if ((m_arrOld[x-1][y] == F_LIVE) || (m_arrOld[x-1][y] == F_BORN)) cnt++;
	if ((m_arrOld[x+1][y] == F_LIVE) || (m_arrOld[x+1][y] == F_BORN)) cnt++;
	if ((m_arrOld[x-1][y+1] == F_LIVE) || (m_arrOld[x-1][y+1] == F_BORN)) cnt++;
	if ((m_arrOld[x][y+1] == F_LIVE) || (m_arrOld[x][y+1] == F_BORN)) cnt++;
	if ((m_arrOld[x+1][y+1] == F_LIVE) || (m_arrOld[x+1][y+1] == F_BORN)) cnt++;
	return cnt;
}

int CField::GetNeighboursTorus(int x, int y)
{
	int cnt = 0;
	CRect NewPos(x-1, y-1, x+1, y+1);
	if (x == 0) NewPos.left = m_Xcount - 1;
	if (x == m_Xcount - 1) NewPos.right = 0;
	if (y == 0) NewPos.top = m_Ycount - 1;
	if (y == m_Ycount - 1) NewPos.bottom = 0;
	if ((m_arrOld[NewPos.left][NewPos.top] == F_LIVE)     || (m_arrOld[NewPos.left][NewPos.top] == F_BORN)) cnt++;
	if ((m_arrOld[x][NewPos.top] == F_LIVE)               || (m_arrOld[x][NewPos.top] == F_BORN)) cnt++;
	if ((m_arrOld[NewPos.right][NewPos.top] == F_LIVE)    || (m_arrOld[NewPos.right][NewPos.top] == F_BORN)) cnt++;
	if ((m_arrOld[NewPos.left][y] == F_LIVE)              || (m_arrOld[NewPos.left][y] == F_BORN)) cnt++;
	if ((m_arrOld[NewPos.right][y] == F_LIVE)             || (m_arrOld[NewPos.right][y] == F_BORN)) cnt++;
	if ((m_arrOld[NewPos.left][NewPos.bottom] == F_LIVE)  || (m_arrOld[NewPos.left][NewPos.bottom] == F_BORN)) cnt++;
	if ((m_arrOld[x][NewPos.bottom] == F_LIVE)            || (m_arrOld[x][NewPos.bottom] == F_BORN)) cnt++;
	if ((m_arrOld[NewPos.right][NewPos.bottom] == F_LIVE) || (m_arrOld[NewPos.right][NewPos.bottom] == F_BORN)) cnt++;
	return cnt;
}

void CField::SetDefault(BOOL all)
{
	m_time = 0;
	m_paintBG = FALSE;
	m_grid = TRUE;
	m_rect = TRUE;
	m_trace = FALSE;
	m_torus = TRUE;
	if (m_Xcount < 100) m_Xcount = 100;
	if (m_Ycount < 60) m_Ycount = 60;
	m_size = 10;
	m_interval = 100;
	m_step = 1;
	m_colorGrid = RGB(0xEE, 0xEE, 0xEE);
	m_colorVoid = RGB(255, 255, 255);
	m_colorDead = RGB(255, 255, 0xDD);
	m_colorBorn = RGB(0, 0xAA, 255);
	m_colorLive = RGB(0, 0, 255);
	if (all){
		m_comment = "";
		m_Xcount = 100;
		m_Ycount = 60;
		FillArr(CRect(0, 0, ARR_SIZE, ARR_SIZE), F_VOID);
	}
}

int CField::GetMin(int a, int b)
{
	return a < b ? a : b;
}

int CField::GetMax(int a, int b)
{
	return a > b ? a : b;
}

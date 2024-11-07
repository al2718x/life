// Field.h: interface for the CField class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FIELD_H__04B7AB01_4396_4A27_BFF2_25DEA4B10B6B__INCLUDED_)
#define AFX_FIELD_H__04B7AB01_4396_4A27_BFF2_25DEA4B10B6B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

const
	ARR_SIZE = 500,
	F_NONE = -1,
	F_VOID = 0,
	F_DEAD = 1,
	F_BORN = 2,
	F_LIVE = 3,
	HDR_SIGN = 0x4546494C,
	HDR_VER = 0x0101;

class CField : public CObject  
{
	DECLARE_SERIAL (CField)
public:
	long m_time;
	int m_cntLive;
	int m_cntBorn;
	int m_cntDead;
	void SetDefault(BOOL all = TRUE);
	void Go(CDC *pDC);
	void Serialize(CArchive &ar);
	char GetArr(int x, int y);
	BOOL PutArr(int x, int y, char temp);
	void FillArr(CRect cells, char temp);
	void FillArrRandom(CRect cells);
	void FillArrRect(CPoint cellsFrom, CRect cellsTo, BOOL copy);
	void FlipArrH(CRect cells);
	void FlipArrV(CRect cells);
	void DrawGrid(CDC *pDC);
	void DrawArr(CDC *pDC);
	void DrawFull(CDC *pDC);
	BOOL m_paintBG;
	BOOL m_grid;
	BOOL m_rect;
	BOOL m_trace;
	BOOL m_torus;
	int m_Xcount;
	int m_Ycount;
	int m_size;
	int m_interval;
	int m_step;
	COLORREF m_colorGrid;
	COLORREF m_colorVoid;
	COLORREF m_colorDead;
	COLORREF m_colorBorn;
	COLORREF m_colorLive;
	CString m_comment;
	CField();
	virtual ~CField();
private:
	int GetMin(int a, int b);
	int GetMax(int a, int b);
	char m_arr[ARR_SIZE][ARR_SIZE];
	char m_arrOld[ARR_SIZE][ARR_SIZE];
	int GetNeighbours(int x, int y);
	int GetNeighboursRect(int x, int y);
	int GetNeighboursTorus(int x, int y);
//	void DrawCell(CDC *pDC, int x, int y);

};

#endif // !defined(AFX_FIELD_H__04B7AB01_4396_4A27_BFF2_25DEA4B10B6B__INCLUDED_)

// Life.h : main header file for the LIFE application
//

#if !defined(AFX_LIFE_H__53594E1C_227B_4FA6_981E_1EE290A41DB9__INCLUDED_)
#define AFX_LIFE_H__53594E1C_227B_4FA6_981E_1EE290A41DB9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLifeApp:
// See Life.cpp for the implementation of this class
//

class CLifeApp : public CWinApp
{
public:
	CLifeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLifeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CLifeApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIFE_H__53594E1C_227B_4FA6_981E_1EE290A41DB9__INCLUDED_)

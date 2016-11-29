// calculation.h : main header file for the CALCULATION application
//

#if !defined(AFX_CALCULATION_H__3E79CDC4_4C2B_4631_9406_50D4208B284E__INCLUDED_)
#define AFX_CALCULATION_H__3E79CDC4_4C2B_4631_9406_50D4208B284E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCalculationApp:
// See calculation.cpp for the implementation of this class
//

class CCalculationApp : public CWinApp
{
public:
	CCalculationApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalculationApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCalculationApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALCULATION_H__3E79CDC4_4C2B_4631_9406_50D4208B284E__INCLUDED_)

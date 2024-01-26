
// Shapes V.7.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CShapesV7App:
// See Shapes V.7.cpp for the implementation of this class
//

class CShapesV7App : public CWinApp
{
public:
	CShapesV7App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CShapesV7App theApp;

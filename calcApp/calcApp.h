
// calcApp.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CcalcAppApp: 
// 有关此类的实现，请参阅 calcApp.cpp
//

class CcalcAppApp : public CWinApp
{
public:
	CcalcAppApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CcalcAppApp theApp;
extern double _array1, _array2, _result, _memory;
extern int _operator;
extern bool _gotArray2, needClear;
extern CFont m_Font;
extern CEdit* pBox1;

// calcApp.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CcalcAppApp: 
// �йش����ʵ�֣������ calcApp.cpp
//

class CcalcAppApp : public CWinApp
{
public:
	CcalcAppApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CcalcAppApp theApp;
extern double _array1, _array2, _result, _memory;
extern int _operator;
extern bool _gotArray2, needClear;
extern CFont m_Font;
extern CEdit* pBox1;
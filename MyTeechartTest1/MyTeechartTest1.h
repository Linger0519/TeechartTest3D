
// MyTeechartTest1.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMyTeechartTest1App:
// �йش����ʵ�֣������ MyTeechartTest1.cpp
//

class CMyTeechartTest1App : public CWinApp
{
public:
	CMyTeechartTest1App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMyTeechartTest1App theApp;
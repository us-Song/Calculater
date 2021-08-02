
#pragma once
#ifndef _CONTROLLER
#define _CONTROLLER
#include <afxdialogex.h>
#include "Model.h"
#endif


class controller : public CDialogEx
{
	Model* model;

public:
	int Calc(int first, enum FourOP op, int second);
	CString parse(CString str);
	BOOL Key(MSG* pMsg, CString m_EDitDisplay, CString m_subd);
	CString eraser(CString str, enum FourOP op);
};
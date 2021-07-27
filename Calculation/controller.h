
#pragma once
#ifndef _CONTROLLER
#define _CONTROLLER
#include <afxdialogex.h>
#endif


class controller : public CDialogEx
{
public:
	int Calc(int first, enum FourOP op, int second);


};
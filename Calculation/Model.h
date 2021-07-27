
#pragma once
#ifndef _CONTROLLER
#define _CONTROLLER
#include <afxdialogex.h>
#endif

enum FourOP
{
	PLUS = 1001,
	MINUS,
	MULTIPLY,
	DIVIDE,
	NONE
};

class Model : public CDialogEx
{
public:
	enum FourOP m_selectedOP;//����ڰ� ��Ģ ������ ������ �����ߴ����� ����
	int m_nFirstOperand;// ����� ���� �Է��� ù ��° �� �����ڸ� ����
	int m_nSecondOperand;// �� ��° �� �����ڸ� ����
	int m_nResult;// ��� ����� ����


};
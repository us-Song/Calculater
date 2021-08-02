
#pragma once
#ifndef _MODEL
#define _MODEL
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
	Model();
	enum FourOP m_selectedOP;//����ڰ� ��Ģ ������ ������ �����ߴ����� ����
	int m_nFirstOperand;// ����� ���� �Է��� ù ��° �� �����ڸ� ����
	int m_nSecondOperand;// �� ��° �� �����ڸ� ����
	int m_nResult;// ��� ����� ����
	char buf[256];

};
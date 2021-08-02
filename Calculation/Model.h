
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
	enum FourOP m_selectedOP;//사용자가 사칙 연산중 무엇을 선택했는지를 저장
	int m_nFirstOperand;// 계산을 위해 입력한 첫 번째 피 연산자를 저장
	int m_nSecondOperand;// 두 번째 피 연산자를 지정
	int m_nResult;// 계산 결과를 저장
	char buf[256];

};
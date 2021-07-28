
#include "pch.h"
#include "framework.h"
#include "Calculation.h"
#include "CalculationDlg.h"
#include "afxdialogex.h"
#include <string>
#include "controller.h"
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int controller::Calc(int first, enum FourOP op, int second)
{
	int result;

	switch (op) {
	case PLUS:
		result = first + second;
		return result;
	case MINUS:
		result = first - second;
		return result;

	case MULTIPLY:
		result = first * second;
		return result;

	case DIVIDE:
		result =first / second;
		return result;

	}
}

CString controller::parse(CString str)
{
	CString str1, str2;
	int idx;
	enum FourOP op;

	if (str.Find('+') != -1)
	{
		AfxExtractSubString(str1, str, 0, '+');
		AfxExtractSubString(str2, str, 1, '+');
		op = PLUS;
	}
	else if (str.Find('-') != -1)
	{
		AfxExtractSubString(str1, str, 0, '-');
		AfxExtractSubString(str2, str, 1, '-');
		op = MINUS;
	}
	else if (str.Find('*') != -1)
	{
		AfxExtractSubString(str1, str, 0, '*');
		AfxExtractSubString(str2, str, 1, '*');
		op = MULTIPLY;
	}
	else if (str.Find('/') != -1)
	{
		AfxExtractSubString(str1, str, 0, '/');
		AfxExtractSubString(str2, str, 1, '/');
		op = DIVIDE;
	}

	int result=Calc(_ttoi(str1), op, _ttoi(str2));
	CString Cresult;
	Cresult.Format(_T("%d"), result);
	return Cresult;
}
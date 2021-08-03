
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

int controller::Calc(int first, enum FourOP op, int second)//���
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

CString controller::parse(CString str)//�Ľ�
{
	CString str1, str2;
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
	else
	{
		controller cont;
		CCalculationDlg one;
		
		MessageBox(_T("�ٽ� �Է��ϼ���"), _T("error"), MB_OK);
		
		return (CString)' ';
	}

	if (!(str2>=(CString)'0'&&str2<= (CString)'9'))
	{
		MessageBox(_T("�ٽ� �Է��ϼ���"), _T("error"), MB_OK);

		return (CString)' ';
	}
	
	int result=Calc(_ttoi(str1), op, _ttoi(str2));
	CString Cresult;
	Cresult.Format(_T("%d"), result);

	return Cresult;
}

CString controller::eraser(CString subd, enum FourOP op)//�����
{

	if (sizeof(subd))// ���ڰ� �Էµ������� ����
	{
		int ret = 0;
		if (op == PLUS)//�����ڰ� +�� 
		{
			ret = subd.Find('+');//+�� �ε��� ��ȯ
		}
		else if (op == MINUS)
		{
			ret = subd.Find('-');
		}
		else if (op == MULTIPLY)
		{
			ret = subd.Find('*');
		}
		else if (op == DIVIDE)
		{
			ret = subd.Find('/');
		}

		subd.Delete(ret + 1, 10);//������ �� ����

	}

	return subd;

}

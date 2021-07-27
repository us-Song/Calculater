
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



#include "pch.h"
#include "framework.h"
#include "Calculation.h"
#include "CalculationDlg.h"
#include "afxdialogex.h"
#include <string>
#include "Model.h"
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

Model::Model()
{
	m_selectedOP = NONE;
	m_nFirstOperand = 0;
	m_nSecondOperand = 0;
}
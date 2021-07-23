﻿
// CalculationDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Calculation.h"
#include "CalculationDlg.h"
#include "afxdialogex.h"

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculationDlg 대화 상자



CCalculationDlg::CCalculationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATION_DIALOG, pParent)
	, m_EDitDisplay(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_EDitDisplay);
}

BEGIN_MESSAGE_MAP(CCalculationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CCalculationDlg::OnBnClickedOk)
	//ON_BN_CLICKED(IDC_BUTTON3, &CCalculationDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_divide, &CCalculationDlg::OnBnClickeddivide)
	ON_BN_CLICKED(IDC_erase, &CCalculationDlg::OnBnClickederase)
	ON_BN_CLICKED(IDC_minus, &CCalculationDlg::OnBnClickedminus)
	ON_BN_CLICKED(IDC_multiply, &CCalculationDlg::OnBnClickedmultiply)
	ON_BN_CLICKED(IDC_Num0, &CCalculationDlg::OnBnClickedNum0)
	ON_BN_CLICKED(IDC_Num1, &CCalculationDlg::OnBnClickedNum1)
	ON_BN_CLICKED(IDC_Num2, &CCalculationDlg::OnBnClickedNum2)
	ON_BN_CLICKED(IDC_Num3, &CCalculationDlg::OnBnClickedNum3)
	ON_BN_CLICKED(IDC_Num4, &CCalculationDlg::OnBnClickedNum4)
	ON_BN_CLICKED(IDC_Num5, &CCalculationDlg::OnBnClickedNum5)
	ON_BN_CLICKED(IDC_Num6, &CCalculationDlg::OnBnClickedNum6)
	ON_BN_CLICKED(IDC_Num7, &CCalculationDlg::OnBnClickedNum7)
	ON_BN_CLICKED(IDC_Num8, &CCalculationDlg::OnBnClickedNum8)
	ON_BN_CLICKED(IDC_Num9, &CCalculationDlg::OnBnClickedNum9)
	ON_BN_CLICKED(IDC_plus, &CCalculationDlg::OnBnClickedplus)
	ON_BN_CLICKED(IDC_result, &CCalculationDlg::OnBnClickedresult)
END_MESSAGE_MAP()


// CCalculationDlg 메시지 처리기

BOOL CCalculationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_selectedOP = NONE;
	m_nFirstOperand = 0;
	m_nSecondOperand = 0;
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CCalculationDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CCalculationDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CCalculationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculationDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}


void CCalculationDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalculationDlg::OnBnClickeddivide()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalculationDlg::OnBnClickederase()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalculationDlg::OnBnClickedminus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalculationDlg::OnBnClickedmultiply()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalculationDlg::OnBnClickedNum0()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;

	
}


void CCalculationDlg::OnBnClickedNum1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalculationDlg::OnBnClickedNum2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalculationDlg::OnBnClickedNum3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalculationDlg::OnBnClickedNum4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalculationDlg::OnBnClickedNum5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalculationDlg::OnBnClickedNum6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalculationDlg::OnBnClickedNum7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalculationDlg::OnBnClickedNum8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalculationDlg::OnBnClickedNum9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalculationDlg::OnBnClickedplus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalculationDlg::OnBnClickedresult()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

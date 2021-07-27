
// CalculationDlg.h: 헤더 파일
//

#pragma once
#include "Model.h"
/*enum FourOP
{
	PLUS = 1001,
	MINUS,
	MULTIPLY,
	DIVIDE,
	NONE
};*/
// CCalculationDlg 대화 상자
class CCalculationDlg : public CDialogEx
{
// 생성입니다.
public:
	
	CCalculationDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	//enum FourOP m_selectedOP;//사용자가 사칙 연산중 무엇을 선택했는지를 저장

	//int m_nFirstOperand;// 계산을 위해 입력한 첫 번째 피 연산자를 저장
	//int m_nSecondOperand;// 두 번째 피 연산자를 지정
	//int m_nResult;// 계산 결과를 저장
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton3();
	CString m_EDitDisplay;
	double c_temp;
	int flag;
	afx_msg void OnBnClickeddivide();
	afx_msg void OnBnClickederase();
	afx_msg void OnBnClickedminus();
	afx_msg void OnBnClickedmultiply();
	afx_msg void OnBnClickedNum0();
	afx_msg void OnBnClickedNum1();
	afx_msg void OnBnClickedNum2();
	afx_msg void OnBnClickedNum3();
	afx_msg void OnBnClickedNum4();
	afx_msg void OnBnClickedNum5();
	afx_msg void OnBnClickedNum6();
	afx_msg void OnBnClickedNum7();
	afx_msg void OnBnClickedNum8();
	afx_msg void OnBnClickedNum9();
	afx_msg void OnBnClickedplus();
	afx_msg void OnBnClickedresult();
	CString m_subd;
	afx_msg void OnBnClickedclear();
};

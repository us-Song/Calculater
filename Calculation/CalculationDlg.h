
// CalculationDlg.h: 헤더 파일
//

#pragma once
#include "Model.h"

// CCalculationDlg 대화 상자
class CCalculationDlg : public CDialogEx
{
// 생성입니다.
public:
	
	CCalculationDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	

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

private:
	CString m_subd;
	CString m_EDitDisplay;
	CString c_temp;
	
public:
	
	CEdit m_editdisplay;
	
	void set_subd(CString value);
	void set_Editd(CString value);
	void set_temp(CString value);
	
	CString get_subd();
	CString get_Editd();
	CString get_temp();
	
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton3();
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
	afx_msg void OnBnClickedclear();
	
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	

};

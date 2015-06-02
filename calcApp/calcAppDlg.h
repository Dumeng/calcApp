
// calcAppDlg.h : 头文件
//

#pragma once
#include "afxwin.h"

double getArray();
void keyPress(int num);

// CcalcAppDlg 对话框
class CcalcAppDlg : public CDialogEx
{
// 构造
public:
	CcalcAppDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CALCAPP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton CPowerButton;
	CButton CExtractButton;

	afx_msg void OnBnClickedequal();
	afx_msg void OnBnClicked1();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClicked7();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();
	afx_msg void OnBnClicked0();
	afx_msg void OnBnClickedc();
	afx_msg void OnBnClickedopposite();
	afx_msg void OnBnClickedplus();
	afx_msg void OnBnClickedminus();
	afx_msg void OnBnClickedmulti();
	afx_msg void OnBnClickeddivision();
	afx_msg void OnBnClickedbackspace();
	afx_msg void OnBnClickeddot();
};

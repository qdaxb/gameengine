// gameTestDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include <string>
#include "resource.h"
#include "gamecontroller.h"


// CgameTestDlg 对话框
class CgameTestDlg : public CDialog
{
// 构造
public:
	CgameTestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_GAMETEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnGameMessage(WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP()
public:
	void AddMessage(std::wstring message);
private:
	CEdit MutiEdit;
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
private:
	GameController m_oGameController;
public:
	afx_msg void OnBnClickedButton1();
	CEdit InputEdit;
};

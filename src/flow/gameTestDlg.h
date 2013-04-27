// gameTestDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include <string>
#include "resource.h"
#include "gamecontroller.h"


// CgameTestDlg �Ի���
class CgameTestDlg : public CDialog
{
// ����
public:
	CgameTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_GAMETEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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

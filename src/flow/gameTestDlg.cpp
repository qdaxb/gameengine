// gameTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "gameTest.h"
#include "gameTestDlg.h"
#include "GameDebugger.h"
#include "XMLImporter.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CgameTestDlg 对话框




CgameTestDlg::CgameTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CgameTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CgameTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, MutiEdit);
	DDX_Control(pDX, IDC_EDIT1, InputEdit);
}

BEGIN_MESSAGE_MAP(CgameTestDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_GameMessage,OnGameMessage)


	//}}AFX_MSG_MAP
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, &CgameTestDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CgameTestDlg 消息处理程序

BOOL CgameTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	TCHAR tchBuffer[MAX_PATH];
	LPWSTR curPath;
	curPath = tchBuffer;
	GetCurrentDirectory(MAX_PATH,curPath);

	XMLImporter* im=new XMLImporter(wcscat(curPath,_T("\\Debug\\test.xml"))); 
	XMLNode* node=new XMLNode();
	im->ImportXML(node);
	m_oGameController.NewGame(node);
	GameDebugger::Init(this);
	SetTimer(1,1500,NULL);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CgameTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

LRESULT CgameTestDlg::OnGameMessage( WPARAM wParam, LPARAM lParam )
{
m_oGameController.ProcMessage(wParam,lParam);
return 0;
}



//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CgameTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CgameTestDlg::AddMessage(std::wstring message)
{
	CString str;
	MutiEdit.GetWindowText(str);
	// this->MutiEdit.SetWindowText(str+((std::string("/n")+message)).c_str());
	this->MutiEdit.SetWindowText(str+CString("\r\n")+ CString(message.c_str()));

	this->MutiEdit.SetSel(MutiEdit.GetWindowTextLength()-1,MutiEdit.GetWindowTextLength()-1);
}

void CgameTestDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//this->m_oGameController.NextOperate();
	m_oGameController.NextOperate();
	CDialog::OnTimer(nIDEvent);
}

void CgameTestDlg::OnBnClickedButton1()
{
	CString str;
	InputEdit.GetWindowText(str);

	wchar_t szText[1024];
	wcscpy_s(szText,1024,str);
	str.ReleaseBuffer();
	PostMessage(WM_GameMessage,1,(UINT)szText);
}

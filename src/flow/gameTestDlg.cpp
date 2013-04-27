// gameTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "gameTest.h"
#include "gameTestDlg.h"
#include "GameDebugger.h"
#include "XMLImporter.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CgameTestDlg �Ի���




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


// CgameTestDlg ��Ϣ�������

BOOL CgameTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
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
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CgameTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
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



//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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

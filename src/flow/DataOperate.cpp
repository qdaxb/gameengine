#include "StdAfx.h"
#include "DataOperate.h"
#include "GameDebugger.h"
#include "Utils.h"
DataOperate::DataOperate(void)
{
}

DataOperate::~DataOperate(void)
{
}
int DataOperate::Execute(OperateAble* OperateAble)
{
	wstring exp=(GetVariable(_T("val"))->toString());
	if(exp.length()<0)
	{
		GameDebugger::OutPut(L"error!no var expression!");
		return 0;
	}
	GameDebugger::OutPut(_T("data operate!exp is:"));
	GameDebugger::OutPut(exp);
	const wchar_t* tbuffer=exp.c_str();
	char* buffer=UNICODEtoASCII(tbuffer);
	OperateAble->GetDataController()->RunExp(buffer);
	//delete[] tbuffer;
	//delete[] buffer;
	return 0;
}
void DataOperate::GetCommand()  //��ȡ�����ַ���
{
	this->command=((GetVariable(_T("val")))->toString());
}	

/*
void DataOperate::CutCommand()  //��������ַ���
{
	wstring tar(L"");			//tar Ҫ����ֵ����
	wstring value1(L"");
	wstring value2(L"");
	GameData* vp1;
	GameData* vp2;
	int i=command.find_first_of('=',0);
	if(i==-1)					//��������ַ����в�����'=',������Ϊ�Ӽ�����ʱ
		tar=command+L" is : ";  //��ʱ����Ϊ���������ַ���
	else
	{
		tar=command.substr(0,i);//��ֳ�Ҫ����ֵ���ַ���
		command=command.substr(i+1,command.length());//���µļ������
	}
		
	int m=command.find_first_of('+',0);
	int n=command.find_first_of('-',0);
	if(m!=-1)
	{
		value1=command.substr(0,m);
		value2=command.substr(m+1,command.length());
	}
	

	if(n!=-1)
	{
		value1=command.substr(0,n);
		value2=command.substr(n+1,command.length());
	}


}
*/
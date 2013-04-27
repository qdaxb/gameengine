#include "StdAfx.h"
#include "WaitForActionOperate.h"
#include "GameDebugger.h"
WaitForActionOperate::WaitForActionOperate(void)
{
}

WaitForActionOperate::~WaitForActionOperate(void)
{
}
int WaitForActionOperate::Execute(OperateAble* OperateAble)
{	
	GameDebugger::OutPut(_T("test event operate"));
	(OperateAble)->RegisterEvent(1,this);
	this->m_oOperateAble=OperateAble;
	this->m_bExecuteState=true;
	return 0;

}
int WaitForActionOperate::ProcEvent(WPARAM wParam,LPARAM lParam)
{
	wchar_t   szPack[1024];   
	memcpy(szPack,(wchar_t*)lParam,1024);
	IAction* action=((GameController*)this->m_oOperateAble)->GetActionFactory()->CreateAction(szPack);
	if(action==NULL)
	{
		GameDebugger::OutPut(L"error action code!");
		return 0;
	}
	this->m_oOperateAble->Push(action);
	this->m_oOperateAble->UnRegisterEvent(wParam,this);
	this->m_bExecuteState=false;
	return 1;
}
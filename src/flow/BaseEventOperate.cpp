
#include "stdafx.h"

#include "BaseEventOperate.h"
#include "OperateAble.h"
#include <string>
#include "GameDebugger.h"
#include "VariableOperate.h"
BaseEventOperate::BaseEventOperate(void)
: m_bExecuteState(false)
{
}

BaseEventOperate::~BaseEventOperate(void)
{
}
int BaseEventOperate::Execute(OperateAble* OperateAble)


{
	GameDebugger::OutPut(_T("test event operate"));
	(OperateAble)->RegisterEvent(1,this);
	this->m_oOperateAble=OperateAble;
	this->m_bExecuteState=true;
	return 0;
}
int BaseEventOperate::ProcEvent(WPARAM wParam,LPARAM lParam)
{
	wchar_t   szPack[1024];   
	lstrcpy(szPack,(wchar_t*)lParam);
	
	SetVariable(_T("testa"),new std::wstring(szPack));
	VariableOperate* v=new VariableOperate();
	v->SetSourceKey(_T("testa"));
	v->SetTargetKey(_T("test"));
	v->SetSourceNode(this);
	v->SetTargetNode(parent);
	m_oOperateAble->GetOperateStack().push(v);
	GameDebugger::OutPut((_T("test event fired!event message:"))+wstring(szPack));
 	this->m_oOperateAble->UnRegisterEvent(wParam,this);
	this->m_bExecuteState=false;
	return 1;
}

#include "stdafx.h"

#include "BaseOperate.h"
#include "OperateAble.h"
#include <string>
#include "GameDebugger.h"
#include "BaseVariable.h"
BaseOperate::BaseOperate(void)
{
}

BaseOperate::~BaseOperate(void)
{
}
int BaseOperate::Execute(OperateAble* OperateAble)
{
	
	GameDebugger::OutPut(_T("test operate"));
	std::wstring *s=&GetVariable(_T("test"))->toString();
	if(GetVariable(_T("test"))->toString().length()>=0)
		GameDebugger::OutPut(GetVariable((_T("test")))->toString());
	return 0;
}
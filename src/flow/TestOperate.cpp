#include "StdAfx.h"
#include "TestOperate.h"
#include "GameDebugger.h"
TestOperate::TestOperate(void)
{
}

TestOperate::~TestOperate(void)
{
}
int TestOperate::Execute(OperateAble* OperateAble)
{
	GameDebugger::OutPut(_T("TestAction!ActionVariable is:"));
	GameDebugger::OutPut(OperateAble->GetDataController()->GetData(((GameData*)OperateAble->GetDataController()->GetVariable(_T("val")))->toString())->toString());
	return 0;
}
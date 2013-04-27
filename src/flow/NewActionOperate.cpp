#include "StdAfx.h"
#include "NewActionOperate.h"
#include "GameController.h"
#include "Commondef.h"
#include "GameDebugger.h"
NewActionOperate::NewActionOperate(void)
{
}

NewActionOperate::~NewActionOperate(void)
{
}

int NewActionOperate::Execute(OperateAble* operateAble)
{
	//TODO �����ַ�������action��д��stack
	wstring command=GetVariable(L"command")->toString();
	const wchar_t* tmp=command.c_str();
	IAction* action=((GameController*) operateAble)->GetActionFactory()->CreateAction(tmp);
	delete[] tmp;
	if(action==NULL)
	{
		GameDebugger::OutPut(L"error action code!");
		return 0;
	}
	operateAble->Push(action);
	return RETURN_SUCCESS;
}
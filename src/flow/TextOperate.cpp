#include "StdAfx.h"
#include "TextOperate.h"
#include "GameDebugger.h"
TextOperate::TextOperate(void)
{
}

TextOperate::~TextOperate(void)
{
}
int TextOperate::Execute(OperateAble* OperateAble)
{
	GameDebugger::OutPut(_T("text:"));
	GameDebugger::OutPut((GetVariable(_T("val")))->toString());
	return 0;
}
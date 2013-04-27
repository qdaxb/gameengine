#include "StdAfx.h"
#include "IfOperate.h"
#include "OperateAble.h"
#include "GameDebugger.h"
#include "Utils.h"
extern GameData expData;
IfOperate::IfOperate(void)
{
}

IfOperate::~IfOperate(void)
{
}

int IfOperate::Execute(OperateAble* OperateAble)
{

	GameDebugger::OutPut(L"if operate");
	wstring str=this->GetVariable(L"test")->toString();
	if(str.length()>0)
	{
		GameDebugger::OutPut(L"expression:"+str);
		OperateAble->GetDataController()->RunExp(UNICODEtoASCII(str));
		if(expData.toFloat()==0)
		{
			GameDebugger::OutPut(L"false");
			return 0;
		}
		GameDebugger::OutPut(L"true");
	}
	
	list<IOperate*> opts=this->GetParent()->GetOperates();
	bool ifAfterTagFlag=true;
	list <IOperate*> ::iterator ifptr;
	int ifpos;
	int tagpos;
	int i=0;
	for(list <IOperate*> ::iterator iter= opts.begin();iter != opts.end();iter++)
	{
		if((*iter)->GetTag()==(this->GetVariable(L"goto")->toString()))
		{
			tagpos=i;
		}
		else if(*iter==this)
		{
			ifpos=i;
		}
		i++;
	}
	
	if(ifpos<tagpos)
	{
		
		for(i=0;i<tagpos-ifpos-1;i++)
		{
			OperateAble->GetOperateStack().pop();
		}
	}
	else
	{
		i=opts.size()-1;
		for(list<IOperate*>::reverse_iterator it=opts.rbegin();it!=opts.rend()&&i>=tagpos;it++,i--)
		{
			if(i<=ifpos)
			OperateAble->GetOperateStack().push(*it);
		}
	}
	return 1;
}
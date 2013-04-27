#include "StdAfx.h"
#include "OperateFactory.h"
#include "OperateStructure.h"
#include "BaseOperate.h"
#include "BaseEventOperate.h"
#include "TestOperate.h"
#include "XMLNode.h"
#include "VariableOperate.h"
#include "TestOperate.h"
#include "NewActionOperate.h"
#include "WaitForActionOperate.h"
#include "IfOperate.h"
#include "DataOperate.h"
#include "TextOperate.h"
OperateFactory::OperateFactory(void)
{
}

OperateFactory::~OperateFactory(void)
{
}

list<IOperate*> OperateFactory::CreateOperate(XMLNode* xmlNode,IAction* action)
{
	list<IOperate*> que;
	IOperate* opt=NULL;
	wstring type;
	xmlNode->GetValue(L"name",type);
	if(type==L"action")
	{
		NewActionOperate* nao=new NewActionOperate();
		que.push_front(nao);
	}
	//todo add type here
	else if (type==L"if")
	{
		que.push_front(new IfOperate());
		
	}
	else if (type==L"test")
	{
		TestOperate* t=new TestOperate();
		t->SetParent(action);
		que.push_front(t);
	}
	else if(type==L"wait")
	{
		WaitForActionOperate* w=new WaitForActionOperate();
		w->SetParent(action);
		que.push_front(w);
	}
	else if(type==L"data")   //增加DataOperate
	{
		DataOperate* d=new DataOperate();
		d->SetParent(action);
		que.push_front(d);
	}
	else if(type==L"text")   //增加TextOperate
	{
		TextOperate* d=new TextOperate();
		d->SetParent(action);
		que.push_front(d);
	}
	//设置attribute
	if(!que.empty())
	{
		map<wstring,wstring>* attr=xmlNode->GetAttributes();
		map<wstring,wstring>::iterator atit;
		for(atit=attr->begin();atit!=attr->end();atit++)
		{
			if(atit->first==L"tag")	
			{
				que.front()->SetTag(atit->second);
			}
			else
				que.front()->SetVariable(atit->first,(void*)(&(atit->second)));

		}
		//设置parent
		que.front()->SetParent(action);
	}
	

	//创建返回值opt
	list<XMLNode*> rtn;
	xmlNode->GetChild(L"return",(list<XMLNode*>&)rtn);
	list<XMLNode*> ::iterator   it; 
	for(it=rtn.begin();it!=rtn.end();it++) 
	{
		VariableOperate* vo=new VariableOperate();
		wstring str;
		(*it)->GetValue(L"source",str);
		vo->SetParent(action);
		vo->SetSourceKey(str);
		(*it)->GetValue(L"target",str);
		vo->SetTargetKey(str);
		vo->SetSourceNode(opt);
		vo->SetTargetNode(action);
		que.push_front(opt);
	}
	
	//queue<IOperate*>* qu=new queue<IOperate*>();
	//IOperate* 	opt=new TestOperate();
	//opt->SetParent(action);
	//qu->push((IOperate*)opt);
	//opt=new BaseOperate();
	//
	//qu->push((IOperate*)opt);
	//opt=new BaseOperate();

	//qu->push((IOperate*)opt);
	//opt=new BaseEventOperate();
	//opt->SetParent(action);
	//qu->push((IOperate*)opt);
	//opt=new BaseOperate();
	//
	//opt->SetVariable(_T("test"),new wstring(_T("testasdf")));
	//qu->push((IOperate*)opt);

	return que;
}

#include "StdAfx.h"
#include "ActionFactory.h"
#include "BaseAction.h"
#include "BaseOperate.h"
#include "IAction.h"
#include "OperateStructure.h"
ActionFactory::ActionFactory(void)
{
}

ActionFactory::~ActionFactory(void)
{
}

//list<IAction*>* ActionFactory::InitActions(void)
//{
//	list<IAction*>* nl=new list<IAction*>();
//	BaseAction* action=new BaseAction();
//	
//	
//
//	OperateStructure* o=new OperateStructure();
//		
//	action->GetOperateQueue().push_back(o);
//	action->SetName(_T("init"));
//	nl->push_back(action);
//	return nl;
//}
IAction* ActionFactory::CreateAction(const wchar_t* tmp)
{

		BaseAction* action=NULL;
	//拆分command
	int i=0,j=0;
	wstring command;
	command.append(tmp);
	list<wchar_t*> test;
	list<wstring> cmd;
	int len=command.length();

	if(len==0)
		cmd.push_back(L"");
	else
		while(i<len)
		{
			j=command.find(L" ",i);
			if(j==-1)
				j=command.length();
			cmd.push_back(command.substr(i,j-i));
			i=j+1;
		}

	//通过manager取action定义
	XMLNode* node=this->m_pActionManager->GetAction(cmd.front());
	//若查找到action
	if(node!=NULL)
	{
		//新建action
		action=new BaseAction();
		list<XMLNode*> opts;
		//设置action值
		map<wstring,wstring>* attribute=node->GetAttributes();
		list<wstring>::iterator itc=cmd.begin();
		for(++itc;itc!=cmd.end();itc++)
		{
			list<wstring>::iterator itctmp=itc;
			attribute->erase(*itctmp);
			attribute->insert(map<wstring,wstring>::value_type(*itctmp,*(++itc)));
		}
		map<wstring,wstring>::iterator ita;
		for(ita=attribute->begin();ita!=attribute->end();ita++)
		{
			action->SetVariable(ita->first,&(ita->second));
		}
		node->GetChild(opts);
		//对每一个子节点调用operatefactory的create方法,返回值增加到action中
		list<XMLNode*> :: reverse_iterator    it; 
		for(it=opts.rbegin();it!=opts.rend();it++) 
		{
			list<IOperate*> o=this->m_oOperateFactory->CreateOperate(*it,action);
			while(!o.empty())
			{
				action->GetOperateQueue().push(o.front());
				o.pop_front();
			}
		}

	}
	
	
	//todo 若类型为action,调用createfactory的create(action)operate

	//若未查找到

	return action;
}
/********************************************************************
	created:	2011/04/18 21:33
	filename: 	GameController
	file ext:	cpp
	author:		axb
	purpose:	游戏主控制类
*********************************************************************/
#include "StdAfx.h"
#include "GameController.h"
#include "BaseAction.h"
#include "ActionFactory.h"
#include "XMLNode.h"
extern DataController* dataController;
GameController::GameController(void)
{
	
	this->ExecutingOperate=NULL;
	m_oDataController=new DataController((OperateAble*)this);
	dataController=m_oDataController;
}

GameController::~GameController(void)
{
}

int GameController::NextOperate(void)
{
	IOperate* opt;

	if(this->ExecutingOperate!=NULL&&this->ExecutingOperate->isExecuting())
	{
		return 0;
	}
	
	if(!((this->m_oOperateStack).empty()))
	{
		IAction* parent=ExecutingOperate==NULL?NULL:ExecutingOperate->GetParent();
		opt=this->m_oOperateStack.top();
		this->ExecutingOperate=opt;
		this->ExecutingAction=opt->GetParent();
		this->m_oOperateStack.pop();
// 		if(opt->GetParent()!=parent&&parent!=NULL)
// 		{
// 			free(this->ExecutingAction);
// 		}

		opt->Execute((OperateAble*) this);
		return 1;
	}
	else
	{
		return -1;
	}
	
}

void GameController::NewGame(XMLNode* game)
{
	this->m_oActionFactory.SetActionManager(&m_oActionManager);
	this->m_oActionFactory.SetOperateFactory(&m_oOperateFactory);
	list<XMLNode*> actions;
	game->GetChild(L"actions",actions);
	m_oActionManager.InitAction(actions.front());
	IAction* gameInitAction=m_oActionFactory.CreateAction(L"InitAction");
	list<IOperate*> optQueue=gameInitAction->GetOperates();
	for(list <IOperate*> ::reverse_iterator iter= optQueue.rbegin();iter != optQueue.rend();iter++)
	
	{
		m_oOperateStack.push(*iter);

	}
	//list<IAction*>* actions=this->m_oActionFactory.InitActions();
	//list <IAction*> ::iterator   ite; 
	//for(ite=actions->begin();ite!=actions->end();ite++) 
	//{ 
	//	this->m_oActionManager.AddAction((IAction&)*(*ite));
	//}
	//
	//IAction* gameInitAction=this->m_oActionManager.CreateAction(_T("init"),NULL);
	//if(gameInitAction==NULL)
	//{
	//	return;
	//}
	//
	//list<OperateStructure*>& optQueue=gameInitAction->GetOperateQueue();
	//list <OperateStructure*> ::iterator   it; 
	//OperateStructure* operateStructure;
	//queue<IOperate*>* opt;
	//
	//for(it=optQueue.begin();it!=optQueue.end();it++)
	//{
	//	operateStructure=gameInitAction->GetOperateQueue().front();
	//	opt= m_oOperateFactory.CreateOperate(*operateStructure,gameInitAction);
	//	while(!opt->empty())
	//	{
	//		m_oOperateStack.push((IOperate*)opt->front());
	//		opt->pop();
	//	}
	//	
	//}
	

}
queue<IAction*>& GameController::GetActionQueue()
{
	return this->m_oActionQueue;
	
}
stack<IOperate*>& GameController::GetOperateStack(){
	return this->m_oOperateStack;
}

void GameController::ProcMessage(WPARAM wPrarm,LPARAM lPrarm)
{

	for(list <GameEvent*> ::iterator iter= m_lEventList.begin();iter != m_lEventList.end();++iter)
	{
		if(((*iter)->wparam)==wPrarm)
			(*iter)->opt->ProcEvent(wPrarm,lPrarm);
		if(m_lEventList.empty())
			break;
	}
}

void GameController::RegisterEvent(WPARAM eventType,BaseEventOperate* opt)
{
	GameEvent* eventPtr=(GameEvent*)malloc(sizeof(GameEvent));
	eventPtr->wparam=eventType;
	eventPtr->opt=opt;
	m_lEventList.push_back(eventPtr);
}
void GameController::UnRegisterEvent(WPARAM eventType,BaseEventOperate* opt)
{	
	for(list <GameEvent*> ::iterator iter= m_lEventList.begin();iter != m_lEventList.end();)
	{
		if(((*iter)->wparam)==eventType&&((*iter)->opt)==opt)
		{
			delete (*iter); 
			iter = m_lEventList.erase(iter); 
		}
		else
			iter++;
	}
}

void GameController::Push(IOperate* operate)
{
	this->m_oOperateStack.push(operate);
}
void GameController::Push(IAction* action)
{
	list<IOperate*> opts=action->GetOperates();
	list<IOperate*>::reverse_iterator it;
	for(it=opts.rbegin();it!=opts.rend();it++)
	{
		m_oOperateStack.push(*it);
	}
}
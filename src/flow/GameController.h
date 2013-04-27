/********************************************************************
	created:	2011/05/01 17:17
	filename: 	GameController
	file ext:	h
	author:		axb
	purpose:	ÓÎÏ·¿ØÖÆÆ÷£¬¼Ì³Ð×ÔOperateAble
*********************************************************************/
#pragma once
#include <queue>
#include <stack>
#include <list>
#include "OperateAble.h"
#include "OperateFactory.h"
#include "ActionManager.h"
#include "ActionFactory.h"
#include "DataController.h"
using namespace std;

struct GameEvent{
	WPARAM wparam;
	BaseEventOperate* opt;
};
class XMLNode;
class IAction;
class IOperate;
class GameController:public OperateAble
{
public:
	GameController(void);
	~GameController(void);
private:
	queue<IAction*> m_oActionQueue;
	stack<IOperate*> m_oOperateStack;
	ActionFactory m_oActionFactory;
	ActionManager m_oActionManager;
	OperateFactory m_oOperateFactory;
	IOperate* ExecutingOperate;
	list<GameEvent*> m_lEventList;
	DataController* m_oDataController;
	IAction* ExecutingAction;
public:
	int NextOperate(void);
	void NewGame(XMLNode* game);
	virtual queue<IAction*>& GetActionQueue();
	virtual stack<IOperate*>& GetOperateStack();
	virtual void ProcMessage(WPARAM wPrarm,LPARAM lPrarm);
	virtual void RegisterEvent(WPARAM eventType,BaseEventOperate* opt);
	virtual void UnRegisterEvent(WPARAM eventType,BaseEventOperate* opt);
	virtual IOperate* GetExecutingOperate(){return ExecutingOperate;}
	virtual DataController* GetDataController(){return m_oDataController;}
	ActionManager* GetActionManager(){return &(this->m_oActionManager);}
	ActionFactory* GetActionFactory(){return &(this->m_oActionFactory);}
	OperateFactory* GetOperateFactory(){return &(this->m_oOperateFactory);}
	virtual void Push(IAction* action);
	virtual void Push(IOperate* operate);
};

/********************************************************************
	created:	2011/05/01 17:06
	filename: 	ActionFactory
	file ext:	h
	author:		axb
	purpose:	action导入类（未定）
*********************************************************************/
#pragma once
#include <list>
#include "IAction.h"
#include "OperateFactory.h"
#include "ActionManager.h"
class ActionFactory
{
public:
	ActionFactory(void);
	~ActionFactory(void);
	IAction* CreateAction(const wchar_t* command);
	void SetOperateFactory(OperateFactory* factory){this->m_oOperateFactory=factory;}
	void SetActionManager(ActionManager* manager){this->m_pActionManager=manager;}
private:
	OperateFactory* m_oOperateFactory;
	ActionManager* m_pActionManager;

};

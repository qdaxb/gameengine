/********************************************************************
	created:	2011/05/01 17:18
	filename: 	OperateAble
	file ext:	h
	author:		axb
	purpose:	Operate的执行环境接口
*********************************************************************/
#pragma once
#include <stack>
#include <queue>
#include "BaseEventOperate.h"
using namespace std;
class IOperate;
class IAction;
class DataController;
class OperateAble
{
public:
	OperateAble(void);
	~OperateAble(void);
	virtual stack<IOperate*>& GetOperateStack(void)=0;
	virtual queue<IAction*>& GetActionQueue(void)=0;
	virtual void RegisterEvent(WPARAM eventType,BaseEventOperate* opt)=0;
	virtual void UnRegisterEvent(WPARAM eventType,BaseEventOperate* opt)=0;
	virtual IOperate* GetExecutingOperate()=0;
	virtual DataController* GetDataController()=0;
	virtual void Push(IAction* action)=0;
	virtual void Push(IOperate* operate)=0;
};

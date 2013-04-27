#include "StdAfx.h"
#include "BaseAction.h"

BaseAction::BaseAction(void)
{
}

BaseAction::~BaseAction(void)
{
	while(!this->OperateQueue.empty())
	{
		free(OperateQueue.front());
		OperateQueue.pop();
	}
}
queue<IOperate*>& BaseAction::GetOperateQueue()
{
	
	return (queue<IOperate*>&)this->OperateQueue;
}
list<IOperate*> BaseAction::GetOperates()
{
	queue<IOperate*> que=this->OperateQueue;
	list<IOperate*> list;
	while(!que.empty())
	{
		list.push_front(que.front());
		que.pop();
	}
	return list;
	
}
/********************************************************************
	created:	2011/05/01 17:14
	filename: 	BaseEventOperate
	file ext:	h
	author:		axb
	purpose:	Event-Based类型operate的基本实现，需要异步处理的operate
				应继承本类型
*********************************************************************/
#pragma once
#include "BaseOperate.h"

class BaseEventOperate :
	public BaseOperate
{
public:
	BaseEventOperate(void);
	~BaseEventOperate(void);
	virtual bool isExecuting(){return m_bExecuteState;}
	virtual int Execute(OperateAble* OperateAble);
	virtual int ProcEvent(WPARAM wParm,LPARAM lParm);
protected:
	bool m_bExecuteState;
	OperateAble* m_oOperateAble;
};

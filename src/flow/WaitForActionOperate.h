#pragma once
#include "baseeventoperate.h"

class WaitForActionOperate :
	public BaseEventOperate
{
public:
	WaitForActionOperate(void);
	~WaitForActionOperate(void);
	virtual int Execute(OperateAble* OperateAble);
	virtual int ProcEvent(WPARAM wParm,LPARAM lParm);
};

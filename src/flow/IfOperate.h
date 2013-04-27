#pragma once
#include "baseoperate.h"

class IfOperate :
	public BaseOperate
{
public:
	IfOperate(void);
	~IfOperate(void);
	virtual int Execute(OperateAble* OperateAble);
};

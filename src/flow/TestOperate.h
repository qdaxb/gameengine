#pragma once
#include "baseoperate.h"

class TestOperate :
	public BaseOperate
{
public:
	TestOperate(void);
	~TestOperate(void);
	virtual int Execute(OperateAble* OperateAble);
};

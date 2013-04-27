#pragma once
#include "baseoperate.h"

class NewActionOperate :
	public BaseOperate
{
public:
	NewActionOperate(void);
	~NewActionOperate(void);
	int virtual Execute(OperateAble* OperateAble);
};

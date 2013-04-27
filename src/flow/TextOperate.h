#pragma once
#include "baseoperate.h"

class TextOperate :
	public BaseOperate
{
public:
	TextOperate(void);
	~TextOperate(void);
	virtual int Execute(OperateAble* OperateAble);
};

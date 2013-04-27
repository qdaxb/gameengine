#pragma once
#include "baseoperate.h"
#include "gamedata.h"
class DataOperate :
	public BaseOperate
{
public:
	DataOperate(void);
	~DataOperate(void);
	virtual int Execute(OperateAble* OperateAble);
	void GetCommand();
	//void CutCommand();
private:
	wstring command;
};

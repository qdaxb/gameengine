/********************************************************************
	created:	2011/05/01 17:16
	filename: 	BaseOperate
	file ext:	h
	author:		axb
	purpose:	IOperate的基本实现，编写其他operate的时候可继承本类
*********************************************************************/
#pragma once
#include "ioperate.h"
#include "string"
#include "IAction.h"
#include "BaseVariable.h"
using namespace std;
class BaseOperate :
	public IOperate
{

private:
	wstring tag;
public:
	string num;
	BaseOperate(void);
	~BaseOperate(void);
	virtual int Execute(OperateAble* OperateAble);
	virtual wstring GetTag(){return this->tag;}
	virtual void SetTag(wstring tag){this->tag=tag;}

};

/********************************************************************
	created:	2011/05/01 17:11
	filename: 	IOperate
	file ext:	h
	author:		axb
	purpose:	所有Operate的基类，其他类引用时尽量使用IOperate类型指针
				暂时继承BaseVariable接口，完善时考虑使用IVariable代替
*********************************************************************/
#pragma once
#include "BaseVariable.h"

class OperateAble;
class IAction;
class IOperate:public BaseVariable
{
protected:
	IAction* parent;
public:
	IOperate(void);
	~IOperate(void);
	virtual int Execute(OperateAble* OperateAble) = 0;
	virtual bool isExecuting(){return false;};
	IAction* GetParent(){return parent;}
	void SetParent(IAction* parent){this->parent=parent;}
	virtual wstring GetTag()=0;
	virtual void SetTag(wstring tag)=0;
};

/********************************************************************
	created:	2011/05/01 17:11
	filename: 	IOperate
	file ext:	h
	author:		axb
	purpose:	����Operate�Ļ��࣬����������ʱ����ʹ��IOperate����ָ��
				��ʱ�̳�BaseVariable�ӿڣ�����ʱ����ʹ��IVariable����
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

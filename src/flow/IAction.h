/********************************************************************
	created:	2011/05/01 17:09
	filename: 	IAction
	file ext:	h
	author:		axb
	purpose:	所有Action的基类接口，其他类在使用action时使用IAction
				类型的指针而不用IAction的派生类
				暂时继承BaseVariable类，完善时替换为IVariable类
*********************************************************************/
#pragma once
#include "IOperate.h"
#include <queue>
#include <list>
#include <string>
#include "OperateStructure.h"
#include "BaseVariable.h"
#include <map>
using namespace std;
class IAction:public BaseVariable
{
private:
	IAction* m_oParent;
public:
	IAction(void);
	~IAction(void);
	virtual queue<IOperate*>& GetOperateQueue(void) =0;
	virtual list<IOperate*> GetOperates(void)=0;
	virtual wstring GetName()=0;
	virtual IAction* GetParent(){return m_oParent;}
};

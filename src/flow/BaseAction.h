/********************************************************************
	created:	2011/05/01 17:13
	filename: 	BaseAction
	file ext:	h
	author:		axb
	purpose:	IAction�Ļ���ʵ�֣���Ϸ�е�action������������Ӧ�̳д���
*********************************************************************/
#pragma once
#include "iaction.h"
#include "BaseOperate.h"
using namespace std;
class BaseAction :
	public IAction
{
private:
	queue<IOperate*> OperateQueue;
	wstring m_sName;
public:
	BaseAction(void);
	~BaseAction(void);
	virtual queue<IOperate*>& GetOperateQueue(void);
	virtual wstring GetName(){return this->m_sName;};
	virtual void SetName(wstring sName){this->m_sName=sName;}
	virtual list<IOperate*> GetOperates(void);
};

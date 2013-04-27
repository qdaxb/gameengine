/********************************************************************
	created:	2011/05/01 17:09
	filename: 	IAction
	file ext:	h
	author:		axb
	purpose:	����Action�Ļ���ӿڣ���������ʹ��actionʱʹ��IAction
				���͵�ָ�������IAction��������
				��ʱ�̳�BaseVariable�࣬����ʱ�滻ΪIVariable��
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

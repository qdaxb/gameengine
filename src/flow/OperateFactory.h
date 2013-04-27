/********************************************************************
	created:	2011/05/01 17:19
	filename: 	OperateFactory
	file ext:	h
	author:		axb
	purpose:	Operate�����࣬��������Ϸ����ʱͨ��operate�ṹ����operateʵ��
*********************************************************************/
#pragma once
#include <list>
#include "IOperate.h"

using namespace std;
class OperateStructure;
class XMLNode;
class OperateFactory
{
public:
	OperateFactory(void);
	~OperateFactory(void);
	list<IOperate*> CreateOperate(XMLNode* xmlNode,IAction* parent);
};

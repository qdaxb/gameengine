/********************************************************************
	created:	2011/05/01 17:20
	filename: 	VariableOperate
	file ext:	h
	author:		axb
	purpose:	用于在operate和action之间赋值的Operate
*********************************************************************/
#pragma once
#include "baseoperate.h"
#include "BaseVariable.h"

class VariableOperate :
	public BaseOperate
{
private:
	BaseVariable* m_oSourceNode;
	BaseVariable* m_oTargetNode;
	std::wstring m_sSourceKey;
	std::wstring m_sTargetKey;
public:
	VariableOperate(void);
	~VariableOperate(void);
	virtual int Execute(OperateAble* OperateAble);
	void SetSourceNode(BaseVariable* node){m_oSourceNode=node;}
	void SetTargetNode(BaseVariable* node){m_oTargetNode=node;}
	void SetSourceKey(std::wstring key){m_sSourceKey=key;}
	void SetTargetKey(std::wstring key){m_sTargetKey=key;}
};

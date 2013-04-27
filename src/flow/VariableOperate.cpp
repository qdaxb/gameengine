#include "StdAfx.h"
#include "VariableOperate.h"

VariableOperate::VariableOperate(void)
{
}

VariableOperate::~VariableOperate(void)
{
}
int VariableOperate::Execute(OperateAble* OperateAble)
{
	void *v=&((m_oSourceNode->GetVariable(m_sSourceKey))->toString());
	m_oTargetNode->SetVariable(m_sTargetKey,v);
	return 1;
}
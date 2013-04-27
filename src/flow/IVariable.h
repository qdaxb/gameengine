/********************************************************************
	created:	2011/05/01 17:12
	filename: 	IVariable
	file ext:	h
	author:		axb
	purpose:	�ɸ�ֵ�ӿڣ�����������ʱ���ã���̳�ʱ�Ĵ��麯���������⣩
*********************************************************************/
#pragma once
#include <string>
#include "GameData.h"
class IVariable
{
public:
	IVariable(void);
	~IVariable(void);
	virtual GameData* GetVariable(std::wstring name)=0;
	virtual void SetVariable(std::wstring name,void* value)=0;
};

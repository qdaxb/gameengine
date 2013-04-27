/********************************************************************
	created:	2011/05/01 17:12
	filename: 	IVariable
	file ext:	h
	author:		axb
	purpose:	可赋值接口，技术限制暂时不用（多继承时的纯虚函数覆盖问题）
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

/********************************************************************
	created:	2011/05/01 17:14
	filename: 	BaseVariable
	file ext:	h
	author:		axb
	purpose:	IVariable的基本实现，因技术原因其他接口暂时继承此类
*********************************************************************/
#pragma once
#include "IVariable.h"
#include "GameData.h"
using namespace std;
class BaseVariable :
	public IVariable
{
protected:
	GameData baseData;
public:
	
	BaseVariable(void);
	~BaseVariable(void);
	virtual GameData* GetVariable(std::wstring name);
	virtual void SetVariable(std::wstring name,void* value);
};

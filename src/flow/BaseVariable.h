/********************************************************************
	created:	2011/05/01 17:14
	filename: 	BaseVariable
	file ext:	h
	author:		axb
	purpose:	IVariable�Ļ���ʵ�֣�����ԭ�������ӿ���ʱ�̳д���
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

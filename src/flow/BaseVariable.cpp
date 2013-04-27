#include "StdAfx.h"
#include "BaseVariable.h"

BaseVariable::BaseVariable(void)
{
}

BaseVariable::~BaseVariable(void)
{
}
GameData* BaseVariable::GetVariable(std::wstring name)
{

	GameData *data=this->baseData.getValue(name);
	if(data==NULL)
	{
		baseData.init(name);
		data=this->baseData.getValue(name);
	}
	return data;
}
void BaseVariable::SetVariable(std::wstring name,void* value)
{
	this->baseData.SetValue(*(wstring*)value,name);
}
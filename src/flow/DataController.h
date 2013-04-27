#pragma once
#include <string>
#include "GameData.h"
class OperateAble;
class DataController
{
private:
	OperateAble* m_oOperateAble;
	GameData rootData;
public:
	DataController(OperateAble* oa);
	~DataController(void);
	int GetInt(std::wstring exp);
	float GetFloat(std::wstring exp);
	std::wstring GetString(std::wstring exp);
	void* GetVariable(std::wstring exp);
	GameData* GetData(std::wstring exp);
	void RunExp(char* exp);
	char* CutBrace(char* exp);
};

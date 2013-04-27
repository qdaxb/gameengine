#pragma once
#include <string>
#include <list>
using namespace std;
class ActionStructure
{
public:
	ActionStructure(void);
	~ActionStructure(void);
	list<wstring> GetOperates(){return this->operates;};
	void AddOperate(wstring str){operates.push_back(str);}
private:
	list<wstring> operates;
};

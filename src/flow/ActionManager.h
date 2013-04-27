/********************************************************************
	created:	2011/05/01 17:06
	filename: 	ActionManager
	file ext:	h
	author:		axb
	purpose:	被导入的action管理类，用户在游戏执行过程中生成可用的
				action定义
*********************************************************************/
#pragma once
#include <map>
#include <string>
#include "IAction.h"
#include "XmlNode.h"
class ActionManager
{
public:
	ActionManager(void);
	~ActionManager(void);
	void InitAction(XMLNode* root);
	XMLNode* GetAction(wstring name)
	{
		map<wstring, XMLNode*>::iterator iter;
		iter=m_mapAllAction.find(name);
		if(iter != m_mapAllAction.end())
			return iter->second;
		return NULL;
	}
private:
	map<wstring,XMLNode*> m_mapAllAction;

};

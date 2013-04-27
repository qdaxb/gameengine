/********************************************************************
	created:	2011/05/01 17:06
	filename: 	ActionManager
	file ext:	h
	author:		axb
	purpose:	�������action�����࣬�û�����Ϸִ�й��������ɿ��õ�
				action����
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

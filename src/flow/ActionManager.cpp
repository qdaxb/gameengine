#include "StdAfx.h"
#include "ActionManager.h"

ActionManager::ActionManager(void)
{
}

ActionManager::~ActionManager(void)
{
}
void ActionManager::InitAction(XMLNode* root)
{
	list<XMLNode*> actions;
	//todo ´íÎó´¦Àí
	root->GetChild((list<XMLNode*>&)actions);
	list<XMLNode*>::iterator it;
	for ( it = actions.begin(); it != actions.end(); ++it )
	{
		wstring str;
		(*it)->GetValue(L"name",(wstring&)str);
		this->m_mapAllAction.insert(pair<std::wstring, XMLNode*>(str,(*it)));
	}
}

//void ActionManager::AddAction(IAction& oAction){
//	m_mapAllAction.insert(pair<wstring, IAction*>(oAction.GetName(),&oAction));
//}
//IAction* ActionManager::CreateAction(wstring command,IAction* parentAction)
//{
//	map<wstring, IAction*>::iterator iter;
//	iter=m_mapAllAction.find(command);
//	if(iter != m_mapAllAction.end())
//		return iter->second;
//	return 0;
//}
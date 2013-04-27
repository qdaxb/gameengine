#ifndef _XMLNODE_H_
#define _XMLNODE_H_

#include <map>
#include <list>
#include <string>
#pragma once

using namespace std;
class XMLNode
{
public:

	XMLNode(void);
	
	~XMLNode(void);

	int ConvertToMap( map<wstring, wstring>& mapNode );

	int GetValue( const wstring& strName, wstring& strValue );

	int GetType( wstring& strNodeType );

	int GetChild( list<XMLNode*>& listChildNode );

	int GetChild( const wstring& strNodeType, list<XMLNode*>& listChildNode );

	map<wstring,wstring>* GetAttributes(void);
	

public:

	int AddChild( XMLNode* pXMLChildNode );

	int AddAttribute( const wstring& strKey, const wstring& strValue );

	int SetNodeType( const wstring& strNodeType );

private:

	wstring m_strNodeType;

	list<XMLNode*> m_listChildNode;

	map<wstring, wstring> m_mapNodeAttribute;

	//CriticalSectionLock m_Lock;

};

#endif


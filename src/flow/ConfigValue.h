#ifndef _CONFIGVALUE_H_
#define _CONFIGVALUE_H_

#pragma once
#include <string>
#include <map>
using namespace std;
class ConfigValue
{
public:

	ConfigValue(void);

	~ConfigValue(void);

public:

	ConfigValue* SelectSingleNode( const wstring& lpszValuePatch );
	
	DWORD GetValue( LPTSTR lpszReturnValue );

	bool AddNewOperator( const wstring& lpszKey, const wstring& lpszValue );

	void GetOperatorMap( map<wstring, wstring>& mapOperator );

private:

	map<wstring, wstring> m_mapOperator;

};

#endif
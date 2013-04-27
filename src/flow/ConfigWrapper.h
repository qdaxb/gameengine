#ifndef _CONFIGWRAPPER_H_
#define _CONFIGWRAPPER_H_

#pragma once
#include <string>
#include <map>
using namespace std;
class ConfigManager;
class ConfigWrapper
{
public:

	ConfigWrapper(void);

	~ConfigWrapper(void);

public:

	int SetConfigParameters( const wstring& csPatchName );

	int CreateGlobalConfigManager();

	bool RemoveGlobalConfigManager();

	bool GetwstringValueFromConfig( const wstring& csKey, wstring& csValue );

	int GetAllNodeInfoFromConfig( map<wstring, wstring>& mapOperator );

private:

	wstring m_strPatchName;

	ConfigManager* m_pConfigManager;

};

#endif


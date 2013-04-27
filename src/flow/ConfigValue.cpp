#include "StdAfx.h"
#include "ConfigValue.h"
#include "Commondef.h"


ConfigValue::ConfigValue(void)
{
	m_mapOperator.clear();
}

ConfigValue::~ConfigValue(void)
{
	m_mapOperator.clear();
}

ConfigValue* ConfigValue::SelectSingleNode( const wstring& strValuePatch )
{
	return 0;
}

DWORD ConfigValue::GetValue( LPTSTR strReturnValue )
{
	return 0;
}

bool ConfigValue::AddNewOperator( const wstring& strKey, const wstring& strValue )
{
	wstring strOperatorName( strKey );
	wstring strOperator( strValue );
	if ( EQUAL_STRING == strOperatorName.compare( NULL_STRING ) ||
		 EQUAL_STRING == strOperator.compare( NULL_STRING ))
	{
		return false;
	}

	m_mapOperator.insert( map<wstring, wstring>::value_type( strOperatorName, strOperator ));

	return true;
}

void ConfigValue::GetOperatorMap( map<wstring, wstring>& mapOperator )
{
	mapOperator.insert( m_mapOperator.begin(), m_mapOperator.end() );
}


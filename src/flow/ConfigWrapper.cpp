#include "StdAfx.h"
#include "ConfigWrapper.h"
#include "Commondef.h"
#include "ConfigManager.h"
#include "ConfigValue.h"

//ConfigWrapper* ConfigWrapper::m_pInstance = NULL;

ConfigWrapper::ConfigWrapper(void)
:m_strPatchName( NULL_STRING ),
 m_pConfigManager( NULL )
{
}

ConfigWrapper::~ConfigWrapper(void)
{
	RemoveGlobalConfigManager();
}

int ConfigWrapper::SetConfigParameters( const wstring& strPatchName )
{
	if ( NUMBER_ZERO == strPatchName.compare( NULL_STRING ))
	{
		return ERROR_XMLFILE_INVALID;
	}

	m_strPatchName = strPatchName;

	return RETURN_SUCCESS;		
}

int ConfigWrapper::CreateGlobalConfigManager()
{
	try
	{
		if ( NUMBER_ZERO == m_strPatchName.compare( NULL_STRING ))
		{
			return ERROR_XMLFILE_INVALID;
		}

		if ( NULL != m_pConfigManager )
		{
			RemoveGlobalConfigManager();
		}

		if ( NULL == m_pConfigManager )
		{
			m_pConfigManager = new ConfigManager();
			if ( NULL == m_pConfigManager )
			{
				return ERROR_NEWPOINTER_FAILED;
			}

			return m_pConfigManager->Initialize( m_strPatchName );
		}

		return RETURN_SUCCESS;
	}
	catch (CMemoryException*)
	{
		return ERROR_NEWPOINTER_FAILED;
	}
}

bool ConfigWrapper::RemoveGlobalConfigManager()
{
	if ( NULL != m_pConfigManager )
	{
		delete m_pConfigManager;
		m_pConfigManager = NULL;
	}

	return true;
}

bool ConfigWrapper::GetwstringValueFromConfig( const wstring& strKey, wstring& strValue )
{
	if ( NUMBER_ZERO == strKey.compare( NULL_STRING ))
	{
		return false;
	}

	if ( NULL == m_pConfigManager )
	{
		return false;
	}

	ConfigValue* pSingleNode = NULL;
//	pSingleNode = m_pConfigManager->SelectSingleNode( strKey );

	TCHAR szNodeValue[MAX_VALUE_LENGTH];

	DWORD dwReturnSize = pSingleNode->GetValue( szNodeValue );
	strValue = szNodeValue;

	if ( NULL != pSingleNode )
	{
		delete pSingleNode;
		pSingleNode = NULL;
	}

	return true;
}

int ConfigWrapper::GetAllNodeInfoFromConfig( map<wstring, wstring>& mapOperator )
{
	ConfigValue* pConfigValue = NULL;

//	pConfigValue = m_pConfigManager->SelectNodes();
	if ( NULL != pConfigValue )
	{
		pConfigValue->GetOperatorMap( mapOperator );

		delete pConfigValue;
		pConfigValue = NULL;
	}
	else
	{
		return ERROR_NEWPOINTER_FAILED;
	}

	return RETURN_SUCCESS;
}
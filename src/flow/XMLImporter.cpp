#include "StdAfx.h"
#include "XMLImporter.h"
#include "Commondef.h"
#include "XMLNode.h"
#include "ConfigManager.h"

XMLImporter::XMLImporter( const wstring& strFilePath )
{
	m_strFilePath = strFilePath;
}

XMLImporter::~XMLImporter()
{
}

int XMLImporter::ImportXML( XMLNode* pXMLNode )
{
	ConfigManager* pConfMgr = new ConfigManager();
	int nRet = pConfMgr->Initialize( m_strFilePath );
	if ( RETURN_SUCCESS != nRet )
	{
		return nRet;
	}

	nRet = pConfMgr->ImportXMLToXMLNode( pXMLNode );
	if ( RETURN_SUCCESS != nRet )
	{
		return nRet;
	}

	return RETURN_SUCCESS;
}

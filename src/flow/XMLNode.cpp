#include "StdAfx.h"
#include "XMLNode.h"
#include "Commondef.h"

XMLNode::XMLNode(void)
{
	m_strNodeType = NULL_STRING;
	m_listChildNode.clear();
	m_mapNodeAttribute.clear();
}

XMLNode::~XMLNode(void)
{
	list<XMLNode*>::iterator it;
	for ( it == m_listChildNode.begin(); it != m_listChildNode.end(); ++it )
	{
		delete *it;
		*it = NULL;
	}

	m_listChildNode.clear();
	m_mapNodeAttribute.clear();
}

int XMLNode::ConvertToMap( map<wstring, wstring>& mapNode )
{
	//AutoLock_Type autoLock( m_Lock );

	if ( NUMBER_ZERO == m_mapNodeAttribute.size())
	{
		return ERROR_NO_VALUE;
	}

	mapNode = m_mapNodeAttribute;

	return RETURN_SUCCESS;
}

int XMLNode::GetValue( const wstring& csName, wstring& csValue )
{
	//AutoLock_Type autoLock( m_Lock );

	if ( NUMBER_ZERO == m_mapNodeAttribute.size() )
	{
		return ERROR_NO_VALUE;
	}

	map<wstring, wstring>::iterator it = m_mapNodeAttribute.find( csName );
	if ( m_mapNodeAttribute.end() == it )
	{
		return ERROR_NO_VALUE;
	}

	csValue = it->second;

	return RETURN_SUCCESS;
}

int XMLNode::GetType( wstring& strNodeType )
{
	//AutoLock_Type autoLock( m_Lock );

	strNodeType = m_strNodeType;

	return RETURN_SUCCESS;
}

int XMLNode::GetChild( list<XMLNode*>& listChildNode )
{
	//AutoLock_Type autoLock( m_Lock );

	if ( NUMBER_ZERO == m_listChildNode.size() )
	{
		return ERROR_NO_CHILD;
	}

	listChildNode = m_listChildNode;

	return RETURN_SUCCESS;
}

int XMLNode::GetChild( const wstring& strNodeType, list<XMLNode*>& listChildNode )
{
	//AutoLock_Type autoLock( m_Lock );

	if ( NUMBER_ZERO == m_listChildNode.size() )
	{
		return ERROR_NO_CHILD;
	}

	listChildNode.clear();

	list<XMLNode*>::iterator it;
	wstring strChildNodeType( NULL_STRING );
	for ( it = m_listChildNode.begin(); it != m_listChildNode.end(); ++it )
	{
		if ( RETURN_SUCCESS != (*it)->GetType( strChildNodeType ))
		{
			continue;
		}

		if ( EQUAL_STRING == strChildNodeType.compare( strNodeType ))
		{
			listChildNode.push_back( *it );
		}
	}

	return listChildNode.size() == 0 ? ERROR_NO_CHILD : RETURN_SUCCESS;
}

int XMLNode::AddChild( XMLNode* pXMLChildNode )
{
	//AutoLock_Type autoLock( m_Lock );

	m_listChildNode.push_back( pXMLChildNode );

	return RETURN_SUCCESS;
}

int XMLNode::AddAttribute( const wstring& strKey, const wstring& strValue )
{
	//AutoLock_Type autoLock( m_Lock );

	m_mapNodeAttribute.insert( map<wstring, wstring>::value_type( strKey, strValue ));
	
	return RETURN_SUCCESS;
}

int XMLNode::SetNodeType( const wstring& strNodeType )
{
	//AutoLock_Type autoLock( m_Lock );

	m_strNodeType = strNodeType;

	return RETURN_SUCCESS;
}

map<wstring,wstring>* XMLNode::GetAttributes(void)
{
	return &this->m_mapNodeAttribute;
}
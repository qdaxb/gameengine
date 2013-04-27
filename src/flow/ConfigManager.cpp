#include "StdAfx.h"
#include "ConfigManager.h"
#include "Commondef.h"
#include "XMLNode.h"


ConfigManager::ConfigManager()
{
	::CoInitialize( NULL );
}

ConfigManager::~ConfigManager(void)
{
	if ( NULL != m_pDocPtr )
	{
		m_pDocPtr.Release();
 		m_pDocPtr = NULL;
	}

	::CoUninitialize();
}

int ConfigManager::Initialize( const wstring& strFilePath )
{
	m_pDocPtr.CreateInstance( _uuidof(MSXML2::DOMDocument40) );

	variant_t varFilePath;
	varFilePath.vt = VT_BSTR;
	varFilePath.bstrVal = ::SysAllocString( strFilePath.c_str() );
	VARIANT_BOOL bRet =  m_pDocPtr->load( varFilePath );
	if ( FALSE == bRet )
	{
		return ERROR_XMLFILE_INVALID;
	}

	return RETURN_SUCCESS;
}

void ConfigManager::AnalyzeXMLElement( MSXML2::IXMLDOMElementPtr pElement, 
									   XMLNode* pXMLNode )
{
	MSXML2::IXMLDOMNodeList* pChildList = NULL;
	HRESULT hResult = pElement->get_childNodes( &pChildList );
	if ( SUCCEEDED(hResult) && NULL != pChildList )
	{
		long lCount = NUMBER_ZERO;
		pChildList->get_length( &lCount );

		for ( int i = NUMBER_ZERO; i < lCount; i++ )
		{
			MSXML2::IXMLDOMNode* pChild   =   NULL;   
			hResult = pChildList->get_item( i, &pChild );

			if ( SUCCEEDED(hResult) && NULL != pChild )
			{
				MSXML2::DOMNodeType nodeType;
				pChild->get_nodeType( &nodeType );
				
				if ( NODE_ELEMENT == nodeType )
				{				
					XMLNode* pXMLChildNode = new XMLNode();
					pXMLChildNode->SetNodeType( (wchar_t*)pChild->GetnodeName());
					SetXMLNodeInfo( pXMLChildNode, pChild );
					
					pXMLNode->AddChild( pXMLChildNode );
					
					AnalyzeXMLElement( pChild, pXMLChildNode );
				}
				else
				{
					continue;
				}
			}
		}
	}
}

int ConfigManager::ImportXMLToXMLNode( XMLNode* pXMLNode )
{
	MSXML2::IXMLDOMElementPtr  pChildNode ;
	pChildNode = (MSXML2::IXMLDOMElementPtr)(m_pDocPtr->firstChild);

	//pXMLNode = new(nothrow) XMLNode();
	if ( NULL == pXMLNode )
	{
		return ERROR_NEWPOINTER_FAILED;
	}

	SetXMLNodeInfo( pXMLNode, pChildNode );

	AnalyzeXMLElement( pChildNode, pXMLNode );

	return RETURN_SUCCESS;
}

void ConfigManager::SetXMLNodeInfo( XMLNode* pXMLNode, MSXML2::IXMLDOMElementPtr pElement )
{
	pXMLNode->SetNodeType( (wchar_t*)pElement->GetnodeName());

	MSXML2::IXMLDOMNamedNodeMap* pAttrs = NULL; 
	pElement->get_attributes( &pAttrs );

	long llenth = pAttrs->length;
	VARIANT varValue;

	for ( long i = 0; i < llenth; ++i )
	{
		MSXML2::IXMLDOMNodePtr pAttrItem = NULL;
		pAttrs->get_item( i, &pAttrItem );
		pAttrItem->get_nodeValue( &varValue );

		pXMLNode->AddAttribute( (wchar_t*)pAttrItem->GetnodeName(), (wchar_t*)varValue.bstrVal);
	}
}
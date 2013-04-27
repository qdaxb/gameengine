#ifndef _CONFIGMANAGER_H_
#define _CONFIGMANAGER_H_

#pragma once

#import "MSXML4.dll"
#include <string>
using namespace std;
class XMLNode;
class ConfigManager
{
public:

	ConfigManager();

	~ConfigManager(void);

public:

	int Initialize( const wstring& lpszFilePath );

	int ImportXMLToXMLNode( XMLNode* pXMLNode );

private:

	void AnalyzeXMLElement( MSXML2::IXMLDOMElementPtr pElement, 
		                    XMLNode* pConfigValue );

	void SetXMLNodeInfo( XMLNode* pXMLNode, MSXML2::IXMLDOMElementPtr pElement );

private:

	MSXML2::IXMLDOMDocumentPtr m_pDocPtr;

};

#endif
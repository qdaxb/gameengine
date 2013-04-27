#ifndef _XMLIMPORTER_H_
#define _XMLIMPORTER_H_

#pragma once

#ifdef XML_EXPORT
#define DLLAPI __declspec(dllexport)
#else
#define DLLAPI __declspec(dllimport)
#endif
#include <string>
using namespace std;
#pragma warning( disable : 4251 )
class XMLNode;
class XMLImporter
{
public:

	XMLImporter( const wstring& strFilePath );

	~XMLImporter();

	int ImportXML( XMLNode* pXMLNode );

private:

	wstring m_strFilePath;

};

#endif


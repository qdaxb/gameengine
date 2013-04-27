#ifndef _IXMLMANAGER_H_
#define _IXMLMANAGER_H_

class XMLNode;
class IXMLManager
{
public:
	virtual int ImportXMLToXMLNode( XMLNode* pXMLNode ) = 0;
};

#endif
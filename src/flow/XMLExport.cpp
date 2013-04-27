#include "stdafx.h"
#include "XMLExport.h"
#include "ConfigWrapper.h"
#include "Commondef.h"

// int ConvertXML( wchar_t* szPath, map<wstring, wstring>& mapOperator )
// {
// 	wstring strPatch( szPath );
// 	ConfigWrapper oConfigWrapper;
// 
// 	int nRet = RETURN_SUCCESS;
// 	
// 	nRet = oConfigWrapper.SetConfigParameters( strPatch );
// 	if ( RETURN_SUCCESS != nRet )
// 	{
// 		return nRet;
// 	}
// 
// 	nRet = oConfigWrapper.CreateGlobalConfigManager();
// 	if ( RETURN_SUCCESS != nRet )
// 	{
// 		return nRet;
// 	}
// 
// 	nRet = oConfigWrapper.GetAllNodeInfoFromConfig( mapOperator );
// 	if ( RETURN_SUCCESS != nRet )
// 	{
// 		return nRet;
// 	}
// 
// 	return RETURN_SUCCESS;
// }
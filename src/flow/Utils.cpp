#include   <windows.h> 
#include "Utils.h"
wchar_t*   ASCIItoUNICODE(const   char*   source)
{
	int   size   =   MultiByteToWideChar(CP_THREAD_ACP,
		MB_PRECOMPOSED,
		source,
		-1,
		NULL,
		0);

	wchar_t*   dest   =   new   wchar_t[size];
	MultiByteToWideChar(CP_THREAD_ACP,
		MB_PRECOMPOSED,
		source,
		-1,
		dest,
		size);

	return   dest;
} 
char*   UNICODEtoASCII(  std::wstring   source)
{
	//获取缓冲区大小，并申请空间，缓冲区大小事按字节计算的  
	int len = WideCharToMultiByte(CP_ACP, 0, source.c_str(), source.size(), NULL, 0, NULL, NULL);  
	char* buffer = new char[len + 1];  
	//宽字节编码转换成多字节编码  
	WideCharToMultiByte(CP_ACP, 0, source.c_str(), source.size(), buffer, len, NULL, NULL);  
	buffer[len] = '\0';  
	//删除缓冲区并返回值    
	return buffer;  
} 
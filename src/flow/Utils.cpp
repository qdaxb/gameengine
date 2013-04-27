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
	//��ȡ��������С��������ռ䣬��������С�°��ֽڼ����  
	int len = WideCharToMultiByte(CP_ACP, 0, source.c_str(), source.size(), NULL, 0, NULL, NULL);  
	char* buffer = new char[len + 1];  
	//���ֽڱ���ת���ɶ��ֽڱ���  
	WideCharToMultiByte(CP_ACP, 0, source.c_str(), source.size(), buffer, len, NULL, NULL);  
	buffer[len] = '\0';  
	//ɾ��������������ֵ    
	return buffer;  
} 
#include "MyStringEx.h"
#include <cstddef>
#include <string.h>
#include <iostream>
using namespace std;


CMyStringEx::CMyStringEx()
{

}

CMyStringEx::~CMyStringEx()
{

}

int CMyStringEx::Find(const char* pszParam)
{	
	if (pszParam == NULL || GetString() == NULL)
		return -1;
	//strstr(char* str1,const char* str2); str1에서 str2와 일치하는 문자열이 있는지 확인을 하는 함수
	const char* pszResult = strstr(GetString(), pszParam);
	cout << pszResult << endl;
	if (pszResult != NULL)
		return pszResult - GetString();

	return -1;
}

void CMyStringEx::OnSetString(char* pszData, int nLength)
{	
	// erron_t strcpy_s(char *dest, size_t size, const char *source);
	// dest : 문자열을 복사할 버퍼, size dest 버퍼의 크기, source 복사할 원본 문자열
	if (strcmp(pszData, "멍멍이아들") == 0)
		strcpy_s(pszData, sizeof(char) * (nLength + 1), "*착한아들*");
}
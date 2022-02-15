#include "MyStringEx.h"
#include <cstddef>
#include <string.h>
#include <iostream>
using namespace std;


CMyStringEx::CMyStringEx()
{

}

CMyStringEx::CMyStringEx(const char* pszParam)
	:CMyString(pszParam)
{

}

CMyStringEx::~CMyStringEx()
{

}

int CMyStringEx::SetString(const char* pszParam)
{
	int nResult;
	// strcmp 문자비교 함수 , (비교할 문자열1, 비교할 문자열2)
	if (strcmp(pszParam, "멍멍이아들") == 0)
		nResult = CMyString::SetString("착한사람");
	else
		nResult = CMyString::SetString(pszParam);

	return nResult;
 
}

int CMyStringEx::Find(const char* pszParam)
{	
	if (pszParam == NULL || GetString() == NULL)
		return -1;
	//strstr(char* str1,const char* str2); str1에서 str2와 일치하는 문자열이 있는지 확인을 하는 함수
	const char* pszResult = strstr(GetString(), pszParam);
	if (pszResult != NULL)
		return pszResult - GetString();

	return -1;
}
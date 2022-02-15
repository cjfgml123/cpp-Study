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
	// strcmp ���ں� �Լ� , (���� ���ڿ�1, ���� ���ڿ�2)
	if (strcmp(pszParam, "�۸��̾Ƶ�") == 0)
		nResult = CMyString::SetString("���ѻ��");
	else
		nResult = CMyString::SetString(pszParam);

	return nResult;
 
}

int CMyStringEx::Find(const char* pszParam)
{	
	if (pszParam == NULL || GetString() == NULL)
		return -1;
	//strstr(char* str1,const char* str2); str1���� str2�� ��ġ�ϴ� ���ڿ��� �ִ��� Ȯ���� �ϴ� �Լ�
	const char* pszResult = strstr(GetString(), pszParam);
	if (pszResult != NULL)
		return pszResult - GetString();

	return -1;
}
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
	//strstr(char* str1,const char* str2); str1���� str2�� ��ġ�ϴ� ���ڿ��� �ִ��� Ȯ���� �ϴ� �Լ�
	const char* pszResult = strstr(GetString(), pszParam);
	cout << pszResult << endl;
	if (pszResult != NULL)
		return pszResult - GetString();

	return -1;
}

void CMyStringEx::OnSetString(char* pszData, int nLength)
{	
	// erron_t strcpy_s(char *dest, size_t size, const char *source);
	// dest : ���ڿ��� ������ ����, size dest ������ ũ��, source ������ ���� ���ڿ�
	if (strcmp(pszData, "�۸��̾Ƶ�") == 0)
		strcpy_s(pszData, sizeof(char) * (nLength + 1), "*���ѾƵ�*");
}
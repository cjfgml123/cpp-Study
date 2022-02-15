#pragma once
#include "CMyString.h"
class CMyStringEx :
    public CMyString
{
public:
    CMyStringEx();
    CMyStringEx(const char* pszParam);
    ~CMyStringEx();
    int SetString(const char* pszParam);
    int Find(const char* pszParam);
};


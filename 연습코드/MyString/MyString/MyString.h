#pragma once

class CMyString
{
public:
	CMyString();

	explicit CMyString(const char* pszParam);

	CMyString(const CMyString& rhs);

	CMyString(CMyString&& rhs);
};
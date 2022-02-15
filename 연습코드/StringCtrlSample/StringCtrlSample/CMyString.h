#pragma once
class CMyString
{
public:
	CMyString();

	// ��ȯ ������
	explicit CMyString(const char* pszParam);

	// ���� ������
	CMyString(const CMyString& rhs);

	//�̵� ������
	CMyString(CMyString&& rhs);

	~CMyString();

private:
	//���ڿ��� �����ϱ� ���� ���� �Ҵ��� �޸𸮸� ����Ű�� ������
	char* m_pszData;

	//����� ���ڿ��� ����
	int m_nLength;
	int Append(const char* pszParam);
	CMyString& operator+=(const CMyString& rhs);


public:
	int SetString(const char* pszParam);
	const char* GetString() const; // ��� �б⸸ �����ϹǷ� �޼��带 ���ȭ �Ѵ�.
	void Release();
	CMyString& operator=(const CMyString& rhs);

	operator char* () const
	{
		return m_pszData;
	}

	int GetLength() const;
	char& operator[](int nIndex);
	char operator[](int nIndex) const;
	int operator==(const CMyString &rhs);
	int operator!=(const CMyString& rhs);
	//virtual void OnSetString(char* pszData, int nLength);
	CMyString operator+(const CMyString& rhs);
	friend CMyString operator+(const char* pszParam, const CMyString& strParam);
};


// TemplateArray.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

template<typename T>
class CMyArray
{
public:
	explicit CMyArray(int nSize) : m_nSize(nSize)
	{
		m_pData = new T[nSize];
	}

	~CMyArray() { delete[] m_pData; }

	//복사 생성자 
	CMyArray(const CMyArray& rhs)
	{
		m_pData = new T[rhs.m_nSize];
		memcpy(m_pData, rhs.m_pData, sizeof(T) * rhs.m_nSize);
		m_nSize = rhs.m_nSize;
	}

	// 대입 연산자
	CMyArray& operator = (const CMyArray& rhs)
	{
		if (this == &rhs)
			return *this;
		
		delete m_pData;
		m_pData = new T[rhs.m_nSize];
		memcpy(m_pData, rhs.m_pData, sizeof(T) * rhs.m_nSize);
		m_nSize = rhs.m_nSize;

		return *this;
	}

	// 이동 생성자
	CMyArray(CMyArray&& rhs)
	{
		operator = (rhs);
	}

	// 이동 대입 연산자
	CMyArray& operator=(const CMyArray&& rhs)
	{
		m_pData = rhs.m_pData;
		m_nSize = rhs.m_nSize;
		rhs.m_pData = nullptr;
		rhs.m_nSize = 0;
	}

	//배열 연산자
	T& operator[](int nIndex)
	{
		if (nIndex < 0 || nIndex >= m_nSize)
		{
			cout << "ERROR: 배열의 경계를 벗어난 접근입니다." << endl;
			exit(1);
		}
		return m_pData[nIndex];
	}

	// 상수화된 배열 연산자
	T& operator[](int nIndex) const
	{
		return operator[](nIndex);
	}

	// 배열 요소의 개수를 반환
	int GetSize() { return m_nSize; }

private:
	T* m_pData = nullptr;
	int m_nSize = 0;
};

int main()
{
	//int 자료형 배열
	CMyArray<int> arr(5);

	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 40;
	arr[4] = 50;

	for (int i = 0; i < 5; ++i)
		cout << arr[i] << ' ';

	cout << endl;

	CMyArray<int> arr2(3);
	arr2 = arr;
	for (int i = 0; i < 5; ++i)
		cout << arr2[i] << ' ';
	cout << endl;
	
	return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

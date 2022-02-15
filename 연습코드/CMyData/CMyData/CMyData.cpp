// CMyData.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
class CMyData
{
public:
	CMyData(int nParam)
	{
		m_pnData = new int;
		*m_pnData = nParam;
	}
	// 복사 생성자 선언 및 정의
	CMyData(const CMyData &rhs)
	{
		cout << "CMyData(const CMyData &)" << endl;

		//메모리 할당
		m_pnData = new int;
		//포인터가 가리키는 위치에 값을 복사한다.
		*m_pnData = *rhs.m_pnData;
	}
	//객체가 소멸하면 동적 할당한 메모리를 해제한다.
	~CMyData()
	{
		delete m_pnData;
	}

	//단순 대입 연산자 함수를 정의한다.
	CMyData& operator = (const CMyData& rhs)
	{
		*m_pnData = *rhs.m_pnData;
		return *this;
	}

	int GetData()
	{
		if (m_pnData != NULL)
			return *m_pnData;
		return 0;
	}
private:
	//포인터 멤버 데이터
	int* m_pnData = nullptr;
};
int main()
{
	CMyData a(10);
	CMyData b(20);
	a = b; 
	cout << a.GetData() << endl;
	return 0;
}
/*
CMyData(const CMyData &)
10
10
*/


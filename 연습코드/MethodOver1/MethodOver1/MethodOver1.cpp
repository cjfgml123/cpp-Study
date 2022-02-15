// MethodOver1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class CMyData
{
public:
	int GetData() { return m_nData; }

	void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
};

class CMyDataEx : public CMyData
{
public:
	//파생 클래스에서 기본 클래스의 메서드를 재정의했다.
	void SetData(int nParam)
	{
		//입력 데이터의 값을 보정하는 새로운 기능을 추가한다.
		if (nParam < 0)
			CMyData::SetData(0);

		if (nParam > 10)
			CMyData::SetData(10);
	}
};

int main()
{
	//구형에는 값을 보정하는 기능이 없다.
	CMyData a;
	a.SetData(-10);
	cout << a.GetData() << endl;

	//신형에는 값을 보정하는 기능이 있다.
	CMyDataEx b;
	b.SetData(15);
	cout << b.GetData() << endl;

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

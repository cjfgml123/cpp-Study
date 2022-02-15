// AdtSample.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

//#define NAME VALUE
#define DEFAULT_FARE 1000

class CPerson
{
public:
	CPerson() {}
	virtual ~CPerson() {
		cout << "virtual ~CPerson()" << endl;
	}

	// 요금 계산 인터페이스(순수 가상 함수)
	virtual void CalcFare() = 0;

	virtual unsigned int GetFare() { return m_nFare; }

protected:
	unsigned int m_nFare = 0;
};

class CBaby : public CPerson
{
public:
	//영유아 0~7세 요금 계산
	virtual void CalcFare() {
		m_nFare = 0; // 0%
	}
};

class CChild : public CPerson
{
public:
	//어린이 8~13세 요금 계산
	virtual void CalcFare() {
		m_nFare = DEFAULT_FARE * 50 / 100; // 50%
	}
};

class CTeen : public CPerson
{
public:
	// 청소년 14~19세 요금 계산
	virtual void CalcFare() {
		m_nFare = DEFAULT_FARE * 75 / 100; 
	}
};

class CAdult : public CPerson
{
public:
	virtual void CalcFare() {
		m_nFare = DEFAULT_FARE;
	}
};
int main()
{	
	CPerson* arList[3] = { 0 };
	int nAge = 0;

	// 1. 자료 입력 : 사용자 입력에 따라서 생성할 객체 선택
	for (auto& person : arList)
	{
		cout << "나이를 입력하세요:";
		cin >> nAge;
		if (nAge < 8)
			person = new CBaby;
		else if (nAge < 14)
			person = new CChild;
		else if (nAge < 20)
			person = new CTeen;
		else
			person = new CAdult;

		// 생성한 객체에 맞는 요금이 자동으로 계산된다.
		person->CalcFare();
	}

	// 2. 자료 출력 : 계산한 요금을 활용하는 부분
	for (auto person : arList)
		cout << person->GetFare() << "원" << endl;

	// 3. 자료 삭제 및 종료
	for (auto person : arList)
		delete person;

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

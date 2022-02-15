// Multicatch.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

void ExceptTest1()
{
	int nInput;
	cout << "1~10 양의 정수를 입력하세요.: ";
	cin >> nInput;

	// 범위를 벗어난 숫자면 예외를 던진다.
	if (nInput < 1 || nInput > 10)
		throw nInput;
}

void ExceptTest2()
{
	char ch;
	cout << "Menu: [A]dd\t[D]elete\t[E]xit\n";
	cin >> ch;

	//없는 메뉴를 선택하면 예외를 던진다.
	if (ch != 'A' && ch != 'D' && ch != 'E')
		throw ch;
}

int main()
{
	cout << "Begin" << endl;
	try
	{
		// 정상적인 흐름이 한 블록 안에 모두 보인다.
		ExceptTest1();
		ExceptTest2();
	}
	catch (int nExp)
	{
		cout << "Error:" << nExp << "은 범위를 벗어난 숫자입니다." << endl;
	}
	catch (char ch)
	{
		cout << "Error:" << ch << "알 수 없는 메뉴입니다." << endl;
	}

	cout << "End" << endl;

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

// SharedPtrSample.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <memory>
using namespace std;

class CTest
{
public:
    CTest() { cout << "CTest()" << endl; }
    ~CTest() { cout << "~CTest()" << endl; }
    void TestFunc() { cout << "TestFunc()" << endl; }
};

int main()
{
    cout << "Begin" << endl;
    shared_ptr<CTest> ptr1(new CTest);

    // 한 대상을 한 포인터로 포인팅한다.
    cout << "Counter: " << ptr1.use_count() << endl;
    {
        shared_ptr<CTest> ptr2(ptr1);

        // 한 대상을 두 포인터로 포인팅한다.
        cout << "Counter: " << ptr1.use_count() << endl;
        ptr2->TestFunc();
    }

    // 한 포인터가 소멸했으므로 포인팅 개수가 1 감소한다.
    cout << "Counter: " << ptr1.use_count() << endl;
    ptr1->TestFunc();
    cout << "End" << endl;

    // 결국 카운터가 0이 되면 대상 객체를 소멸시킨다.
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

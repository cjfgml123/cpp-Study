// OperOverAssignMove.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

//제작자 코드
class CMyData
{
public:
    // explicit 예약어로 묵시적으로 변환이 일어나지 않게끔 하여 임시객체가 생성되지 못하게 한다.
    explicit CMyData(int nParam)
    {
        cout << "CMyData(int)" << endl;
        m_pnData = new int(nParam);
    }

    CMyData(const CMyData& rhs)
    {
        cout << "CMyData(const CMyData &)" << endl;
        m_pnData = new int(*rhs.m_pnData);
    }

    ~CMyData() { delete m_pnData; }

    operator int() { return *m_pnData; }

    // 덧셈 연산자 다중 정의
    CMyData operator+(const CMyData& rhs)
    {
        //호출자 함수에서 이름 없는 임시 객체가 생성된다.
        return CMyData(*m_pnData + *rhs.m_pnData);
    }

    // 단순 대입 연산자 다중 정의
    CMyData& operator = (const CMyData& rhs)
    {
        cout << "operator=" << endl;
        if (this == &rhs)
            return *this;

        delete m_pnData;
        m_pnData = new int(*rhs.m_pnData);

        return *this;
    }

    //이동 대입 연산자 다중 정의
    CMyData& operator = (CMyData&& rhs)
    {
        cout << "operator=(Move)" << endl;

        // 얕은 복사를 수행하고 원본은 NULL로 초기화한다.
        m_pnData = rhs.m_pnData;
        rhs.m_pnData = NULL;
        return *this;
    }
private:
    int* m_pnData = nullptr;
};

// 사용자 코드
int main()
{
    CMyData a(0), b(3), c(4);
    cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ Before ㅡㅡ" << endl;

    // 이동 대입 연산자가 실행된다!
    a = b + c;
    cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡAfterㅡㅡㅡ" << endl;
    cout << a << endl;
    a = b;
    cout << a << endl;

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

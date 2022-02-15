// CTestData.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
using namespace std;

class CTestData
{
public:
    CTestData(int nParam,const char *pszName) : m_nData(nParam), m_pszName(pszName)
    {
        cout << "CTestData(int): " << m_pszName << endl;
    }

    ~CTestData()
    {
        cout << "~CTestData(): " << m_pszName << endl;
    }

    CTestData(const CTestData& rhs) : m_nData(rhs.m_nData), m_pszName(rhs.m_pszName)
    {
        cout << "CTestData(const CTestData &): " << m_pszName << endl;
    }

    CTestData& operator = (const CTestData& rhs) // 단순대입연산자로인해 실행됨.
    {
        cout << "operator=" << endl;
        // 값은 변경하지만 이름(m_pszName)은 그대로 둔다.
        m_nData = rhs.m_nData;
        return *this;
    }

    int GetData() const { return m_nData; }
    void SetData(int nParam) { m_nData = nParam; }

private:
    int m_nData = 0;
    //변수 이름을 저장하기 위한 멤버
    const char *m_pszName = nullptr;
};

CTestData TestFunc(int nParam)
{   
    CTestData a(nParam, "a");
    return a;
}

int main()
{   
    CTestData b(5, "b");
    cout << "ㅡㅡㅡㅡBeforeㅡㅡㅡㅡㅡㅡ" << endl;
    //함수가 반환되면서 임시 객체가 생성됐다가 대입 연산 후 즉시 소멸한다!
    b = TestFunc(10);
    cout << "After" << endl;
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

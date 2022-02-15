// LambdaSort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <functional>

using namespace std;

class CTestData
{
public:
    CTestData()
    {
        m_array[0] = 30;
        m_array[1] = 10;
        m_array[2] = 50;
        m_array[3] = 20;
        m_array[4] = 40;
    }

    void Print()
    {
        for (auto& n : m_array)
            cout << n << '\t';
        cout << endl;
    }

    //배열을 정렬한다.
    //함수의 매개변수가 람다식을 받을 수 있는 function 클래스다.
    void Sort(function<int(int, int)> cmp)
    {
        int nTmp;

        for (int i = 0; i < 4; ++i)
        {
            for (int j = i + 1; j < 5; ++j)
            {
                //두 항을 비교하기 위해 함수 객체를 이용한다.
                if (cmp(m_array[i], m_array[j]) < 0)
                {
                    nTmp = m_array[i];
                    m_array[i] = m_array[j];
                    m_array[j] = nTmp;
                }
            }
        }
    }
private:
    int m_array[5];
};

int main()
{
    CTestData data;
    data.Sort([](int a, int b) -> int { return a - b; });
    data.Print();

    //오름차순 정렬 및 출력
    data.Sort([](int a, int b) -> int {return b - a; });
    data.Print();
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

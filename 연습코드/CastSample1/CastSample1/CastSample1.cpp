// CastSample1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class CMyData
{
public:
    CMyData() {}
    virtual ~CMyData() {}
    void SetData(int nParam) { m_nData = nParam; }
    int GetData() { return m_nData; }

private:
    int m_nData = 0;
};

class CMyDataEx : public CMyData
{
public:
    void SetData(int nParam)
    {
        if (nParam > 10)
            nParam = 10;

        CMyData::SetData(nParam);
    }

    void PrintData()
    {
        cout << "PrintData(): " << GetData() << endl;
    }
};
int main()
{
    // 파생 형식의 객체를 기본 형식으로 포인팅한다.
    CMyData* pData = new CMyDataEx;
    CMyDataEx* pNewData = NULL;

    // CMyData::SetData() 함수를 호출합니다.
    // 따라서 10이 넘는지 검사하지 않습니다.
    // 가상 함수가 아니라면 실 형식이 아니라 참조 형식이 우선한다.
    pData->SetData(15);

    //기본 형식에 대한 포인터이나 가리키는 대상은 파생 형식이다.
    //이 사실이 명확하므로 파생 형식에 대한 포인터로 형변환을 시도한다.
    pNewData = static_cast<CMyDataEx*>(pData);
    pNewData->PrintData();
    delete pData;
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

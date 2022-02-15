// CompositionSample.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class CNode
{
	//friend 클래스 선언
	friend class CMyList;

public:
	// explicit : 묵시적 형변환을 할 수 없게 만들고 명시적인 형변환만 가능하도록 만드는 것.
	// ex) Point(클래스) pt; pt = 10; 이런식으로 된 것을 막기 위해 씀. 원래라면 pt = Point(10); 이런식으로 써야 함.
	explicit CNode(const char* pszName)
	{
		strcpy_s(m_szName, sizeof(m_szName), pszName);
	}
private:
	// 단일 연결 리스트로 관리할 데이터
	char m_szName[32];
	CNode* pNext = nullptr;
};

class CMyList
{
public:
	CMyList() : m_HeadNode("Dummy Head") {}
	~CMyList()
	{
		// 리스트에 담긴 데이터들을 모두 출력하고 삭제
		CNode* pNode = m_HeadNode.pNext; // friend때문에 가능
		CNode* pDelete = nullptr;

		while (pNode)
		{
			pDelete = pNode;
			pNode = pNode->pNext;

			cout << pDelete->m_szName << endl;
			delete pDelete;
		}

		m_HeadNode.pNext = nullptr;
	}

	void AddNewNode(const char* pszName)
	{
		CNode* pNode = new CNode(pszName);

		// 리스트에 새로운 노드를 추가
		pNode->pNext = m_HeadNode.pNext;
		m_HeadNode.pNext = pNode;
	}

	// 리스트의 모든 노드 값을 출력
	void Print()
	{
		CNode* pNode = m_HeadNode.pNext;
		while (pNode)
		{
			cout << pNode->m_szName << endl;
			pNode = pNode->pNext;
		}
	}

private:
	CNode m_HeadNode;
};

// UI 클래스
class CMyUI
{
public:
	// 참조 멤버는 반드시 초기화 목록을 이용해 초기화해야 한다.
	CMyUI(CMyList& rList) : m_list(rList) {}

	// 메뉴 출력 및 사용자 입력 확인
	int PrintMenu()
	{
		system("cls"); // 콘솔 화면 지움
		cout << "[1]Add\t" << "[2]Print\t" << "[0]Exit\n:";
		cout.flush(); // 콘솔 커서를 다음 행으로 줄바꿈하지 않고 Flush하는 것을 말한다.
		int nInput = 0;
		cin >> nInput;

		return nInput;
	}

	//지속적으로 메뉴를 출력하는 메인 이벤트 반복문
	void Run()
	{
		char szName[32];
		int nInput = 0;

		while ((nInput = PrintMenu()) > 0)
		{
			switch (nInput)
			{
			case 1: // Add
				cout << "이름: ";
				cout.flush();
				cin >> szName;
				m_list.AddNewNode(szName);
				break;
			case 2: // print
				m_list.Print();
				break;
			default:
				break;
			}
		}
	}

private: 
	//UI 클래스 내부에 자료구조 객체에 대한 참조만 존재한다.
	CMyList &m_list;
};

int main()
{
	// 자료구조와 UI 객체를 별도로 선언하고 연결한다.
	CMyList list;
	CMyUI ui(list);
	ui.Run();
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

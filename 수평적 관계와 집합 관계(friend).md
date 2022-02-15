### Chapter 08 수평적 관계와 집합 관계

#### 8.1 friend

- friend 예약어는 함수나 클래스 선언 앞에 작성할 수 있다.
- 반드시 클래스 내부에서 friend 선언을 해야 한다. 누가 누구의 친구가 되는 것인지 명확해야 하기 때문이다.

```C++
friend class 클래스 이름;
friend 함수원형선언;
```

- friend 함수 및 클래스 : 클래스에서 선언하는 접근 제어 지시자의 영향을 받지 않도록 해준다. 기존 클래스와 클래스 상속 관계에 영향을 받지 않고 새로운 관계를 형성할 수 있다.
- 집합 관계 : friend 함수와 클래스 선언을 이용해서 각 요소를 의미에 따라 묶는 구조화를 의미한다.

```C++
// 전역 함수 PrintData를 friend 예약어를 이용함.
#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData(int nParam) : m_nData(nParam) {}
	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

	//friend 함수로 선언
	friend void PrintData(const CMyData &);
private:
	int m_nData = 0;
};

void PrintData(const CMyData& rData) 	// 전역 함수
{
	// 프렌드 함수이므로 접근 제어 지시자의 영향을 받지 않고 
	// private 멤버에 직접 접근한다.
	cout << "PrintData():" << rData.m_nData << endl;
}
int main()
{
	CMyData a(5);
	PrintData(a);

	return 0;
}
```

##### 의문점 :

##### 객체지향적인 프로그래밍을 위해 머리가 아프도록 접근을 제어하더니 이렇게 허무하다 싶게 그냥 열어주는 것은 뭔가요?

- C++ 문법의 특징이 '자유도'가 높다는 것.
- 개발자가 의지를 가지고 객체를 꽉 틀어막을 수도 있고 화끈하게 몽땅 열어줄 수도 있다. 이것을 다른 말로 '독립성'과 '응집성'이라고 한다. 서로 관련 없는 것들은 완전히 무관하게 설계하고 반대로 따로 떨어진 것이라 하더라도 관련이 깊다면 거의 한 덩어리에 준하도록 묶어주는 것이다.
- friend 예약어 선언이 존재하는 것은 '응집성' 때문이다. 한 덩어리로 만든 C 기반 프로그램을 C++로 변환할 때 특정 클래스가 다른 대상을 상대로 friend 예약어를 선언할 수 있다. 이유는 그 둘의 관계가 마치 '연예인'과 '매니저' 같기 때문이다.



#### 8.1.3 friend 클래스

- 함수 외에 클래스도 friend 예약어를 선언할 수 있다.
- 이렇게 하면 friend로 선언한 클래스 통째로 접근 제어 지시자의 영향을 받지 않게 되므로 모든 메서드에 접근이 허용된다.

```c++
// 연결 리스트 
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
	CNode *pNext = nullptr;
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

private:
	CNode m_HeadNode;
};

int main()
{
	//메모리 추가/삭제 코드가 등장하지 않는다.
	CMyList list;
	list.AddNewNode("길동");
	list.AddNewNode("철수");
	list.AddNewNode("영희");

	return 0;
}

/*
영희
철수
길동
*/
```

- friend class CMyList; 로 인해 CMyList는 CNode 클래스의 private 멤버들에 아무런 제약 없이 접근할 수 있다.
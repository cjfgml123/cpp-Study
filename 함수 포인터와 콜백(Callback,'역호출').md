### 12.2.1 함수 포인터와 콜백(Callback,'역호출')

```c++
#include <iostream>
using namespace std;

// 사용자는 각 항을 비교하는 방법을 정의해야 한다.
int CompareData(const void* pLeft, const void* pRight)
{
	return *(int*)pLeft - *(int*)pRight;
    //뺄셈을 해서 값이 가타면 두 수는 값이 같은 것이고 양수라면 왼쪽 값이 더 큰 것.
    //qsort는 이 반환값을 기준으로 퀵정렬을 실행한다.
    //정렬의 대상이 문자열 이라면 지금처럼 뺄셈연산만으로는 비교할 수 없어서 정렬하려는 대상에 따라 방법을 사용자 스스로가 결정할 수 있도록 길을 열어준 것.
    //Left , Right 위치 바꾸면 내림차순
}

int main()
{
	int aList[5] = { 30,50,10,20,40 };

	// 각 항을 비교하는 방법(함수 주소)을 콜백 함수로 전달한다.
    // 정렬할 배열,요소개수, 요소크기, 비교함수
	qsort(aList, 5, sizeof(int), CompareData);
	// 함수를 비교할 때마다 이 주소를 호추한다.
	for (auto& n : aList)
		cout << n << '\t';

	cout << endl;
}
/*
10      20      30      40      50
*/
```

#### 12.2.2 함수 객체

- 함수 호출 연산자를 다중 정의한 클래스를 말한다.
- 함수 호출 연산자를 여러 매개변수 구조로 다중 정의함으로써 함수 템플릿처럼 활용할 수 있다.

- 펑터(Functor)라고도 부른다.

```c++
#include <iostream>
using namespace std;

// 함수 객체 클래스의 선언 및 정의
class Add
{
public:
	//함수 호출 연산자를 다중 정의한다.
	int operator()(int a, int b)
	{
		cout << "()(int, int)" << endl;
		return a + b;
	}

	// 다양한 매개변수 구성으로 다중 정의할 수 있다.
	double operator()(double a, double b)
	{
		cout << "()(double, double)" << endl;
		return a + b;
	}
};

int main()
{
	Add adder;
	//함수 객체로 호출한다.
	cout << adder(3, 4) << endl;
	cout << adder(3.3, 4.4) << endl;

	return 0;
}
/*
()(int, int)
7
()(double, double)
7.7
*/
```

```c++
//함수를 함수의 매개변수로 넘긴 것.
//제작자 철수의 코드
void TestFunc(Add &add)
{
    //사용자가 만든 함수를 제작자가 호출한다.
    cout << add(3,4) << endl;
}

// 사용자 영희의 코드
int main()
{
    Add adder;
    //제작자에게 전달하면 호출해준다.
    TestFunc(adder);
}
```

```c++
#include <iostream>
using namespace std;

class CCompareBase
{
public:
    // 순수 가상 함수로 선언된 연산자 함수
    // 따라서 모든 CCompareBase의 파생 클래스는 int 자료형 둘을 매개변수로 받아 다시 int 자료형을 반환하는 함수 호출 연산자를 재정의해야 한다. 끝에 보이는 const 예약어도 빠뜨리면 안된다.
    virtual int operator()(int a, int b) const = 0;
};

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
    // cmp(m_array[i],m_array[i])는 파생 형식의 것, 즉 미래의 함수를 호출하는 것이다. 가상함수 이므로
    void Sort(const CCompareBase& cmp)
    {
        int nTmp;

        for (int i = 0; i < 4; ++i)
        {
            for (int j = i + 1; j < 5; ++j)
            {
                // 두 항을 비교하는 방법은 함수 객체를 이용한다.
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

class CMyCmpDesc : public CCompareBase
{
public:
    int operator()(int a, int b) const { return a - b; }
};

class CMyCmpAsce : public CCompareBase
{
public:
    int operator()(int a, int b) const { return b - a; }
};

int main()
{
    CTestData data;

    //내림차순 정렬 및 출력
    CMyCmpDesc desc;
    data.Sort(desc);
    data.Print();

    //오름차순 정렬 및 출력
    CMyCmpAsce asce;
    data.Sort(asce);
    data.Print();
}

/*
50      40      30      20      10
10      20      30      40      50
*/
```

- cmp는 Sort() 메소드의 매개변수이고 형식은 const CCompareBase &cmp이다.

#### 12.2.3 람다식으로 변경하기

- 람다식이란 함수에 매개변수로 함수 자체를 전달할 수 있는 방법이다.

```c++
// 함수 객체를 람다식으로 바꾼 정렬

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
    // int자료형 두 개를 매개변수로 받아 다시 int 자료형을 반환하는 함수
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
/*
50      40      30      20      10
10      20      30      40      50
*/
```

#### 12.2.4 람다 캡처

- 람다 캡처란 람다식 내부에서 외부에 선언된 변수에 접근하기 위한 선언이다. 람다식은 함수 내부에 정의하는 또 다른 함수이므로 각각 개별화되는데 마치 임신중인 어머니와 뱃속의 아기가 각각 다른 사람인 것처럼 서로 다른 둘인 것이다. 람다 캡처라는 것은 어머니와 아기를 이어주는 탯줄 같은 것이다.
- 람다식 내부에서 사용하려는 외부 변수는 반드시 캡처 선언을 해야 하며 캡처 종류는 다음과 같다.

| 캡처 종류        | 설명                                                         |
| ---------------- | ------------------------------------------------------------ |
| 복사 캡처        | 람다식 선언([])의 내부에 외부에서 사용할 변수 이름을 작성해 캡처하는 것을 말한다. |
| 참조 캡처        | 람다식 선언([])의 내부에 외부에서 사용할 참조 변수(&) 이름을 작성해 캡처하는 것을 말한다. |
| 디폴트 복사 캡처 | 람다식 외부의 사용할 수 있는 모든 변수(람다 선언 직전에 이미 선언되었고 소멸되지 않은 모든 사용 범위 안 변수들)를 복사로 한꺼번에 캡쳐한다. [=]라고 선언해서 사용한다. |
| 디폴트 참조 캡처 | 디폴트 복사 캡처와 같은 의미인데 복사 대신 참조로 한꺼번에 캡쳐한다. [&]라고 선언해서 사용한다. |

```c++
복사 캡쳐 ex) [nData](void)->(void)
참조 캡쳐 ex) [&nData](void)->(void)
디폴트 복사 캡쳐 ex) [=](void)->(void)
디폴트 참조 캡쳐 ex) [&](void)->(void)
```

- 람다식은 크게 복사 캡처와 참조 캡처로 나뉜다. 복사 캡처는 값에 의한 호출이고 참조 캡처는 참조에 의한 호출과 같다.

```c++
#include <iostream>
using namespace std;

int main()
{
	int nData = 10;
	cout << nData << endl;
	auto TestFunc = [nData](void)->void
	{
		cout << nData << endl;
	};

	TestFunc();
}
/*
10
10
*/
```

```c++
//auto TestFunc = [nData](void)->void에서 void 생략 가능
auto TestFunc = [nData](void)->void	//모두 기술
auto TestFunc = [nData](void) // 반환 형식 생략
auto TestFunc = [nData]() // 반환 형식, 매개변수 생략
auto TestFunc = [nData] // 모두 void이므로 괄호까지 생략
```

- 람다식 외부에 선언된 변수를 복사 캡처한 경우 람다식 내부에서 값을 읽는 것은 가능하지만 변경하는 것은 안된다. ex) cout << ++nData << endl;
- 그러므로 복사 캡처는 기본적으로 const 예약어가 적용된 것처럼 작동한다고 볼 수 있다.

```c++
//하지만
auto TestFunc = [&nData](void)->void
//처럼 &기호를 붙여 참조 캡처로 선언한다면 람다식 내부에서 값을 읽는 것은 물론 단항 증가,감소 연산 대입연산을 실행해도 오류 x, 원본 외부 변수의 값도 변경
```

ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

```c++
//복사 캡처이면서도 람다식 내부에서 값을 변경할 수 있도록 허용하는 것이 있다. 단 그 변화는 람다식 내부로 제한된다.
#include <iostream>
using namespace std;

int main()
{
	int nData = 10;
	cout << nData << endl;
	auto TestFunc = [nData](void) mutable -> void
	{
		cout << ++nData << endl;
	};

	TestFunc();
	cout << nData << endl;
}
/*
10
11
10
*/
// mutable을 선언하면 복사 캡처된 변수의 값을 변경할 수는 있지만 그 영향은 람다식 내부까지로 제한된다.
```

```c++
// 복사 캡처할 변수가 여러 개라면 쉼표를 이용
int x = 10, y = 20;
auto TestFunc = [x,y]()->int
{
    return x + y;
};
// 외부 변수 x,y를 모두 복사 캡처한다. x,y는 람다식 외부에 존재하는 변수 전체이다. 이와 같이 변수 전체를 복사 캡처하고 싶다면 auto TestFunc = [=]()->int와 같이 디폴트 복사 캡처를 선언하는 것이 좋다.

//대괄호 안에 = 기호 하나만 넣으면 모든 람다식 내부에서 외부 변수에 접근가능, '='대신 '&'를 사용하면 디폴트 참조 캡처가 되고 읽기,쓰기 가능
auto TestFunc = [&]()->int
{
    return ++x + ++ y;
};

// 일부는 참조, 일부는 복사 캡처 가능
// 디폴트 참조 캡처를 적용하지만 z만은 예외로 복사 캡처를 진행하는 경우와 디폴트 복사 캡처를 적용하지만 z만은 예외로 참조 캡처를 적용한 예
int x,y,z;
[&,z] {};
[=,&z] {};


// 같은 변수가 두 번 같은 방법으로 캡처 되는것은 선언할 수 없다. ex)
[x,x] {};
[x,&x] {};
```

- 같은 변수가 두 번 같은 방법으로 캡처 되는것은 선언할 수 없다.


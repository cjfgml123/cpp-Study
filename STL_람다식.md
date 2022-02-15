#### 12.1 STL 맛보기

- STL(Standard Template Library)은 템플릿 기반의 클래스 라이브러리로 다양한 알고리즘과 자료구조를 쉽게 사용할 수 있는 방법을 클래스 형태로 제공한다.

```c++
// 스트링 컨테이너 사용
#include <iostream>

// string 클래스를 사용하기 위한 헤더
#include <string>
using namespace std;

int main()
{
	string strName;
	cout << "이름: ";
	cin >> strName;
	cout << "당신의 이름은 " + strName + "입니다." << endl;

	return 0;
}
```

- std::string 클래스를 사용하려면 string 헤더를 불러와야 한다. 그리고 std 네임스페이스 소속이며 보통은 cout 객체처럼 using선언으로 생략한다. 내부적으로 메모리를 자동으로 관리하는 것은 물론 이동 시맨틱 등 좋은 것들 다 구현되어 있다.

```c++
std::string strData("Hello");

if(strData == "World")
    cout << "Same" << endl;
// 연산자도 다 만들어져 있다. 덧셈 연산자 뿐만 아니라 관계 연산자도 구현되어 있으며 cout 객체로 출력할 수도 있다.
```



```c++
// 배열을 템플릿으로 구현한 vector 클래스 (크기가 늘어나기까지 함.)

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	//요소가 int 자료형이고 개수가 세 개인 벡터 선언
	vector<int> vec(3);
	vec[0] = 10;
	vec[1] = 20;
	vec[2] = 20;

	for (auto& n : vec)
		cout << n << '\t';

	cout << endl;

	// 뒤에 새로운 요소 두 개를 더 추가한다.
	vec.push_back(30);
	vec.push_back(40);

	for (auto& n : vec)
		cout << n << '\t';

	cout << endl;

	return 0;
}
/*
10      20      20
10      20      20      30      40
*/

// 템플릿 클래스 이므로 int 같은 기본 자료형 외에 사용자 정의 클래스도 지원
```



### 12.2 람다식과 함수 객체

- 람다'Lambda'는 이름 없는 함수 이다.
- 함수 객체를 대체하는 것으로 별도로 클래스를 선언할 필요 없이 간단한 람다식 선언과 정의만으로 같은 결과를 얻을 수 있으므로 편리하다.

```c++
[캡처] (매개변수 리스트) -> 반환형식 {구문;}
[캡처] mutable throw(매개변수 리스트) -> 반환형식 {구문;}
//mutable throw : 필요한 경우에만 기술
// 캡처 : 람다식 내부에서 외부에 선언된 요소에 접근하기 위한 문법
```

```c++
// 람다식 기본
// 람다식이 무엇인지 보여주기 위한 예시 , 이와 같은 구조의 코드는 다시 볼 일이 많지 않다.
#include <iostream>
using namespace std;

int Testfunc(int nParam)
{
    cout << "Function Pointer: " << nParam << endl;
    return nParam;
}

int main()
{
    //람다식 선언 및 정의
    auto func = [](int nParam) -> int
    {
        cout << "Lambda: " << nParam << endl;
        return nParam;
    };

    //람다식 호출
    func(5);

    //함수 포인터를 이용한 호출
    auto pfTest = Testfunc;
    pfTest(10);
}
/*
Lambda: 5
Function Pointer: 10
*/

//반환 형식도 int 자료형인 함수 원형임.

```

```c++
// 람다식을 다른 함수의 매개변수로 사용
// std::function 객체를 사용하기 위한 헤더 추가
#include <functional>
#include <iostream>
using namespace std;

// std::function 템플릿 클래스를 매개변수로 받는다.
// <int(const char*,int)> : 괄호 왼쪽의 int는 함수의 반환형식, 괄호 안쪽은 매개변수 목록
void TestFunc(const char* pszParam, std::function<int(const char*, int)> param)
{
	cout << pszParam << endl;
	param("Hello", 10);
}

int main()
{
	cout << "begin" << endl;
	::TestFunc(
		"TestFunc()",

		//함수의 실인수로 함수 몸체를 람다식으로 기술
		[](const char* pszParam, int nParam) -> int
		{
			cout << pszParam << " : " << nParam << endl;
			return 0; // 람다식의 return 문
		}
	);

	cout << "End" << endl;
}

/*
begin
TestFunc()
Hello : 10
End
*/
```


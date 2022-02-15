### 메모리 영역 동적 할당, 정적 할당 -https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=eludien&logNo=221462352935





### C++ main 함수

```C++
#include <iostream>
// iostream은 확장명이 없지만 헤더 파일이다. 확장명이 생략된 것도 아니므로 iostream.h와는 다른 파일이다. 헤더 파일임에도 불구하고 확장자 .h가 생략된 이유는 C++에서는 사용자 정의 헤더가 아닌 표준 헤더 파일들은 모두 .h 확장명을 생략하기 때문이다. 이것이 필요한 이유는 cout, endl 같은 객체를 사용하는데 이 헤더 파일이 필요하기 때문이다. 
std::cout << "Hello, World" << std::endl;

// std는 '네임스페이스'라고 하며 개념 상 '소속'으로 생각하면 된다.
// :: 은 '범위 지정 연산자' 혹은 '스코프 설정 연산자(Scope resolution operator)'라고 한다.
// cout은 콘솔 출력을 담당하는 객체이다.
// <<는 '연산자 함수'
// std에 속한 cout 객체에 "Hello, Wrold" 문자열과 endl 객체를 '넘겨(<<)' 문자열을 화면에 출력해달라는 뜻
```



### C++ Reference(참조자) 개념과 포인터와 차이

- 포인터는 NULL 값이 있지만, 참조값은 NULL 값이 없다. NULL 값이란, 결정되지 않거나 모르는 값을 의미한다. 하지만 참조자는 선언시 바로 초기화 해주어야 한다.
- 참조자는 변수를 입력 받고 포인터는 주소값을 입력 받는다.
- 참조자는 한번 지정한 객체를 변경할 수 없지만, 포인터는 가능하다. 참조자는 한번 객체를 정하면 바꿀 수 없다. 하지만 포인터의 경우 주소값을 변경하여 바꿀 수 있다.

ㅡㅡㅡ

- 공통점 : 둘 다 다른 객체(변수)를 간접적으로 참조한다.



#### 1) 참조자 - 자신이 참조하는 변수를 대신할 수 있는 또 하나의 이름

```C++
// 선언과 동시에 반드시 초기화 해야 한다.
// 형식 &이름 = 원본;
int *data = &3; //불가능
int &data = 3; // 상수에 대한 참조는 불가능
int &data; // 참조 원본이 없으므로 불가능

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
#include <iostream>
using namespace std;
int main(void)
{
    int num1 = 10;
    int &num2 = num1;	//num1에 num2라는 참조자를 선언했다.
    
    num2 += 10;
    cout << num1 << endl;
    cout << num2 << endl;
    return 0;
}
// 20
// 20
// 이미 선언된 변수의 앞에 오면 주소 값의 반환을 명령하는 뜻이지만, 새로 선언되는 변수의 이름 앞에 오면 참조자의 선언을 뜻하게 됩니다. num2에 다가 10을 더해줘서 num1도 20으로 출력 된다.
```



#### 2) 포인터





#### 3) 참조형 변수 선언과 정의

```C++
#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc,_TCHAR* argv[])
{
    int nData = 10;
    
    //nData 변수에 대한 참조자 선언
    int &ref = nData;
    
    // 참조자의 값을 변경하면 원본도 변경된다!
    ref = 20;
    cout << nData << endl;
    
    // 포인터를 쓰는 것과 비슷하다.
    int *pnData = &nData;
    *pnData = 30;
    cout << nData << endl;
    
    return 0;
}
//20
//30
```



#### 4) 함수의 매개변수가 참조 형식으로 되어 있는 예제

```C++
#include <iostream>

//매개변수가 int에 대한 참조 형식이다.
void TestFunc(int &rParam)
{
    //피호출자 함수에서 원본의 값을 변경했다.
    rParam = 100;
}
int main(int argc, _TCHAR* argv[])
{
    int nData = 0;
    // 참조에 의한 인수 전달이다.
    TestFunc(nData);
    cout<< nData << endl;
    return 0;
}
//100
//참조 전달이기 때문에 TestFunc() 함수의 매개변수인 rParam은 nData의 다른 이름이 됩니다. 따라서 nParam의 변화는 nData의 변화를 의미한다. 함수의 매개변수가 참조자인 경우 가장 큰 문제점은 호출자 코드만 봐서는 매개변수가 참조 형식이라는 사실을 전혀 알 수 없어서 C++에서는 절대로 호출자 코드만 보고 함수의 원형을 확신해서는 안된다.
```


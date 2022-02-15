#### 1. Callable

- 호출(Call)할 수 있는 모든 것을 의미한다. ex) 함수 , 하지만 c++에서는 ()를 붙여서 호출할 수 있는 모든 것을 Callable이라고 정의한다.

```c++
#include<iostream>

typedef struct _S
{
    void operator() ( int A, int B ) { std::cout << "A * B = " << A*B << std::endl; }
}S;

main()
{
    S s;
    s(1,2);
}

```

- s는 함수가 아니고 클래스의 객체인데 마치 함수 처럼()를 이용해서 호출할 수 있다. 실제는 s.operator()(1,2)

#### 2. std::function

- Callable들을 객체의 형태로 보관할 수 있다. 함수 포인터는 진짜 함수들만 보관할 수 있는 개체라고 볼 수 있다면 이것은 모든 Callable들을 보관할 수 있다.

```c++
#include <functional>
#include <iostream>
#include <string>

int some_(const std::string& a) {
  std::cout << "Func1" << a << std::endl;
  return 0;
}

struct S {
  void operator()(char c) { std::cout << "Func2" << c << std::endl; }
};

int main() {
    //int를 리턴하며 인자로 const string&을 받는다.
  std::function<int(const std::string&)> f1 = some_;
  std::function<void(char)> f2 = S();
 //S의 경우 operator()가 인자로 char을 받고 리턴타입이 void이므로 이렇게 표현
  f1("hello");
  f2('c');
}
```

#### 2-1) 멤버 함수를 가지는 std::function

- 위의 Callable 예시는 쉽게 적용할 수 있지만 클래스 안의 멤버 함수들은 다르다.

```c++
class A {
    int c;
    public:
    A(int _e) : c(_e){} //생성자
    int b() {}
};

int main() 
{
    A a(5);
    std::function<int()> w = a.b; //에러
}
//w 를 호출할때 자신을 호출하는 객체가 무엇인지 알 길이 없다. A클래스의 c를 참조 할때 어떤 객체의 c인지를 알 수 없어서 w에 a에 관한 정보도 추가로 전달해야 한다. 이 경우
std::function<int(A&)> w = &A::
```


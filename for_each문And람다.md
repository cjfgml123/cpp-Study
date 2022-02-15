## for_each문

- 코드 간결화
- 함수 객체를 이용한 inline화
- 사용자가 for_each문의 기능을 정의해 유연성을 부여.

- 사용법 : 헤더파일"<algorithm>"에 의해 정의 됨.
- 주의 : 2번째 인자에서 전달 받은 주소 값까지 출력하는 것이 아니라 전달 받은 주소 값 전 까지의 값만을 출력 
- 중간에 중단이 불가능 -> break 불가능

```c++
//Unaryfunction for_each(InputIt first,InputIt last, Unaryfunction f)
//반환 값 for_each(시작 주소 값 , 요소의 마지막 다음 null or 쓰레기 값의 주소, 사용자가 정의한 함수or 함수 객체)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_func(int n) {
    cout << n << " ";
}

int main(void) {
    vector<int> v = {5,2,3,4,5};
    // for_each는 값을 반환할 수 있다. 반환되는 것은 사용자로부터 전달 받은 함수 또는 함수 객체의 형식        으로 반환된다.
    // void(*pr)(int n)
    auto pr = for_each(v.begin(),v.end(),print_func);
    
    return 0;
}
```



#### 사용자가 정의한 함수 or 함수 객체

- 사용자가 정의한 함수 객체를 통해 간략하게 출력을 할 수 있다.
- Lambda를 이용해 함수나 객체를 정의할 필요없이 바로 실행되게 만들 수도 있다.

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_func(int n) {
    cout << n << " ";
}

int main(void) {
	vector<int> v = {1,2,3,4,5};
    vector<int>::iterator itr = v.begin();
    
    cout << "for_each문 함수 호출 : ";
    for_each(v.begin(), v.end(), print_fnc);    //함수 호출
    cout << endl;

	
    //itr은 v의 시작 조소를 가르키고 있으며 *itr로 접근한다면 v의 첫번째 요소 1이 출력 될 것. 이 1을 Lambda함수의 매개변수 n에 대입을 하게 된다.(내부적으로)
    cout << "for_each문 Lambda 호출 : ";
    for_each(itr, itr + v.size(), [](auto& n) {    //Lambda 호출
        cout << n << " ";
        });
}
```

- for_each문 내부로 들어가게 되면 첫 번째 인자 값으로 받은 주소 값을 바탕으로 사용자가 정의한 함수의 매개변수로 전달하게 된다.



## Lambda

- lambda는 boost라는 라이브러리에서 제공하는 함수 였지만 지금은 modern c++로 넘어가면서 이 기능을 본격적으로 지원하게 되었다.
- 람다는 기본적으로 캡쳐블록, 전달인자, return type을 생략할 수 있다.

```c++
[my_mod] (int v_) -> int {return v_ & my_mod;}
//[] 캡처 블록(사용시 외부 변수를 캡쳐해 람다 몸통에서 사용가능)
//() 전달 인자
//-> 반환타입
// {}함수 몸통
```


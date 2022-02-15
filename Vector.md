## Vector

- c++ 표준라이브러리(Standard Template Library)에 있는 컨테이너로 사용자가 사용하기 편하게 정의된 class를 말한다. vector를 생성하면 메모리 heap에 생성되며 동적할당 된다.

- 속도적인 측면에서 array(배열)에 비해 성능은 떨어지지만 메모리를 효율적으로 관리하고 예외처리가 쉽다는 장점이 있다.



#### Vector의 초기화

| vector<자료형> 변수명                         | 벡터 생성                                                  |
| --------------------------------------------- | ---------------------------------------------------------- |
| vector<자료형>변수명(숫자)                    | 숫자만큼 벡터 생성 후 0으로 초기화                         |
| vector<자료형>변수명={변수1,변수2,변수3...}   | 벡터 생성 후 오른쪽 변수 값으로 초기화                     |
| vector<자료형>변수명[]={,}                    | 벡터 배열(2차원 벡터) 선언 및 초기화(열은 고정, 행은 가변) |
| vector<vector<자료형>변수명                   | 2차원 벡터 생성(열과 행 모두 가변)                         |
| vector<자료형>변수명.assign(범위,초기화할 값) | 벡터의 범위 내에서 해당 값으로 초기화                      |

```c++
vector<int> v; //int형 벡터 생성
vector<int>v(4); //int형 벡터 생성 후 크기를 4로 할당(모든 벡터요소 0으로 초기화)
vector<int>v = {1,2,3}; //int형 벡터 생성 후 1,2,3 으로 초기화
vector<int>v[] = {{1,2},{3,4}}; //int형 벡터 배열 생성(행은 가변이지만 열은 고정)
vector<vector<int>> v; //2차원 벡터 생성(행과 열 모두 가변)
vector<int> v = {1,2,3,4,5}; // 벡터 범위를 5로 지정하고 정수 10으로 초기화
v.assign(5,10); // output:10 10 10 10 10
```



### Vector의 iterators

| v.begin()                 | 벡터 시작점의 주소 값 반환              |
| ------------------------- | --------------------------------------- |
| v.end()                   | 벡터(끝부분 + 1) 주소 값 반환           |
| v.rbegin() (revers begin) | 벡터의 끝 지점을 시작점으로 반환        |
| v.rend() (revers end)     | 벡터의 (시작+1) 지점을 끝 부분으로 반환 |

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1,2,3,4,5}
    // for_each(시작 주소값,요소의 마지막 다음 null or 쓰레기 값의 주소, 사용자가 정의한 함수or 함수 객체)
    for_each(v.begin(),v.end(),[&](int& n){
       cout << n << endl; // lamda
    });
    return 0;
}
```



### Vector의 Element access (벡터의 요소 접근)

| v.at(i)             | 벡터의 i번째 요소 접근(범위 검사함)    |
| ------------------- | -------------------------------------- |
| v.[i] (operator []) | 벡터의 i번째 요소 접근(범위 검사 안함) |
| v.front()           | 벡터의 첫번째 요소 접근                |
| v.back()            | 벡터의 마지막 요소 접근                |

```c++
vector<int> v = { 1, 2, 3, 4};

cout << v.front() << endl;        //output : 1
cout << v.back() << endl;        //output : 4
cout << v.at(1) << endl;        //output : 2
cout << v[2] << endl;            //output : 3
```



### Vector에 요소 삽입

| v.push_back()                                     | 벡터의 마지막 부분에 새로운 요소 추가                        |
| ------------------------------------------------- | ------------------------------------------------------------ |
| v.pop_back()                                      | 벡터의 마지막 부분 제거                                      |
| v.insert(삽입할 위치의 주소 값, 변수 값)          | 사용자가 원하는 위치에 요소 삽입                             |
| v.emplace(삽입할 위치의 주소 값, 변수 값)         | 사용자가 원하는 위치에 요소 삽입(move로 인해 복사 생성자 X)  |
| v.emplace_back()                                  | 벡터의 마지막 부분에 새로운 요소 추가(move로 인해 복사생성자 X) |
| v.erase(삭제할 위치) or v.erase(시작위치, 끝위치) | 사용자가 원하는 index값의 요소를 지운다.                     |
| v.clear()                                         | 벡터의 모든 요소를 지운다.(return size = 0)                  |
| v.resize(수정 값)                                 | 벡터의 사이즈를 조정한다.(범위 초과시 0으로 초기화)          |
| v.swap(벡터 변수)                                 | 벡터와 벡터를 스왑한다.                                      |

```c++
#include <vector>

int main(){
    vector<int> v;

    v.push_back(10);
    v.push_back(20);        //v = { 10, 20 }

    v.inset(v.begin() + 1, 100);     // v = { 10, 100, 20 }

    v.pop_back();        // v = { 10, 100 }

    v.emplace_back(1); //v = { 10, 100, 1 }
    v.emplace_back(2);    //v = { 10, 100, 1, 2 }
    v.emplace(v.begin() + 2, -50);    //v = { 1, 100, -50, 1, 2 }

    v.erase(v.begin() + 1); // v = { 1, -50, 1, 2 }
    v.resize(6);    // v = { 1, -50, 1, 2, 0, 0 }
    v.clear();    // v = empty()     
}

```

##### 짚고 넘어가야 할 부분 (vector에 대한 복사생성자와 move 이다.)

- 기본적으로 push_back() 함수는 값을 넣는 과정에서 복사생성자를 호출하게 된다. 또한 insert를 하게 된다면 모든 값들을 새로운 메모리에 복사한 후 해당 자리에 값을 넣게 된다. 이렇게 되면 복사생성자로 인한 오버헤드가 커지게 되며 성능 저하를 야기한다.
- 그래서 나온 것이 emplace와 emplace_back이다.

- empace와 emplace_back은 벡터 내부에서 값들을 생성하는 것이다. 즉 생성자만 호출이 된다.

```C++
#include <iostream>
#include <vector>
#include <string>

class A {
private:
    int num;
    std::string name;
public:
    A(int i, std::string s) : num(i), name(s) {}
};

int main(void) {
    std::vector<A> v;	// 클래스를 담을 수 있는 벡터
    A a(1, "hwan");	
    
    v.push_back(1, "hi");   //error -> v.push_back(a);
    v.emplace_back(1, "hi"); //ok!!
    
    return 0;
}
```

- v.push_back 은 삽입이 되지 않는다. push_back은 내부적으로 템플릿<T>에 대한 생성자 호출을 지원하지 않기 때문이다.

- emplace_back() 같은 경우 되는 이유는 내부적으로 템플릿<T>에 대한 생성자 호출을 해주기 때문에 편하고, 복사 생성자의 호출없이 바로 입력 가능
- push_back 보단 emplace_back사용을 권장



### Vector Capacity(벡터 용량)

| v.empty()         | 벡터가 빈공간이면 true, 아니면 false               |
| ----------------- | -------------------------------------------------- |
| v.size()          | 벡터의 크기 반환                                   |
| v.capacity()      | heap에 할당된 벡터의 실제크기(최대크기) 반환       |
| v.max_size()      | 벡터가 system에서 만들어 질 수 있는 최대 크기 반환 |
| v.reserve(숫자)   | 벡터의 크기 설정                                   |
| v.shrink_to_fit() | capacity의 크기를 벡터의 실제 크기에 맞춤          |


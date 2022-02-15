### 뮤텍스(mutex)

- 뮤텍스는 다른 스레드가 공유자원에 접근을 하지 못하게 만드는 동기화 객체이다. 공유 자원에 접근하기 위해서는 mutex에 대한 잠금을 획득하고, 접근 후에는 잠금을 해제 해야 한다.

- lock은 이러한 mutex를 기반으로 잠글 수 있는 기능을 캡슐화 한 객체이다. 쉽게 생각하면 자물쇠가 lock이고, 자물쇠의 열쇠 구멍을 mutex라고 생각 할 수 있다.

#### 1. 경쟁 상태 (Race Condition)

- 서로 다른 쓰레드에서 같은 메모리를 공유할 때 발생할 수 있는 문제



#### 2. std::lock

```c++
#include <iostream>
#include <mutex>

std::mutex m1, m2;
int main() {
   std::thread th([&]() {
   std::lock(m1, m2);
   std::cout << "th1" << std::endl;
   m1.unlock();
   m2.unlock();
   });
   std::thread th2([&]() {
   std::lock(m1, m2);
   std::cout << "th2" << std::endl;
   m1.unlock();
   m2.unlock();
   });

   std::cout << "hello" << std::endl;
   th.join();
   th2.join();
}
```

- std::lock은 여러개의 뮤텍스를 한번에 잠글 수 있도록 도와준다.



#### 3. std::lock_guard

- 많이 쓰이는 락 종류로써 다음처럼 객체 생성 시에 lock되며 객체가 소멸시에 unlock되는 특성을 가지고 있다.

```c++
#include <iostream>
#include <thread>
#include <mutex>

std::mutex m1;
int main() {
   std::thread th([&]() {
   std::lock_guard<std::mutex> lock_guard(m1);
   for (int i = 0; i < 100; i++) {
   std::cout << "th1" << std::endl;
   }
   });
   std::thread th2([&]() {
   std::lock_guard<std::mutex> lock_guard(m1);
   for (int i = 0; i < 100; i++) {
   std::cout << "th2" << std::endl;
   }
   });

   std::cout << "hello" << std::endl;
   th.join();
   th2.join();
}
```




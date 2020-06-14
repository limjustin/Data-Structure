# Data Structure Chapter 02

### Performance Analysis

### 성능이란 무엇인가

#### "최악의 경우의 성능을 보장해 주어야 한다."

#### "공간 복잡도보다 시간 복잡도가 더 중요하다."



#### 성능(Performance)

- 동일한 **성과(Solution)**를 도출하기 위해서 요구되는 **자원(Resource)**의 크기
- Performance = Solution / Resource
  - 효율적(Efficient) : Solution 고정 시, Resource가 얼마나 적은 자원을 요구하냐?
  - 효과적(Effective) : Resource 고정 시, Solution이 어느정도냐?



#### 공간에 관련된 성능 - 공간 복잡도(Space Complexity)

- 특정한 프로그램을 수행하는 데 요구되는 **메모리**

#### 시간에 관련된 성능 - 시간 복잡도(Time Complexity)

- 특정한 프로그램을 수행하는 데 요구되는 **시간**



### 점근적 분석법

#### "성능은 입력의 크기(n)에 따라 결정된다."

#### "시간 복잡도는 매우 큰 입력에 대해서 측정한다."

![function_fg](https://user-images.githubusercontent.com/55044278/84584809-e1a5c200-ae43-11ea-83c2-6a45f55aea95.PNG)

- 동일한 입력의 크기(n)를 처리할 때, g(n)은 f(n)보다 **더 많은 시간을 요구함**
- 따라서 g(n)은 f(n)보다 **성능이 나쁨**
  - g(n) >= f(n)
  - g(n) is the worst case of f(n)
  - f(n) is better than g(n)
  - The upper bound of f(n) is g(n)
- g(n)은 **f(n)의 성능**을 나타내는 척도로 사용됨
- 많이 사용되는 **표준적인 함수**를 이용 (1, n, log n, n^2, n log n, e^n, n^n)



### Big-O 표기법

![big-o-notation](https://user-images.githubusercontent.com/55044278/84584791-b622d780-ae43-11ea-9ac8-c8d23e917b71.PNG)

- f(n) = O(g(n))의 의미
  - f(n)은 g(n)보다 빠르다
  - g(n)은 f(n)보다 느리다 -> g(n) = Ω(f(n))
- f(n) = O(g(n))인 동시에, f(n) = Ω(g(n))일 경우
  - f(n) = Θ(g(n))이라고 하며, f(n)과 g(n)은 동일한 비율로 증가한다고 함 (tight bound)



### Big-O 표기법의 예

#### i) g(n) = 1

- f(n) = O(1) // 상수 시간 복잡도

  ```c
  void func(int n) {
      printf("Hello World!");
  }
  ```

  - n = 1일 때 1번 / n = 10일 때 1번 / n = 100일 때 1번

#### ii) g(n) = n

- f(n) = O(n) // 선형 시간 복잡도

  ```c
  void func(int n) {
      i = 0;
      while(i < n) {
          printf("Hello World!");
          i++;
      }
  }
  ```

  - n = 1일 때 1번 / n = 10일 때 10번 / n = 100일 때 100번

#### iii) g(n) = n^k

- f(n) = O(n^2), if k = 2 // 다항 시간 복잡도

  ```c
  void func(int n) {
      for(i = 0; i < n; i++) {
          for(j = 0; j < n; j++) {
              printf("Hello World!");
          }
      }
  }
  ```

  - n = 1일 때 1번 / n = 10일 때 100번 / n = 100일 때 10000번

#### iv) g(n) = k^n

- f(n) = O(2^n), if k = 2 // 지수 시간 복잡도

  ```c
  int func(int n) {
      if (n == 0)
          return 0;
      if (n == 1)
          return 1;
      
      return func(n - 1) + func(n - 2);
  }
  ```

  - n = 1일 때 2번 / n = 10일 때 2^10번 / n = 100일 때 2^100번

#### v) g(n) = log k n

- f(n) = O(log n), if k = 2 // 로그 시간 복잡도

  ```c
  int func(int n) {
      for(k = 1; k < n; k = k * 10)
          printf("Hello World!");
  }
  ```

  - n = 1일 때 0번 / n = 10일 때 1번 / n = 100일 때 2번

#### vi) g(n) = n log n

- f(n) = O(n log n), if k = 2

  ```c
  void func(int n) {
      for(i = 1; i <= n; i++) {
          for(j = 1; j <= n; j = j * 10) {
              printf("Hello World!");
          }
      }
  }
  ```

  - n = 1일 때 0번 / n = 10일 때 10번 / n = 100일 때 200번



##### 어려웠던 문제

다음 코드의 시간 복잡도를 Big-O 표기법으로 나타내시오.

```c
void func(int n) {
    int i = 1, s = 1;
    while(s < n) {
        s = s + i++;
        printf("*");
    }
}
```

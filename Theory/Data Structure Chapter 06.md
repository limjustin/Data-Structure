## Data Structure Chapter 06

### Sorting

**정의**

- 데이터를 정해진 키에 따라서 **크기 순으로 배열**하는 것

**정렬 알고리즘의 성능**

- O(n^2) 정렬 알고리즘
  - 버블 정렬, 삽입 정렬, 선택 정렬 등
- O(n log n) 정렬 알고리즘
  - 합병 정렬, 쾌속 정렬 등



#### 삽입 정렬 (Insertion Sort)

**개념**

- 배열의 가장 앞자리로부터 **정렬된 부분 배열**을 생성하고 그 크기를 증가시킴
- 새로운 원소를 **정렬된 부분 배열의 알맞은 위치에 삽입**하여 부분 배열의 **정렬을 유지함**

**알고리즘**

- 배열의 원소를 하나씩 **부분 배열에 삽입**하면서 **정렬을 수행**

- **정렬이 끝난** 배열의 앞 부분을 **부분 배열**로 이용

- 부분 배열 a[0 ... k-1]에 대해서 (k+1)번째 원소인 a[k]를 a[0 ... k-1]에 삽입

  ```c++
  void insert(int x, int n, int a[]) {
      int i, j;
      
      // 1. 정렬된 부분 배열 내 새로운 원소가 들어갈 적절한 위치를 찾기
      for(i = 0; i < n; i++) {
          if(a[i] > x)
              break; // 해당하는 index에서 break
      }
      
      // 2. 부분 배열 내 원소들의 이동
      for(j = n-1; j >= i; j--) { // 부분 배열의 끝부터 i까지 수행
          a[j+1] = a[j];
      }
      
      // 3. 새로운 원소를 해당하는 위치에 삽입 후, 부분 배열 정렬 완료
      a[i] = x;
      return;
  }
  
  void insertion_sort(int n, int a[]) {
      int i;
      
      for(int i = 1; i < n; i++)
          insert(a[i], i, a);
  } 
  ```

  **실행 예**

  ![Insertion_Sort](https://user-images.githubusercontent.com/55044278/85304485-c6435280-b4e6-11ea-9a76-524c008cad83.PNG)

**성능 분석**

- insert( )의 수행 시간 = O(n)
- insert( )를 호출하는 횟수 = O(n)
- **결과 : O(n^2)**



#### 버블 정렬 (Bubble Sort)

**개념**

- 배열의 **가장 앞자리에 최소값**을 옮김
- 배열의 **가장 뒷자리부터** 원소들을 차례대로 **비교**
- 거품이 마치 **물 밑에서 올라오는 것**과 비슷하다는 것에서 유래 (혹은 Sinking Sort라고도 함)

**알고리즘**

- 배열의 i번째 위치에 i ~ (n-1)의 원소들 중에서 가장 작은 값이 옴

- i번째에는 i번째 작은 값이 옴

- (n-1)번째부터 (i+1)번째까지 진행 (밑에서부터 올라옴)

  ```c++
  void swap(int* a, int* b) {
      int temp;
      temp = *a;
      *a = *b;
      *b = temp;
  }
  
  void bubble_sort(int n, int a[]) {
      int i, j;
      for(i = 0; i < n-1; i++) { // i번째 자리
          for(j = n-1; j > i; j--) { // 맨 뒤에서부터 비교
              if(a[j-1] > a[j]) // 앞의 원소가 더 클때 SWAP
                  swap(a[j-1], a[j]); // 한 번도 swap을 호출하지 않을 때는 바로 정렬 종료 가능함
          }
      }
  }
  ```

  **실행 예**

  ![Bubble_Sort](https://user-images.githubusercontent.com/55044278/85304504-cba09d00-b4e6-11ea-9b7a-b0f649a1f8c4.PNG)

**성능 분석**

- 안 쪽 for-loop의 수행 횟수 = n(n-1) / 2

  - i = 0일 때 n-1번 수행

  - i = 1일 때 n-2번 수행

    ​            ........

  - i = n-2일 때 1번 수행

- 가장 Best Case는 대부분 오름차순으로 정렬되어 있는 배열일 때 (ex) 5 82 61 30 74)

- 가장 Worst Case는 대부분 내림차순으로 정렬되어 있는 배열일 때 (ex) 82 61 74 30 5)

- **결과 : O(n^2)**



#### 선택 정렬 (Selection Sort)

**개념**

- 배열의 i번째 자리에 i번째 최소값을 옮김
- 배열의 s번째와 e번째 원소 사이에서 **가장 작은 원소의 인덱스를 찾는 연산**이 필요

**알고리즘**

- 정렬하고자 하는 배열의 첫 번째 원소부터 차례대로 방문

- a[i] ~ a[n-1] 중에서 최소값과 a[i]의 값을 교환할 것임 (**인덱스**를 찾아서 교환할 예정)

  ```c++
  int select_min(int s, int e, int b[]) {
      int min_idx = s;
      for(int i = s+1; i <= e; i++) {
          if(b[i] < b[min_idx])
              min_idx = i;
      }
      return min_idx;
  }
  
  void selection_sort(int n, int a[]) {
      int i;
      int min_idx;
      for(i = 0; i < n-1; i++) {
          min_idx = select_min(i, n-1, a);
          swap(a[i], a[min_idx]);
      }
  }
  ```

  **실행 예**

  ![Selection_Sort](https://user-images.githubusercontent.com/55044278/85304508-cd6a6080-b4e6-11ea-9023-4513b5e1e4e1.PNG)

**성능 분석**

- select_min( ) 함수를 n개에 대해서 수행
- select_min( ) 함수를 O(n)번 수행 -> Worst Case일 경우에도 항상 O(n)번 수행하게 됨
- **결과 : O(n^2)**



#### ※ 분할 정복

- **Divide & Conquer**
- **분할 정복의 3단계**
  - **분할(Divide)** : 주어진 집합의 데이터를 적절한 크기의 부분 집합으로 나눔
  - **정복(Conquer)** : 부분 집합에서 문제를 해결
  - **결합(Combine)** : 해결된 부분 해를 합쳐서 주어진 집합의 해를 구함

![image-20200622161940937](C:\Users\user\AppData\Roaming\Typora\typora-user-images\image-20200622161940937.png)

- Divide & Conquer 



#### 합병 정렬 (Merge Sort)

**개념**

- 정렬된 2개의 리스트를 하나의 정렬된 리스트로 합병
- 1개의 원소를 가진 정렬된 리스트 n개
- 정렬된 리스트를 합병해서 해결

**과정**

1. 분할
   - n개의 원소를 가진 배열을 2개로 **분할**
   - 더 이상 분할할 수 없을 때까지 **분할을 반복** (**원소가 1개**가 될 때까지)
2. 정복
   - **더 이상 분할할 수 없는** 배열은 **정렬된 것**으로 간주
3. 결합
   - 정렬된 배열을 **합병**해서 **더 큰 정렬된 배열**을 생성
   - n개의 원소를 가진 **정렬된 배열**까지 **합병**을 계속 진행

**알고리즘**

- 재귀 호출을 이용

- 정렬할 배열을 전역 변수로 선언하고 시작 인덱스(s)와 종료 인덱스(e) 사용

  ```c++
  #define MAX_SIZE 8
  int sorted[8]; // 정렬할 배열
  
  void merge(int list[], int ls, int m, int rs) {
      int lptr = ls;
      int rptr = m + 1;
      int k = ls; // 정렬할 배열의 중심이 될 index
      
      // 정렬된 2개의 리스트를 비교하여 하나의 정렬된 리스트로 합병 - 결합 과정
      while(lptr <= mid && rptr <= rs) {
          if(list[lptr] < list[rptr])
              sorted[k++] = list[lptr++];
          else
              sorted[k++] = list[rtpr++];
      }
      
      // 남은 배열 채우기
      if(lptr > mid)
          for(int i = rptr; i <= rs; i++)
              sorted[k++] = list[i];
  	// 남은 배열 채우기
      if(rptr > rs)
          for(int i = lptr; i <= mid; i++)
              sorted[k++] = list[i];
      
      // 정렬된 배열(sorted)의 결과를 본 배열(list)로 재복사
      for(int l =ls; l <= rs; l++)
          list[l] = sorted[l];
  }
  
  void merge_sort(int list[], int s, int e) {
      // 예외 처리 - 정복 과정
      if(s == e) 
          return;
      
      // 분할 과정
      int mid = (s + e) / 2;
      merge_sort(list, s, mid);
      merge_sort(list, mid + 1, e);
      merge(list, s, mid, e);
  }
  ```

  **실행 예**

  ![Merge_Sort](https://user-images.githubusercontent.com/55044278/85304524-d0655100-b4e6-11ea-97a0-8ef1aae4c7ff.PNG)

**성능 분석**

- 분할 = O(n)
- 정복 = O(1)
- 결합 = O(n log n)
- **결과 : O(n log n)**


#### 쾌속 정렬 (Quick Sort)

**개념**

- **분할 정복** 구조의 정렬 알고리즘
- 하지만 **결합을 요구하지 않도록** 리스트를 적절하게 분할하는 방법을 적용함
- 기준이 되는 값인 **Pivot**이 있음

**알고리즘**

- 왼쪽에는 pivot보다 작은 수만 배치 / 오른쪽에는 pivot보다 큰 수만 배치

- item**FromLeft** that is **larger that Pivot** / item**FromRight** that is **smaller than Pivot**, and **swap** it

  ```c++
  #define MAX_SIZE 8
  
  int split(int list[], int s, int e) {
      int pivot, lptr, rptr;
      lptr = s + 1;
      rptr = e;
      pivot = list[s]; // 가장 앞에 있는 원소를 pivot으로 정함
      
      while(lptr <= rptr) {
          while((list[rptr] >= pivot) && (lptr <= rptr)) // itemFromRight that is smaller than Pivot
              rptr--;
          while((list[lptr] <= pivot) && (lptr <= rptr)) // itemFromLeft that is larger than Pivot
              lptr++;
          if(lptr <= rptr)
              swap(&list[lptr], &list[rptr]); // and swap it
      }
      swap(&list[rptr], &list[s]); // Change 'smaller than Pivot' with Pivot
      return rptr;
  }
  
  void quick_sort(int list[], int s, int e) {
      // 예외 처리
      if(s >= e)
          return;
      
      int mid = split(list, s, e);
      quick_sort(list, s, mid - 1);
      quick_sort(list, mid + 1, e);
  }
  ```

  **실행 예**

  ![Quick_Sort](https://user-images.githubusercontent.com/55044278/85304517-ce9b8d80-b4e6-11ea-9bf1-e5498e2bcc92.PNG)

**성능 분석**

- **결과 : O(n log n)**

- but Worst Case일 때는, **O(n^2)**

  ex) 1 2 3 4 5 6 7 8 혹은 8 7 6 5 4 3 2 1 처럼 **정렬이 이미 되어있는 배열**일 때



#### 기타 정렬

- 쉘(Shell) 정렬
  - 배열을 여러 개의 부분 배열로 분할하여 각각 삽입 정렬을 수행
  - 정렬된 부분 배열을 통합하면서 삽입 정렬을 반복해서 수행
- 기수(Radix) 정렬
  - 정렬할 원소를 버킷에 분배하는 과정을 반복해서 정렬을 수행
- 팀(Tim) 정렬
- 인트로(Intro) 정렬
- 카운트(Count) 정렬
  - 데이터에 대한 count를 증가
- 보고(Bogo, Stupid, Monkey) 정렬
  - 비효율적인 알고리즘
- 슬립(Sleep) 정렬
  - 쓰레드의 슬립을 이용한 정렬
- 버켓(Bucket) 정렬
  - 전체 데이터를 bucket에 저장한 후, bucket 내부의 데이터를 정렬하고 bucket을 합병하는 정렬



#### 정렬의 성질

1. Comparison

   - 데이터에 대한 비교를 이용하는 정렬
   - 비교 정렬이 아닌 알고리즘 : 기수 정렬, 슬립 정렬, 보고 정렬, 카운트 정렬

2. Adaptive

   - 부분적으로 정렬된 데이터에 대해서 더 좋은 성능을 보이는 정렬

   - Adaptive하게 발전시킬 수 있는 정렬 : 버블 정렬

     ex) 1 2 3 4 5 8 7 6

3. Stable

   - 같은 값을 포함한 배열의 정렬

   - Stable하지 않은 정렬 : 선택 정렬

     ex) *5* 2 *5* 1 8 9 7

4. In-place

   - 추가적으로 요구하는 메모리가 O(1)인가?

   - Quick Sort와 Merge Sort는 System Stack을 사용

     Recursive Call을 사용하기 때문

5. Online

   - 계속 증가하는 데이터에 대해서도 정렬이 가능한가?
   - Insertion Sort, Bubble Sort는 중간에 데이터가 들어와도 정렬 가능
   - Selection Sort는 중간에 데이터가 들어오면 처음부터 다시해야 함



#### **정렬의 성능 분석 표**

![sort](https://user-images.githubusercontent.com/55044278/85304534-d22f1480-b4e6-11ea-8529-a2ac2d1762c8.PNG)

- 삽입, 선택, 버블 정렬에서 시간 차이가 발생하는 이유
  - **삽입 정렬**은 Swap을 사용하지 않음
  - **선택 정렬**은 Swap하는데 O(n)이 소요됨
  - **버블 정렬**은 Swap하는데 O(n^2)이 소요됨
  - 결론 : **Swap하는데 소요되는 시간**에 따라서 차이가 발생하게 됨

## Data Structure Chapter 03

### Array

#### 리스트

- 유한한 원소들의 나열
- 리스트의 구현 방법
  - 배열(Array) : 인덱스에 기반한 구현
  - 연결 리스트(Linked list) : 포인터에 기반한 구현 (연속된 공간 아님)

- 자료의 관리
  - 삽입(insert)
  - 제거(delete)
  - 검색(search)



#### 배열

- **연속적**으로 할당된 기억 공간
- 모든 원소들은 **인덱스**에 대응됨
- n개의 자료를 하나의 **주소**로 접근할 수 있음

- 배열과 친구들
  - arr : 배열
  - size : 배열의 크기 (할당받은 메모리의 크기)
  - count : 현재 배열에 저장된 원소의 수



#### 검색

- 선형 검색 (Linear Search)

  - 배열의 **첫 번째 원소부터** 차례로 방문하면서 key element와 동일한 원소가 있는지 확인

  - 정렬되지 않은 배열에서도 적용할 수 있음

    ```c
    index linear_search(Array arr, elt x) {
        for(int i = 0; i < count; i++) {
        	if(arr[i] == x)
            	return i;
    	}
    	return -1;
    }
    ```

    시간 복잡도 : **O(n)**

    - 최악의 경우 : O(n)
    - 평균의 경우 : O(n/2) = O(n)
    - 최선의 경우 : O(1)

- 이진 검색 (Binary Search)

  - **분할 정복(Divide & Conquer)** 알고리즘

  - 배열의 중간 원소와 key element를 비교하여 배열을 분할함으로써 탐색을 재귀적으로 수행

  - **정렬된 배열**에서만 적용할 수 있음

    ``` c
    index binary_search(Array arr, index s, index e, elt x) {
        if(s == e)
            return (arr[s] == x) ? s : -1;
        int mid = (s + e)/2;
        if(x == arr[mid])
            return mid;
        else if(arr[mid] > x)
            return binary_search(arr, s, mid-1, x);
        else
            return binary_search(arr, mid+1, e, x);
    }
    ```

    시간 복잡도 : **O(log n)**



#### 추가

1. x를 추가할 위치를 결정

2. 추가할 위치에 원소를 옮겨서 공간을 확보

3. 원소를 추가

4. 배열의 크기(count)를 증가

   ```c
   Array insert_by_value(Array arr, elt x) {
       // 1. x를 추가할 위치를 결정
       for(int i = 0; i < count; i++) {
           if(arr[i] > x)
               break;
       }
       
       // 2. 추가할 위치의 원소를 옮겨서 공간을 확보
       for(int j = n-1; j >= i; j--) {
           a[j+1] = a[j];
       }
       
       // 3. 원소를 추가
       arr[i] = x;
       
       // 4. 배열의 크기 (count)를 증가
       count++;
       return arr;
   }
   ```

   시간 복잡도 : **O(n)**

   1. x를 추가할 위치를 결정 -> O(k) // 왜냐하면 자리만 찾으면 되거든
   2. 추가할 위치에 원소를 옮김 -> O(n-k) // 나머지 배열들에 대해서 작업하는 것들이니까
   3. 원소를 추가 -> O(1)
   4. 배열의 크기를 증가 -> O(1)



#### 제거

1. 제거할 원소(x)를 배열(arr)에서 찾음

2. 제거할 원소 뒤에 있는 원소들을 앞으로 이동

3. 배열의 크기(count)를 감소

   ```c
   Array delete(Array arr, elt) {
       // 1. 제거할 원소를 배열에서 찾음
       for(int i = 0; i < count; i++) {
           if(arr[i] == x)
               break;
       }
       if(i == count)
           return;
       
       // 2. 제거할 원소 뒤에 있는 원소들을 앞으로 이동
       for(int j = i; j < count - 1; j++) {
           arr[j] = arr[j+1];
       }
       
       // 3. 배열의 크기 감소
       count--;
       
       return arr;
   }
   ```

   시간 복잡도 : **O(n)**

   1. 제거할 원소를 배열에서 찾음 -> O(k)
   2. 제거할 원소 뒤에 있는 원소들을 앞으로 이동 -> O(n-k)
   3. 배열의 크기를 감소 -> O(1)



#### 배열에서의 시간 복잡도 정리

![image-20200614192108395](C:\Users\user\AppData\Roaming\Typora\typora-user-images\image-20200614192108395.png)
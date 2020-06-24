## Data Structure Chapter 07

### 트리 (Tree)

**정의**

- **루트(root)**라고 불리우는 특별한 노드가 있음

- 연결된 모든 노드의 쌍은 재귀적으로 **부모-자식 관계(parent-child relation)**을 맺고 있음

- **순환하는 경로(cycle path)가 없음**

- 트리의 자료 구조 (포인터 기반)

  ```c++
  typedef class node *nptr;
  class node {
      data_type data; // 저장할 데이터
      int n_childs; // 자식 노드의 수
      nptr* childs; // 자식 노드에 대한 포인터
  }
  ```



### 이진 트리 (Binary Tree)

**정의**

- Degree가 2인 트리

- 최대 노드의 수는 2개

  ```c++
  typedef class node *nptr;
  class node {
      data_type data;
      nptr lchild, rchild;
  }
  ```



**성질**

- **i번째 레벨**의 **최대 노드**의 수는 **2^(i-1)** 개

  ![ilevelmaximumnode](https://user-images.githubusercontent.com/55044278/85543008-a2058400-b654-11ea-81ee-a8b05d0cb4f4.PNG)


- **Depth가 k**인 이진 트리의 **최대 노드**의 수는 **2^k - 1** 개

  ![depthkmaximun](https://user-images.githubusercontent.com/55044278/85543032-a6ca3800-b654-11ea-9d77-0784f1d0f544.PNG)


- 원소가 있는 이진 트리에 대해서 n0을 leaf node의 수, n2를 degree가 2인 노드의 수라고 하면 **n0 = n2 + 1**이 성립

  ![n0isn2plust1](https://user-images.githubusercontent.com/55044278/85543058-ad58af80-b654-11ea-9f2e-6f8efc1a4e19.PNG)




**특별한 이진 트리**

1. **포화 이진 트리 (Full binary tree)**

   - Depth가 k일 때 2^k - 1 개의 노드를 갖는 이진 트리

     ![fullbinarytree](https://user-images.githubusercontent.com/55044278/85543085-b3e72700-b654-11ea-8cc3-c91b87768e9b.PNG)


2. **완전 이진 트리 (Complete binary tree)**

   - 같은 Depth를 갖는 포화 이진 트리와 노드들 사이에 1:1 대응이 성립하는 이진 트리

   - **Depth가 k인 완전 이진 트리**의 노드 수를 n이라고 하면 **A <= n <= B**를 만족할 수 있는 A와 B는 => **A = 2^(k-1) - 1, B = 2^k - 1** (**k-1층과 k층 사이**에 어떤 값이든 가지면 됨)

     ![completebinarytree](https://user-images.githubusercontent.com/55044278/85543105-b9447180-b654-11ea-8967-021f5f0b53a7.PNG)






### 트리 탐색 (Tree Search)

**정의**

- **Root node로부터 시작**해서 **트리의 모든 노드를 방문**하는 연산
- 모든 트리에서 적용되는 일반적인 탐색
  - 깊이 우선 탐색 (Depth-First Search, DFS)
  - 넓이 우선 탐색 (Breadth-First Search, BFS)
- 이진 트리에만 적용되는 특별한 탐색



**이진 트리에서의 탐색**

- 노드와 그 자식 노드를 방문하는 순서에 따라서 3가지로 나뉨

  1. **중위 우선 탐색 (Inorder Traversal)**

     - 순서 : 왼쪽 - > **부모** -> 오른쪽

       ![inorder](https://user-images.githubusercontent.com/55044278/85543193-cc574180-b654-11ea-8705-b311f88ffb69.PNG)


       ```c++
       void inorder(nptr bt) {
           if(bt) {
               inorder(bt->lchild);
               print(bt->data);
               inorder(bt->rchild);
           }
       }
       ```

       

  2. **전위 우선 탐색 (Preorder Traversal)**

     - 순서 : **부모** -> 왼쪽 -> 오른쪽

       ![preorder](https://user-images.githubusercontent.com/55044278/85543214-d0835f00-b654-11ea-8f0f-6d7fbc158345.PNG)


       ```c++
       void preorder(nptr bt) {
           if(bt) {
               print(bt->data);
               preorder(bt->lchild);
               preorder(bt->rchild);
           }
       }
       ```

       

  3. **후위 우선 탐색 (Postorder Traversal)**

     - 순서 : 왼쪽 -> 오른쪽 -> **부모**

       ![postorder](https://user-images.githubusercontent.com/55044278/85543223-d24d2280-b654-11ea-975b-ed03d5160e55.PNG)


       ```c++
       void postorder(nptr bt) {
           if(bt) {
               postorder(bt->lchild);
               postorder(bt->rchild);
               print(bt->data);
           }
       }
       ```



### 이진 탐색 트리 (Binary Search Tree)

**정의**

- 이진 탐색 과정에서 분할되는 배열을 이진 트리에 대응시킨 구조
- 다음의 조건을 만족시켜야 함
  - 모든 노드는 **서로 다른 하나의 값(key)**을 저장함
  - **왼쪽 subtree**의 값들은 루트 노드의 값보다 **더 작음**
  - **오른쪽 subtree**의 값들은 루트 노드의 값보다 **더 큼**
  - 왼쪽 subtree와 오른쪽 subtree는 **이진 탐색 트리**임

- 좋은 이진 탐색 트리
  - **균형(Balanced)** 이진 탐색 트리 : |depth(left) - depth(right)| <= 1
  - 최선의 경우 시간 복잡도 : O(log n)
- 나쁜 이진 탐색 트리
  - **편향(Skewed)** 이진 탐색 트리
  - 최악의 경우 시간 복잡도 : O(n)



**생성(초기화)**

- 이진 탐색 트리의 자료 구조

  ```c++
  typedef class node* nptr;
  class node {
      data_type key;
      nptr lchild, rchild;
  }
  ```

- 초기화

  - root node를 선언
  - 원소가 없는 이진 탐색 트리는 root node의 key를 원소로 사용되지 않을 값(예: -1)로 초기화



#### **검색 (Search)**

- 이진 트리 탐색에서 원하는 원소(x)를 찾는 연산

- 루트 노드에서부터 시작

- **알고리즘**

  - **x == root->key** 일 때는 **원하는 원소**를 찾은 경우

  - **x < root->key** 일 때는 **왼쪽 서브 트리**로 이동

  - **x > root->key** 일 때는 **오른쪽 서브 트리**로 이동

    ```c++
    void node::search(int x) {
        if(x == this->key)
            printf("Bingo!! \n");
        
        else if(x < this->key) {
            if(this->lchild != NULL) // subtree가 NULL이 아닐 때 계속 진행
                this->lchild->search(x);
            else
                printf("Not Found! \n");
        }
        
        else { // Case of (x > this->key)
            if(this->rchild != NULL) // subtree가 NULL이 아닐 때 계속 진행
                this->rchild->search(x);
            else
                printf("Not Found! \n");
        }    
    }
    ```

- **시간 복잡도**

  - 최선의 경우 (Balanced)
    - 이진 탐색 트리의 depth는 **log n**
    - 최악의 경우 검색은 leaf node에서 끝남
    - 시간 복잡도는 **O(log n)**
  - 최악의 경우 (Skewed)
    - 이진 탐색 트리의 depth는 **n**
    - 최악의 경우 검색은 leaf node에서 끝남
    - 시간 복잡도는 **O(n)**



#### **추가 (Insert)**

- 이진 탐색 트리에 **새로운 원소**를 더하는 연산

- 새로운 원소를 저장하는 **노드를 생성**하여 **추가**

- 새로 추가되는 노드는 반드시 **leaf node**

- **알고리즘**

  - **x == root->key** 일 때는 **정의에 위배** (모든 노드는 서로 다른 하나의 값(key)을 저장해야 함)

  - **x < root->key** 일 때는 **왼쪽 서브 트리**로 이동

  - **x > root->key** 일 때는 **오른쪽 서브 트리**로 이동

    ```c++
    void node::insert(int x) {
        // degenerate case - root node에 삽입
        if(this->key == -1) {
            this->key = x;
            return;
        }
        
        // x와 key가 같은 경우
        if(x == this->key) {
            printf("No duplicate Data! \n");
        }
        
        // x가 key보다 작은 경우
        else if(x < this->key) {
            // lchild에 추가
            if(this->lchild != NULL)
                this->lchild->insert(x);
            else { // 아무 것도 없는 경우 새로 생성해 주어야 함
                this->lchild = (nptr) malloc(sizeof(node)); // 동적 할당
                this->lchild->key = x; // 값 대입
                this->lchild->lchild = this->lchild->rchild = NULL;
            }
        }
        
        // x가 key보다 큰 경우
        else {
            // rchild에 추가
            if(this->rchild != NULL)
                this->rchild->insert(x);
            else { // 아무 것도 없는 경우 새로 생성해 주어야 함
                this->rchild = (nptr) malloc(sizeof(node)); // 동적 할당
                this->rchild->key = x; // 값 대입
                this->rchild->lchild = this->rchild->rchild = NULL;
            }        
        }  
    }
    ```

**시간 복잡도**

- 최선의 경우 (Balanced)
  - 이진 탐색 트리의 depth는 **log n**
  - 최악의 경우 검색은 leaf node에서 끝남
  - 시간 복잡도는 **O(log n)**
- 최악의 경우 (Skewed)
  - 이진 탐색 트리의 depth는 **n**
  - 최악의 경우 검색은 leaf node에서 끝남
  - 시간 복잡도는 **O(n)**



#### **제거 (Delete)**

- 이진 탐색 트리의 **노드를 지우는 연산**

- 제거할 노드를 찾아가는 과정은 **재귀적 구조**로 구현됨

- 어떤 노드를 제거하느냐에 따라서 다른 연산 방법이 필요함

- **알고리즘**

  - 재귀적인 구현 원리

    - 함수가 정수형의 리턴값을 갖음
    - 1을 리턴하여 자신을 파괴해달라고 Parent node에 요청
    - 노드는 자기 자신을 파괴할 수 없음

  - 어떤 노드를 제거하느냐의 원리

    1. Leaf node
       - 노드 그냥 제거하면 됨
    2. 한 개의 child node를 갖는 노드
       - 노드를 제거하고 child node로 대체해야 함
    3. 두 개의 child node를 갖는 노드
       - 노드의 키를 left_max(왼쪽 부분 트리의 원소 중 최대값) 혹은 right_min(오른쪽 부분 트리의 원소 중 최소값)으로 대체하고, left_max 혹은 right_min 노드를 제거해야 함

    ```c++
    int node::remove(int x) {
        // 1. x와 key가 같은 경우
        if(x == this->key) {
            // 1-1. 두 child가 다 NULL
            if(this->lchild == NULL && this->rchild == NULL)
                return 1;
            
            // 1-2. lchild만 NULL
            if(this->lchild == NULL && this->rchild != NULL) {
                this->key = this->rchild->key;
                this->lchild = this->rchild->lchild;
                this->rchild = this->rchild->rchild;
                return 0;
            }
            
            // 1-3. rchild만 NULL
            if(this->lchild != NULL && this->rchild == NULL) {
                this->key = this->lchild->key;
                this->lchild = this->lchild->lchild;
                this->rchild = this->lchild->rchild;
                return 0;
            }
            
            // 1-4. 둘 다 NULL이 아닌 경우
            if(this->lchild != NULL && this->rchild != NULL) {
                this->key = this->lchild->get_max(); // lchild 중 최대값으로 교체
                if(this->lchild->remove(this->key) ==  1) // 남아있는 노드 삭제
                    this->lchild = NULL;
                return 0;
            }
        }
        
        // 2. x가 key보다 작은 경우
        else if(x < this->key) {
            if(this->lchild != NULL) {
                if(this->lchild->remove(x) == 1) // 1을 리턴하여 파괴 요청
                    this->lchild = NULL;
            }
            else {
                printf("Not found %d in removing \n", x);
            }
            return 0;
        }
        
        // 3. x가 key보다 큰 경우
        else {
            if(this->rchild != NULL) {
                if(this->rchild->remove(x) == 1) // 1을 리턴하여 파괴 요청
                    this->rchild = NULL;
            }
            else {
                printf("Not found %d in removing \n", x);
            }
            return 0;
        }
    }
    ```

**시간 복잡도**

- 최선의 경우 (Balanced)
  - 이진 탐색 트리의 depth는 **log n**
  - 최악의 경우 검색은 leaf node에서 끝남
  - 시간 복잡도는 **O(log n)**
- 최악의 경우 (Skewed)
  - 이진 탐색 트리의 depth는 **n**
  - 최악의 경우 검색은 leaf node에서 끝남
  - 시간 복잡도는 **O(n)**



### Heap (Priority Queue)

**정의**

- **Priority Queue** 
  - **정의**
    - 가장 **우선 순위가 높은 원소**가 가장 먼저 제거되는 큐
  - **우선 순위 큐의 연산**
    - 추가 (Push)
      - 큐에 **새로운 원소를 삽입**함
      - 새로운 원소의 **위치**는 그 **중요도(Priority)**에 따라서 결정됨
      - 원소를 **중요도**에 따라서 **정렬된 리스트에 추가**함
      - **성능 : O(n)**
    - 제거 (Pop)
      - 큐에서 **가장 우선 순위가 높은 원소**를 삭제함
      - **리스트의 첫 번째 원소**를 제거함
      - **성능 : O(n)**
    - 탑 (Top)
      - 큐에서 **가장 우선 순위가 높은 원소를 찾음** (삭제는 하지 않음)
      - 리스트의 **첫 번째 원소를 리턴**함
      - **성능 : O(1)**

- **Heap** 
  - **정의**
    - **(이진) 트리**를 기반으로 구현된 **우선 순위 큐**
    - **완전 이진 트리** 형태
  - **종류**
    - Max heap : 모든 노드의 값은 자식 노드의 값들보다 큼
    - Min heap : 모든 노드의 값은 자식 노드의 값들보다 작음



**구현**

- 완전 이진 트리에서 각 노드에 위에서 아래로, 왼쪽에서 오른쪽으로 번호를 부여

- 배열에서 첫 번째 원소부터 번호를 부여

  ![heap](https://user-images.githubusercontent.com/55044278/85543273-dd07b780-b654-11ea-937f-fb6e5bf75caa.PNG)


- k번째 노드의 부모 노드 : k/2
- k번째 노드의 왼쪽 child node : 2*k
- k번째 노드의 오른쪽 child node : 2*k + 1

- Heapify 함수

  정의 : k번째 노드로부터 Heap을 재구성할 것

  - 하향식 재구성(Topdown heapify) 알고리즘

    - Leaf node까지 Heap을 재구성

      ```c++
      void heapify_topdown(int idx) {
          // leaf node에 도착하면 끝
          if(2*idx > cnt)
              return;
          if(2*idx == cnt) {
              if(heap[idx] < heap[2*idx])
                  swap(&heap[idx], &heap[2*idx]);
              return;
          }
         	if(heap[2*idx] > heap[2*idx+1] && heap[2*idx] > heap[idx]) {
              swap(&heap[idx], &heap[2*idx]);
              heapify_topdown(2*idx);
          }
         	else if(heap[2*idx+1] > heap[2*idx] && heap[2*idx+1] > heap[idx]) {
              swap(&heap[idx], &heap[2*idx+1]);
              heapify_topdown(2*idx+1);
          }
      }
      ```

  - 상향식 재구성(Bottomup heapify) 알고리즘

    - Root node까지 Heap을 재구성

      ```c++
      void heapify_bottomup(int idx) {
          // root node에 도착하면 끝
          if(idx == 1)
              return;
          if(heap[idx/2] < heap[idx]) {
              swap(&heap[idx/2], &heap[idx]);
              heapify_bottom(idx/2);
          }
      }
      ```

      

#### 추가 (Push)

- 원소를 Heap의 **마지막 위치**에 삽입

- **Bottomup Heapify**를 이용해서 새로운 원소가 삽입된 Heap을 구성

- **알고리즘**

  ```c++
  void push(int ndata) {
      cnt++;
      heap[cnt] = ndata;
      
      heapify_bottomup(cnt);
  }
  ```

  **시간 복잡도 : O(log n)**



#### 제거 (Pop)

- **Root node**에 저장된 **값을 제거**

- **Heap의 마지막 노드에 저장된 값**을 **Root node로** 옮기고 노드를 **제거**

- **Root node**로부터 **Topdown Heapify** 수행

- **알고리즘**

  ```c++
  int pop(void) {
      int temp = heap[1];
      heap[1] = heap[cnt];
      cnt--;
      
      heapify_topdown(1);
      return temp;
  }
  ```

  **시간 복잡도 : O(log n)**



#### Heap Sort

**개념**

- **O(n log n) 정렬 알고리즘**

  - Push **n** times
  - Pop **n** times

  ```c++
  void heap_sort(int* arr, int n) {
      int i;
      for(i = 0; i < n; i++)
          push(arr[i]);
      for(i = 0; i < n; i++)
          printf("%d ", pop());
  }
  ```

  **실행 예**

  ![Heap_Sort](https://user-images.githubusercontent.com/55044278/85543294-e2fd9880-b654-11ea-87e6-f85e2b0692ed.PNG)


- Time complexity of heap sort
  - n times push -> n * O(log n) = **O(n log n)**
  - n times pop -> n * O(log n) = **O(n log n)**
  - In total, **O(n log n)**


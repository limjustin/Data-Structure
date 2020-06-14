## Data Structure Chapter 04

### 연결리스트 (Linked List)

#### 연결리스트

- 원소들이 메모리에서 **임의의 위치**에 배치되어 있음

- 한 원소는 다음 원소를 가리키는 주소(link, pointer)를 가지고 있음 (**포인터 기반**의 자료구조)

  cf) 배열과 연결 리스트의 비교

  ![image-20200614213847887](C:\Users\user\AppData\Roaming\Typora\typora-user-images\image-20200614213847887.png)

- **node = data + link**

  - **node**는 메모리의 임의의 위치에 배치됨
  - 각 node는 다음 node를 가리키는 **link**를 포함하고 있음

- 연결 리스트의 종류

  - **단일 연결 리스트** : 각 node는 하나의 link를 가짐
  - **이중 연결 리스트** : 각 node는 두 개의 link를 가짐

- 연결 리스트의 정의

  ```c
  typedef struct _node node;
  struct _node {
      char ats[3];
      node *link;
  }
  ```



#### 단일 연결 리스트

##### 단일 연결 리스트의 노드 정의

```c++
class node {
    data_type item;
    node *link;
}
```



##### 검색 (Search)

- 찾는 원소(key element)를 저장하고 있는 노드의 **포인터**를 리턴

- 선형 탐색만 가능함

  ```c++
  node *hnode::search(data_type item) {
      return this->link->search(item);
  }
  ```

  ```c++
  node *node::search(data_type item) {
      node *curr = this;
      while(curr != NULL) {
          if(curr->item == item)
              return curr; // Found
          curr = curr->link;
      }
      return NULL; // Not Found
  }
  ```



##### 추가 (Insert)

- 추가할 데이터를 저장하는 **새로운 노드**를 **연결 리스트에 삽입**하는 연산

- Algorithm

  1. 데이터를 추가할 적절한 위치를 결정
  2. 데이터를 저장할 때 새로운 노드를 생성
  3. 새로운 노드가 연결 리스트에 포함되도록 링크를 갱신

  ```c++
  void node::insert(data_type item) {
      // 1. 적절한 위치를 결정
      node *curr = this;
      while(curr->link != NULL) {
          if(curr->link->item > item) // 추가할 데이터보다 작은 원소들 중에서
              break;					// 가장 큰 원소를 고를 것이기 때문!!
          curr = curr->link;
      }
      
      // 2. 새로운 노드를 생성
      node *nnode = new node;
      nnode->item = item;
      
      // 3. 링크를 갱신
      nnode->link = curr->link; // 오른팔 달아주기
      curr->link = nnode; // 왼팔 달아주기
  }
  ```



##### 제거 (Delete)

- 리스트로부터 **원하는 원소의 연결을 해제**하여 리스트에서 그 원소를 삭제하는 연산

- Algorithm

  1. 제거할 원소를 찾음
  2. 링크를 갱신해서 제거할 원소를 리스트에서 분리
  3. 제거된 노드의 메모리를 free함

  ```c++
  void node::delete(data_type item) {
      // 1. 제거할 원소를 찾음
      node *curr = this;
      while(curr->link != NULL) {
          if(curr->link->item == item)
              break;
          curr = curr->link;
      }
      
      /d/ 2. 링크를 갱신
      node *dnode = curr->link; // 제거할 원소를 선택해서 따로 이름을 붙여줌
      curr->link = dnode->link; // 다음 방향인 것 복사 (이어주는 것까지 완료)
      
      // 3. 제거된 node를 free
      free(dnode); // 동적 해제
  }
  ```



#### 이중 연결 리스트

##### 이중 연결 리스트의 노드 정의

```c++
class node {
    data_type item;
    node *llink, *rlink;
}
```



##### 추가 (Insert)

- Algorithm

  1. 데이터를 추가할 적절한 위치를 결정
  2. 데이터를 저장할 새로운 노드를 생성
  3. 새로운 노드가 연결 리스트에 포함되도록 링크를 갱신

  ```c++
  void node::insert(data_type item) {
      // 1. 적절한 위치를 결정
      node *curr = this;
      while(curr->rlink != NULL) {
          if(curr->rlink->item > item)
              break;
          curr = curr->rlink;
      }
      
      // 2. 새로운 노드를 생성
      node *nnode = new node;
      nnode->item = item;
      
      // 3. 링크를 갱신
      // 3.1 rlink 방향
      nnode->rlink = curr->rlink;
      curr->rlink = nnode;
      // 3.2 llink 방향
      nnode->llink = curr;
      nnode->rlink->llink = nnode;
  }
  ```



##### 제거 (Delete)

- Algorithm

  1. 제거할 원소를 찾음
  2. 링크를 갱신해서 제거할 원소를 리스트에서 분리
  3. 제거된 노드의 메모리를 free함

  ```c++
  void node::delete(data_type item) {
      // 1. 제거할 원소를 찾음
      node *curr = first;
      while(curr->rlink != NULL) {
          if(curr->rlink->item == item)
              break;
          curr = curr->rlink;
      }
      
      // 2. 링크를 갱신
      node *dnode = curr->rlink;
      curr->rlink = dnode->rlink;
      curr->rlink->llink = dnode->llink;
      
      // 3. 제거된 node를 free
      free(dnode);
  }
  ```

  

#### 성능 분석

- **시간 복잡도**

  ![timecomplexity in linked list](https://user-images.githubusercontent.com/55044278/84598700-91604b80-aea7-11ea-92aa-dc7515e716ba.PNG)

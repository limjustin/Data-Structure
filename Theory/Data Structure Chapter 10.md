## Data Structure Chapter 10

### DFS (Depth-first search)

**그래프의 탐색 문제**

- 중요한 요소 2가지

  1. 탐색 과정에서 이미 방문한 노드를 기록해야 함

     -> visit 여부를 저장하는 배열

  2. 탐색 과정에서 노드를 방문하는 순서를 기억할 것

     -> stack 혹은 queue의 사용 (DFS는 stack 사용, BFS는 queue 사용)



##### DFS Algorithm

- 각 vertex v에서 할 일

  - 이 vertex를 방문하였는지 여부를 표시 (visited[v] = 1)
  - v에 연결된 vertex 중에서 아직 방문하지 않은 vertex를 방문
  - 더 이상 방문할 vertex가 없다면 return

- stack을 사용

- Pseudo Code

  ```c++
  void dfs(vertex u) {
      visited[u] = 1;
      
      for(w = graph[u]; w != NULL; w = w->link) {
          if(!visited[w]) // 아직 방문하지 않은 vertex에 해당하여
              dfs(w); // DFS 연산을 수행
      }
  } // edge의 시간 복잡도 m = (vertex의 수) x (vertex에 연결된 edge의 수)
  
  void dfs(graph G) {
      for all v in G
          visited[v] = FALSE; // 모든 vertex의 방문 여부 초기화
      
      for all v in G // Graph에 있는 모든 vertex들
          if(visited[v] == FALSE) // 방문을 하지 않았다면
              dfs(v);
  }
  ```

- 시간 복잡도

  1. Disconnected Graph
     - vertex의 수는 O(n)의 시간 복잡도를 가짐
     - 한 vertex에 연결된 edge의 수  = 0
     - 따라서 각 vertex의 for문은 0 x O(n) = 0번 돌아감
     - m =0이므로 **O(n+m) = O(n)**
  2. Sparse Graph
     - vertex의 수는 역시나 O(n)의 시간 복잡도를 가짐
     - 한 vertex에 연결된 edge의 수는 1개씩이니까 O(1) 상수개
     - 각 vertex의 for문은 O(1) x O(n) = O(n)
     - m = O(n)이므로 **O(n+m) = O(n + n) = O(n)**
  3. Dense Graph
     - vertex의 수 O(n)
     - 한 vertex에 연결된 edge의 수는 O(n) (각 vertex는 거의 모든 vertex에 연결)
     - 각 vertex의 for문은 O(n) x O(n) = O(n^2)
     - m = O(n^2)이므로 **O(n+m) = O(n+n^2) = O(n^2)**

  ![image-20200626125432275](C:\Users\user\AppData\Roaming\Typora\typora-user-images\image-20200626125432275.png)



### BFS (Breadth-first search)

**BFS Algorithm**

- 방문할 vertex의 리스트를 queue를 이용해서 관리

- Queue의 선언이 필요함

- Queue로부터 pop해서 방문할 vertex를 선택

- 선택한 vertex에 이웃한 아직 방문하지 않은 vertex에 대해서

  - 방문한 것으로 표시 (visited[w] = 1)
  - queue에 추가

- queue가 empty가 아닌 동안 반복

- Pseudo Code

  ```c++
  void bfs(vertex v) {
      vertex w;
      visited[v] = TRUE;
      push(v); // Queue에 push
      
      while(!emptyQ()) { // Queue가 empty 상태가 아닌 경우
          v = pop(); // 해당 vertex를 pop해서 다음 연산 수행
          for(w = graph[v]; w != NULL; w = w->link) { // pop한 원소에 연결되어 있는 것들
              if(visited[w] == FALSE) { // 아직 방문하지 않았으면
                  visited[w] = TRUE; // 방문했다고 기록
                  push(w); // Queue에 push
              }
          }
      }
  }
  
  void bfs(graph G) {
      for all v in G
          visited[v] = FALSE;
      for all v in G
          if(visited[v] == FALSE)
              bfs(v);
  }
  ```

- 시간 복잡도

  **결과 :  O(n+m)**



### **DFS와 BFS에 대한 시간 복잡도**

```c++
void dfs(vertex v) {
	.....
    // for-loop의 역할
    // 하나의 vertex가 몇 개의 edge에 연결되어 있느냐
    // Disconnected G : 0(0)
    // Sparse G : 상수(O(1))
    // Dense G : 거의 모든 vertex와 연결(O(n))
}

void dfs(graph G) {
    .....
    // 그래프에 있는 모든 vertex를 호출
    // 항상 O(n)개 존재
} 
```

결과적으로,

- 인접 행렬
  - Sparse matrix이던 혹은 Dense matrix이던지에 상관없이 행렬의 for-loop는 **O(n)**번 수행
  - 시간 복잡도 = **O(n^2)**
- 인접 리스트
  - Disconnected : O(n + m) = O(n + 0) = **O(n)** (m = 0)
  - Sparse : O(n + m) = O(n + n) = **O(n)** (m = n)
  - Dense : O(n + m) = O(n + n^2) = **O(n^2)** (m = n^2)


## Data Structure Chapter 11

### 그래프 탐색 응용 (Graph search Applications)

#### 연결 성분 찾기

**알고리즘**

- dfs(v) 혹은 bfs(v)를 **호출할 때마다** 연결 성분의 **인덱스를 증가**

  ```c++
  void dfs(int v, int idx) {
      nodePointer w;
      visited[v] = TRUE;
      v->label = idx;
      
      for(w = graph[v]; w != NULL; w = w->link) {
          if(!visited[w->vertex])
              dfs(w->visited, idx);
      }
  }
  
  void connected() {
      int i;
      int idx = 1;
      for(i = 0; i < n; i++) {
          if(!visited[i]) {
              dfs(i, idx);
              idx++;
          }
      }
  }
  ```

  

#### 신장 트리

**정의**

- 그래프의 vertex의 수 = n
- 그래프의 신장 트리의  edge의 수 = (n-1)



#### 이중 연결 성분

**분절점(Articulation Point)**

- 이 vertex와 연결된 edge를 제거하면 **그래프가 2개 이상의 연결 성분으로 분해**되는 vertex

  ![image-20200626142846956](C:\Users\user\AppData\Roaming\Typora\typora-user-images\image-20200626142846956.png)



**이중 연결 그래프(Biconnected Graph)**

- 분절점이 없는 그래프

  ![image-20200626143104072](C:\Users\user\AppData\Roaming\Typora\typora-user-images\image-20200626143104072.png)



**이중 연결 성분(Biconnected Component)**

- 이중 연결 그래프를 구성하는 성분들



**깊이 우선 번호(Depth-first number)**

- 깊이 우선 탐색을 수행하는 순서대로 방문하는 vertex에 부여되는 번호

  ![image-20200626143540502](C:\Users\user\AppData\Roaming\Typora\typora-user-images\image-20200626143540502.png)

  ![image-20200626143601406](C:\Users\user\AppData\Roaming\Typora\typora-user-images\image-20200626143601406.png)

  - 주요 성질

    - u가 v의 조상 노드일 때, **dfn(u) < dfn (v)**

    - **Back edge**가 존재

      - 그래프 모든 edge = 신장 트리에 속한 edge + 속하지 않은 edge(nontree edge)

      - **신장 트리에 속하지 않은 edge**

        ![image-20200626144028439](C:\Users\user\AppData\Roaming\Typora\typora-user-images\image-20200626144028439.png)

    

  - **분절점을 dfn 관점에서 설명해보기**

    1. **root node**가 **2개 이상의 자식 노드**를 갖는 경우

    2. **후손의** **back edge**를 타고 **내 위의 조상으로** 갈 수 있느냐 -> **없으면 분절점**

       vertex u와 자식 w에서 (w, w의 후손 -> 하나의 back edge -> u의 조상)

  - **분절점을 low( ) 관점에서 생각해보기**

    - low(u)
      - **후손의 back edge**를 타고 갈 수 있는 vertex 중 **가장 낮은 dfn**
      - 수식으로 정의
        1. **dfn(u)** // 자신의 dfn (초기화)
        2. **min(low(w))** // 자식 노드의 dfn
        3. **min(dfn(v))** // 한번에 back edge로 올라갈 수 있는 dfn 중 최소값
    - 다음의 조건을 만족시킬 때, u는 분절점
      - u가 2개 이상의 child node를 갖는 신장 트리의 root node
      - low(w) >= dfn(u) // u는 자기자신, w는 자식



- DFS(1) -> Computing dfn

  ```c++
  int dfn[MAX_VERTEX]; // -1로 초기화
  int low[MAX_VERTEX]; // -1로 초기화
  int num = 0;
  void dfs1(u, v) { // v는 u의 부모
      dfn[u] = num++; // 대입하고 +1 증가
      
      for(w = graph[u]; w; w = w->link) {
          if(dfn[w] < 0) // 음수일 경우, 방문을 아직 안했다는 의미
              dfs1(w, u)
      }
  }
  ```

- DFS(2) -> Computing low

  ```c++
  void dfs2(u, v) {
      dfn[u] = low[u] = num++;
      
      for(w = graph[u]; w; w = w->link) {
          if(dfn[w] < 0) { // 자식을 아직 방문하지 않았으면 (자식만 걸림)
              dfs2(w, u); // 자식 방문
              low[u] = min(low[u], low[w]); // 자식 노드의 low 값과 비교
          }
          // 왜 else if냐
          // 이미 if문에서는 음수 조건을 걸어버린 이유는
          // 음수인 경우 = 아직 방문 안함 = 자식 노드
          // 음수가 아닌 경우 = 방문 이미 함 = 조상 노드
          // 그래서 if문에는 자식 노드만 걸리고 else if문에는 조상 노드만 걸림
          // 근데 조상 노드 중에서 v는 부모니까 부모가 아닌 조상인 경우 (w != v 이유)
          // dfn[u]는 low[u]라고 써도 됨 위에서 그렇게 정의했거든
          else if(w != v) // 부모 말고 조상인 경우
              low[u] = min(low[u]/* dfn[u] = low[u] */, low[w]); // 조상 노드의 dfn과 비교
      }
  }
  ```

- DFS(3) -> Computing articulation point

  ```c++
  void dfs3(u, v) {
      dfn[u] = low[u] = num++;
      
      for(w = graph[u]; w; w = w->link) {
          if(dfn[w] < 0) {
              dfs3(w, u);
              low[u] = min(low[u], low[w]);
              if(low[w] >= dfn[u]) // 분절점의 정의 : 자식의 low가 자신의 dfn보다 크거나 같은 경우
                  printf("u: articulation point");
          }
          else if(w != v)
              low[u] = min(low[u], low[w]);
      }
  }
  ```

- DFS(4) -> Biconnected component

  ```c++
  void dfs4(u, v) {
      dfn[u] = low[u] = num++;
      
      for(w = graph[u]; w; w = w->link) {
          if(dfn[w] < 0) {
              push(u, w); // stack에 push
              dfs4(w, u);
              low[u] = min(low[u], low[w]);
              if(low[w] >= dfn[u]) { // 분절점을 만났을 때
                  printf("new bicon:");
                  do {
                      pop(&x, &y);
                      printf("<x, y>");
                  } while(x != u || y != w); // 분절점까지 pop 수행
              }
          }
          else if(w != v)
              low[u] = min(low[u], low[w]);
      }
  }
  ```

- Time Complexity

  - Time complexity of DFS -> **O(n+m)**
  - Time complexity of BCC -> **O(n+m)**
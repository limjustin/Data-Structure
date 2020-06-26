## Data Structure Chapter 09

### 그래프(Graph)

**정의**

- 개체들 사이의 일대일 관계를 시각적으로 표현하는 수학적 모델
- 그래프는 vertex(꼭짓점, 정점)와 edge(간선)의 집합

- G = (V, E)

**종류**

- **방향과 가중치**에 따른 그래프의 종류

  ![image-20200624201516530](C:\Users\user\AppData\Roaming\Typora\typora-user-images\image-20200624201516530.png)

- **복잡도**에 따른 그래프의 종류

  ![image-20200624201755285](C:\Users\user\AppData\Roaming\Typora\typora-user-images\image-20200624201755285.png)

  1. **완전 그래프 (Complete graph)**
     - n개의 vertex들이 서로 연결된 그래프
     - 하나의 vertex가 (n-1) 개의 vertex와 연결됨
     - Edge의 수 = nC2 = **n(n-1)/2** (무방향일때)
     - if 방향 그래프일 경우, n(n-1) 개의 edge를 가짐
  2. **밀집 그래프 (Dense graph)**
     - n개의 vertex들이 대부분 서로 연결된 그래프
     - Edge의 수 = **O(n^2)**
     - 방향 그래프일 경우에도 O(n^2)개의 edge를 가짐
  3. **완전 그래프**
     - 각 vertex들이 상수 개의 vertex와 연결된 그래프
     - 한 vertex에서 연결된 vertex의  수 : O(1)
     - Edge의 수 : **O(n)**

**용어**

- Adjacent (인접)

  - Vertex u와 v가 edge로 연결되어 있을 때
  - **한 edge를 공유**하는 두 vertex

- Incident 

  - 두 edge가 **같은 vertex를 공유**하고 있을 때
  - (0,1)과 (0,2)는 incident

- 부분 그래프 (Subgraph)

  - G = (V, E) 이고 G’ = (V’, E’) 일 때, V’ ⊆ V and E’ ⊆ E이면, G’은 G의 부분 그래프

- 경로 (Path)

  - 경로의 길이

    - 일반적인 경우, vertex의 수이거나 혹은 edge의 수가 경로의 길이가 됨
    - **가중치 그래프**일 경우, **경로에 있는 edge의 weight의 합**이 경로의 길이가 됨

  - 최단 경로

    - 여러 경로 중에서 그 길이가 최소인 경로 (최단 거리)

  - 단순 경로

    - 시작 vertex와 끝 vertex를 제외하고 모든 vertex가 다 다른 값을 가져야 함

      ex) 단순 경로의 예 : Path(1, 3) = (1, 0, 2, 3)

      ​      **단순 경로가 아닌 예** : Path(1, 3) = (1, *0, **2**, 5, 6, **2***, 3)

- 연결 (Connected)

  - 방향 그래프에서는 경로에 방향성이 추가되기 때문에 강한 연결이라고 함

    ![image-20200626112953519](C:\Users\user\AppData\Roaming\Typora\typora-user-images\image-20200626112953519.png)

- 신장 트리 (Spanning tree)

  - 그래프 G = (V, E) 의 부분 그래프 T = (V’, E’) 가 다음의 조건을 만족시킬 때, T를 G의 신장 트리 라고 함

    - V’ = V and E’ ⊆ E  and **|E’| = |V| -1  (Vertex의 개수에서 1을 뺀 값이 신장 트리의 Edge 수여야 함)**

    - E'는 순환이 없음

    - 여러 개의 신장 트리가 존재함

      ![image-20200626113332632](C:\Users\user\AppData\Roaming\Typora\typora-user-images\image-20200626113332632.png)

**구현**

1. Edge 리스트

   - 그래프의 edge의 리스트를 제시

   ![image-20200626114536253](C:\Users\user\AppData\Roaming\Typora\typora-user-images\image-20200626114536253.png)

2. 인접 행렬 (Adjacency matrix)

   - 방향이 있을 수도, 없을 수도 있음
   - n x n array의 형태

   ![image-20200626114635925](C:\Users\user\AppData\Roaming\Typora\typora-user-images\image-20200626114635925.png)

3. 인접 리스트 (Adjacency list)

   - 방향이 있을 수도, 없을 수도 있음 

   ![image-20200626114820245](C:\Users\user\AppData\Roaming\Typora\typora-user-images\image-20200626114820245.png)

   - STL을 이용한 그래프의 구현 (인접 리스트)

     ```c++
     nptr edge[10001];
     
     void main() {
         scanf("%d %d", &n, &m);
         for(int i = 0; i < m ; i++) {
             scanf("%d %d", &u, &v);
             edge[u].add(v); // 둘 다 각각의 연결리스트 목록에 들어감!!
             edge[v].add(u);
         }
         for(int i = 1; i <= n; i++)
             edge[i].sort();
     }
     ```

- 성능 비교

  ![image-20200626115813793](C:\Users\user\AppData\Roaming\Typora\typora-user-images\image-20200626115813793.png)

  - 희소 그래프 (Sparse Graph)일 경우
    - 인접 행렬은 nxn array이므로 O(n^2)이 나올 수 밖에 없음
    - 인접 리스트의 경우 edge의 수가 vertex의 수만큼 존재할 경우, **O(n)의 성능**이 나옴



**연산**

1. DFS (Depth first search)

   ![image-20200626120634711](C:\Users\user\AppData\Roaming\Typora\typora-user-images\image-20200626120634711.png)

2. BFS (Breadth first search)

   ![image-20200626120650591](C:\Users\user\AppData\Roaming\Typora\typora-user-images\image-20200626120650591.png)

3. 연결 성분 (Connected component)

   ![image-20200626120732326](C:\Users\user\AppData\Roaming\Typora\typora-user-images\image-20200626120732326.png)

4. 신장 트리 (Spanning tree)

   - 전체 vertex의 수에 1을 빼면 edge의 수가 되어야 함

   ![image-20200626120841284](C:\Users\user\AppData\Roaming\Typora\typora-user-images\image-20200626120841284.png)

5. 이중 연결 성분 (Biconnected component)

   - **한 vertex가 제거되어도 연결이 유지**되는 connected component

     ex) 5번 vertex가 제거되어도 2-4-6끼리 연결 유지

   ![image-20200626121126687](C:\Users\user\AppData\Roaming\Typora\typora-user-images\image-20200626121126687.png)

6. 강한 연결 성분 (Strongly connected component)

   ![image-20200626121345349](C:\Users\user\AppData\Roaming\Typora\typora-user-images\image-20200626121345349.png)

7. 최단 거리 (Shortest path)
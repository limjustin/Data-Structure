## Data Structure Chapter 05

### Stack

#### 스택의 정의

- 원소와 그 도착한 시간을 반대 순서로 저장한 리스트

- 원소의 추가와 제거는 **탑(Top)**에서만 일어남

- Last-In First-Out (혹은 First-In Last-Out)

- 스택의 구조

  ```c++
  class Stack {
      int size; // 스택에 저장할 수 있는 원소의 수
      DataType* Items; // 원소를 저장하는 리스트
      int TOP; // TOP의 위치
  }
  ```



#### 스택의 연산

1. CreateStack

   ```c++
   void Stack::CreateStack(int _size) {
       size = _size; // 크기 가져와서 
       tItem = new DataType[size]; // 크기 만큼의 리스트 할당
       TOP = 0; // TOP의 위치는 0으로 초기화
   }
   ```

2. is_Empty

   ```c++
   int Stack::is_Empty(void) {
       return (TOP == 0);
   }
   ```

3. is_Full

   ```c++
   int Stack::is_Full(void) {
       return (TOP == size);
   }
   ```

4. Push

   ```c++
   void Stack::push(DataType DataItem) { // 그냥 넣는거니까 void type
       // Exception Handling - Overflow
       if(is_Full())
           printf("Pushing in Full Stack! \n");
       
       Items[TOP] = DataItem; // Push는 오직 TOP에서만 수행됨
       TOP++; // 원소를 추가한 후에는 TOP을 증가시킬 것
   }
   ```

5. Pop

   ```c++
   DataType Stack::pop(void) {
       // Exception Handling - Underflow
       if(is_Empty())
           printf("Poping from Empty Stack! \n");
       
       TOP--; // TOP에서 가장 가까운 원소를 삭제
       	   // TOP은 빈 공간을 가리킴 -> -1을 감소시켜서 인덱스 당겨주는 역할
       return Items[TOP]; // 그리고 리턴하는 원리
   }
   ```

6. Top

   ```c++
   DataType Stack::Top(void) {
       return Items[TOP - 1]; // 실은 TOP-1에 저장된 원소를 리턴함
   }
   ```



#### 스택의 응용

**Postfix Expression (후위 표기)**

- Pseudo Code Main Algorithm

  ```c++
  1. If the current token is an OPERAND, then print OPERAND;
  2. If the current token is an OPERATOR
      2-1. If(token == Right parenthesis)
      	while(stack[TOP] != Left parenthesis) // 괄호가 있는 수식의 처리
              print POP();
  	2-2. while(stack[TOP] >= OPERATOR) // 새로 들어오는 것의 우선순위 더 낮음
          	print POP();
  	2-3. PUSH OPERATOR;
  ```

**Checking Parenthesis (괄호 검사)**

- 규칙 1 (여는 괄호)
  - 여는 괄호는 스택에 저장
- 규칙 2 (닫는 괄호)
  - 닫는 괄호는 스택 탑의 괄호와 같은 타입일 때만 Pop
- 규칙 3 (종료)
  - 마지막 괄호까지 점검한 후에 스택이 empty면 에러 없음
- 규칙 4 (error)
  - 닫는 괄호와 스택 탑의 괄호의 타입이 다르면 error
  - 닫는 괄호를 만났는데 스택이 empty면 error
  - 마지막 괄호까지 점검한 후에 스택이 엠티가 아니면 error



### Queue

#### 큐의 정의

- 원소와 원소가 들어온 순서를 함께 저장

- 원소의 추가와 제거가 양 끝에서 일어나는 리스트

- First-In First-Out

- FRONT : 원소가 추가되는 곳 / REAR : 원소가 제거되는 곳

- ENQUEUE : 원소를 추가하는 연산 / DEQUEUE : 원소를 제거하는 연산

- 큐의 구조

  ```c++
  class Queue {
  	int size; // 큐에 저장할 수 있는 원소의 수
  	DataType* Items; // 원소를 저장하는 리스트
  	int rear, front; // FRONT와 REAR의 값
  }
  ```



#### 큐의 연산

1. CreateQueue

   ```c++
   void queue::CreateQueue(int _size) {
       size = _size;
      	Items = new DataType[size];
       front = rear = -1; // front와 rear를 -1로 초기화
   }
   ```

2. Is_Empty

   ```c++
   int queue::IsEmpty(void) {
       return (front == rear);
   }
   ```

3. Is_Full

   ```
   int queue::IsFull(void) {
   	return (rear == size-1);
   }
   ```

4. Enqueue

   ```c++
   void queue::Enqueue(element item) {
   	if(isFull())
           printf("Cannot add an element to a full queue! \n");
       rear++; // enqueue는 오직 rear에서만 수행됨
       Items[rear] = item;
   }
   ```

5. Dequeue

   ```c++
   element queue::Dequeue() {
   	if(isEmpty())
           printf("You cannot delete from an empty queue! \n");
       front++; // dequeue는 front에서 제거함
       return Items[front]; // 큐에서 원소 하나를 삭제하고 리턴하는 연산
   }
   ```



#### 특수한 큐

##### **Circular Queue (원형 큐)**

**기존 큐의 문제점**

- 큐에 빈 공간이 있어도 REAR == size이면 Full이라고 판단할 수 있음

**원형 큐에서의 해결책**

- 큐의 마지막 원소와 첫 번째 원소를 연결함

  ```c++
  rear = rear + 1 -> rear = (rear + 1) % N
  front = front + 1 -> front = (front + 1) % N
  ```

  - 장점
    - 스택과 같이 무한한 추가와 제거가 가능함
  - 단점
    - Full과 Empty의 상태가 동일해짐
    - FRONT == REAR
    - 따라서, 큐에 저장된 원소를 나타내는 count 변수가 필요함



##### **Doubly-Ended Queue (DEQ)**

- Enqueue와 Dequeue가 Queue의 양 끝에서 일어나는 형태의 Queue
- FRONT/REAR에서 Enqueue/Dequeue가 일어날 것인지 명시해야함
- 스택과 큐를 동시에 지원하는 장점이 있음



##### **Priority Queue (우선 순위 큐)**

- **우선 순위**에 따라서 원소를 추가하거나 제거하는 큐
- 큐의 원소는 **우선 순위에 따라서 배치**됨
- **우선 순위를 유지**하도록 원소를 추가함
- 항상 큐의 **첫 번째 원소는 가장 우선 순위가 높은 원소**를 유지함
- 큐의 **첫 번째 원소**만 제거함
- 트리 형태의 구현 **(Heap)**
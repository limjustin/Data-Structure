#include <stdio.h>
#define MAX 6
int cnt = 0;
int heap[6];
int res[6];

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void heapify_topdown(int idx) {
	// leaf node에 도착하면 끝
	if (2 * idx > cnt)
		return;
	if (2 * idx == cnt) {
		if (heap[idx] < heap[2 * idx])
			swap(&heap[idx], &heap[2 * idx]);
		return;
	}
	if (heap[2 * idx] > heap[2 * idx + 1] && heap[2 * idx] > heap[idx]) {
		swap(&heap[idx], &heap[2 * idx]);
		heapify_topdown(2 * idx);
	}
	else if (heap[2 * idx + 1] > heap[2 * idx] && heap[2 * idx + 1] > heap[idx]) {
		swap(&heap[idx], &heap[2 * idx + 1]);
		heapify_topdown(2 * idx + 1);
	}
}

void heapify_bottomup(int idx) {
	// root node에 도착하면 끝
	if (idx == 1)
		return;
	if (heap[idx / 2] < heap[idx]) {
		swap(&heap[idx / 2], &heap[idx]);
		heapify_bottomup(idx / 2);
	}
}

void push(int ndata) {
	cnt++;
	heap[cnt] = ndata;

	heapify_bottomup(cnt);
}

int pop(void) {
	int temp = heap[1];
	heap[1] = heap[cnt];
	cnt--;

	heapify_topdown(1);
	return temp;
}

void heap_sort(int* arr, int n) {
	int i;
	
	for (i = 0; i < n; i++)
		push(arr[i]);
	for (i = 0; i < n; i++) {
		res[i] = pop();
	}
	for (int l = MAX - 1; l >= 0; l--) {
		printf("%d ", res[l]);
	}
	printf("\n");
}

int main(void) {
	int list[6] = { 2,8,5,3,9,1 };
	int size = sizeof(list) / sizeof(int);
	printarray(size - 1, list);
	heap_sort(list, MAX);

	return 0;
}

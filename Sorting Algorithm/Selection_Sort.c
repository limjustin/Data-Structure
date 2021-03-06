#include <stdio.h>

void printarray(int n, int a[]) {
	for (int index = 0; index < n; index++) {
		printf("%d ", a[index]);
	}
	printf("\n");
}

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int select_min(int s, int e, int n[]) {
	int min_idx = s;
	for (int i = s + 1; i <= e; i++) {
		if (n[i] < n[min_idx])
			min_idx = i;
	}
	return min_idx;
}

void selection_sort(int n, int a[]) {
	int i;
	int min_idx;
	for (i = 0; i < n - 1; i++) {
		min_idx = select_min(i, n - 1, a);
		swap(&a[i], &a[min_idx]);
		printarray(n, a);
	}
}

int main(void) {
	int arr[5] = { 82,61,5,30,74 };
	printarray(sizeof(arr) / sizeof(int), arr);
	selection_sort(sizeof(arr) / sizeof(int), arr);
	return 0;
}

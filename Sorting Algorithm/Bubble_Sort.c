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

void bubble_sort(int n, int a[]) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {
			if (a[j - 1] > a[j])
				swap(&a[j - 1], &a[j]);
		}
		printarray(n, a);
	}
}

int main(void) {
	int arr[5] = { 82,61,5,30,74 };
	printarray(sizeof(arr) / sizeof(int), arr);
	bubble_sort(sizeof(arr) / sizeof(int), arr);
	return 0;
}

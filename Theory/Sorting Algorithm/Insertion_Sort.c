#include <stdio.h>

void printarray(int n, int a[]) {
	for (int index = 0; index < n; index++) {
		printf("%d ", a[index]);
	}
	printf("\n");
}

void insert(int x, int n, int a[]) {
	int i, j;
	for (i = 0; i < n; i++) {
		if (a[i] > x)
			break;
	}

	for (j = n - 1; j >= i; j--) {
		a[j + 1] = a[j];
	}

	a[i] = x;
	
	return;
}

void insertion_sort(int n, int a[]) {
	int i;

	for (i = 1; i < n; i++) {
		insert(a[i], i, a);
		printarray(n, a);
	}
}

int main(void) {
	int arr[5] = { 82,61,5,30,74 };
	printarray(sizeof(arr) / sizeof(int), arr);
	insertion_sort(sizeof(arr) / sizeof(int), arr);
	return 0;
}

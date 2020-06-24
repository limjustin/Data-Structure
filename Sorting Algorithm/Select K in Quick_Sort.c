#include <stdio.h>
#define MAX_SIZE 8

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

int split(int list[], int s, int e) {
	int pivot, lptr, rptr;
	lptr = s + 1;
	rptr = e;
	pivot = list[s];

	while (lptr <= rptr) {
		while ((list[rptr] >= pivot) && (lptr <= rptr))
			rptr--;
		while ((list[lptr] <= pivot) && (lptr <= rptr))
			lptr++;
		if (lptr <= rptr)
			swap(&list[lptr], &list[rptr]);
	}
	swap(&list[rptr], &list[s]);
	return rptr;
}

int select_kth(int list[], int k, int s, int e) {
	if (s == e)
		return list[s];

	int m = split(list, s, e);

	if (k < m)
		select_kth(list, k, s, m - 1);
	if (k > m)
		select_kth(list, k, m + 1, e);
	else
		return list[k];
}

int main(void) {
	int list[8] = { 16, 12, 38, 5, 19, 4, 27, 20 };
	int size = sizeof(list) / sizeof(int) - 1;
	int find;
	printarray(sizeof(list) / sizeof(int), list);
	printf("Input index : ");
	scanf("%d", &find);
	int res = select_kth(list, find, 0, size);
	printf("find list[%d] in quick sorted array = %d \n", find, res);

	return 0;
}

#include <stdio.h>
#define MAX_SIZE 8

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

void quick_sort(int list[], int s, int e) {
	if (s >= e)
		return;
	int mid = split(list, s, e);
	quick_sort(list, s, mid - 1);
	quick_sort(list, mid + 1, e);
	
	printarray(MAX_SIZE, list);
}


int main(void) {
	int list[8] = { 16, 12, 38, 5, 19, 4, 27, 20 };
	int size = sizeof(list) / sizeof(int) - 1;
	printarray(sizeof(list) / sizeof(int), list);
	quick_sort(list, 0, size);

	return 0;
}

#include <stdio.h>
#define MAX_SIZE 8
int sorted[8];

void merge(int list[], int ls, int md, int rs) {
	int lptr = ls;
	int rptr = md + 1;
	int mid = md;
	int k = ls;

	while (lptr <= mid && rptr <= rs) {
		if (list[lptr] < list[rptr])
			sorted[k++] = list[lptr++];
		else
			sorted[k++] = list[rptr++];
	}

	if (lptr > mid)
		for (int i = rptr; i <= rs; i++)
			sorted[k++] = list[i];
	if (rptr > rs)
		for (int i = lptr; i <= mid; i++)
			sorted[k++] = list[i];

	for (int l = ls; l <= rs; l++) {
		list[l] = sorted[l];
	}

	printarray(MAX_SIZE, list);
}

void merge_sort(int list[], int s, int e) {
	if (s == e)
		return;

	int mid = (s + e) / 2;
	merge_sort(list, s, mid);
	merge_sort(list, mid + 1, e);
	merge(list, s, mid, e);
}


int main(void) {
	int list[8] = { 16, 12, 38, 5, 19, 4, 27, 20 };
	printarray(sizeof(list) / sizeof(int), list);
	merge_sort(list, 0, size);
	return 0;
}

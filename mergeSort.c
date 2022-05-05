#include <stdio.h>
#include <stdlib.h>

static int* buff;

void __mergeSort(int a[], int left, int right) {
	if (left < right) {
		int center = (left + right) / 2;
		int p = 0; 
		int j = 0;
		int k = left;
		int i;

		__mergeSort(a, left, center);
		__mergeSort(a, center + 1, right);

		for (i = left; i <= center; i++)
			buff[p++] = a[i];

		while (i <= right && j < p)
			a[k++] = buff[j] <= a[i] ? buff[j++] : a[i++];

		while (j < p)
			a[k++] = buff[j++];
	}
}

int mergeSort(int a[], int n) {
	if ((buff = calloc(n, sizeof(int))) == NULL) return -1;

	__mergeSort(a, 0, n - 1);
	free(buff);
	return 0;
}

void mergeSort_test() {
	int a[] = { 10, 8, 7, 6, 5, 4, 3, 2, 1 };
	mergeSort(a, 9);

	for (int i = 0; i < 9; i++)
		printf("%3d", a[i]);
	putchar('\n');
}
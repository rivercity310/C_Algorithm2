#include <stdio.h>
#include <stdlib.h>



void mergeSort_test() {
	int a[] = { 10, 8, 7, 6, 5, 4, 3, 2, 1 };
	mergeSort(a, 9);

	for (int i = 0; i < 9; i++)
		printf("%3d", a[i]);
	putchar('\n');
}
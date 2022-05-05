#include <stdio.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)

void print_ary2(int a[], int n) {
	for (int i = 0; i < n; i++)
		printf("%5d ", a[i]);
	putchar('\n');
}

void partition(int a[], int n) {
	print_ary2(a, n);

	int i;
	int pl = 0;
	int pr = n - 1;
	int pivot = a[n / 2];

	do {
		while (a[pl] < pivot) pl++;
		while (a[pr] > pivot) pr--;
		if (pl <= pr) {
			printf("%d과 %d를 교환합니다\n", a[pl], a[pr]);
			swap(int, a[pl], a[pr]);
			print_ary2(a, n);

			pl++;
			pr--;
		}
	} while (pl <= pr);

	printf("pl = %d, a[pl] = %d\n", pl, a[pl]);
	printf("pr = %d, a[pr] = %d\n", pr, a[pr]);

	print_ary2(a, n);
}

void quick_sort(int a[], int left, int right) {
	int pl = left;
	int pr = right;
	int x = a[(pl + pr) / 2];

	// 분할 과정 출력
	printf("a[%d]~a[%d] : {", left, right);
	for (int i = left; i < right; i++)
		printf("%d ", a[i]);
	printf("%d}\n", a[right]);

	do {
		while (a[pl] < x) pl++;
		while (a[pr] > x) pr--;

		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);

	if (left < pr) quick_sort(a, left, pr);
	if (pl < right) quick_sort(a, pl, right);
}

void qSort_test() {
	int a[] = { 1, 8, 7, 4, 5, 2, 6, 3, 9 };
	quick_sort(a, 0, 8);
	print_ary2(a, 9);
}
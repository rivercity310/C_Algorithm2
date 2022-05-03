#include <stdio.h>

void print_arr(int a[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n');
}

void shell_sort(int a[], int n) {
	int i, j, h;
	for (h = n / 2; h > 0; h /= 2) {
		for (i = h; i < n; i++) {
			int tmp = a[i];
			for (j = i - h; j >= 0 && a[j] > tmp; j -= h)
				a[j + h] = a[j];

			a[j + h] = tmp;
		}
		printf("[%d - Á¤·Ä]\n", h);
		print_arr(a, n);
	}
}

void shell_sort_test() {
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2 };
	shell_sort(a, 8);
}
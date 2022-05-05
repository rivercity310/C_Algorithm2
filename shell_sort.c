#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_arr(int a[], int n) {
	int counter = 0;
	for (int i = 0; counter++, i < n; i++) {
		printf("%5d ", a[i]);
		if (counter % 10 == 0) putchar('\n');
	}
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
		printf("[%d - 정렬]\n", h);
		print_arr(a, n);
	}
}

void shell_sort2(int a[], int n) {
	int i, j, h;
	for (h = 1; h < n / 9; h = h * 3 + 1);

	for (; h > 0; h /= 3) {
		for (i = h; i < n; i++) {
			int tmp = a[i];
			for (j = i - h; j >= 0 && a[j] > tmp; j -= h)
				a[j + h] = a[j];

			a[j + h] = tmp;
		}
	}
}

void shell_sort_test() {
	srand(time(NULL));
	
	int nx;
	printf("배열의 크기? ");
	scanf_s("%d", &nx);

	int* x = (int*)malloc(nx * sizeof(int));
	for (int i = 0; i < nx; i++)
		x[i] = (rand() % 10000 - 5000); // -5000 ~ 4999

	print_arr(x, nx);
	shell_sort2(x, nx);
	puts("\n\n\n");
	print_arr(x, nx);

}
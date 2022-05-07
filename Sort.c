#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sort.h"

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)
#define RINT 10      // 0 ~ (RINT - 1)

// =========================================================================

static int* bf;

static int* memalloc(int n) {
	srand(time(NULL));

	int* x = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		*(x + i) = rand() % RINT;

	bf = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		bf[i] = x[i];

	return x;
}

static void prt_arr(const int a[], int n) {
	int counter = 0;
	for (int i = 0; i < n; i++) {
		printf("%4d ", a[i]);
		if (++counter % 10 == 0) putchar('\n');
	}
	putchar('\n');
}

static void histo(int n) {
	puts("[Histogram]");
	for (int i = 0; i < RINT; i++) {
		fprintf(stdout, "[%02d]: ", i);

		int counter = 0;
		for (int j = 0; j < n; j++)
			if (bf[j] == i) {
				//putc('+', stdout);
				counter++;
			}

		fprintf(stdout, "\t\t\t(%d)\n", counter);
	}
}

static void Sort(void(*fp)(int*, int), int ch) {
	int nx;
	printf("배열의 크기? ");
	scanf_s("%d", &nx);

	int* x = memalloc(nx);

	prt_arr(x, nx);
	ch == 0 ? fp(x, nx) : fp(x, 0, nx - 1);
	prt_arr(x, nx);

	histo(nx);
}

// =========================================================================

/* 단순 버블 정렬 */
void bubble_sort(int a[], int n) {
	int counter = 0;

	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j - 1] > a[j]) {
				swap(int, a[j - 1], a[j]);
				counter++;
			}

	printf("[%s]\n", __func__);
	printf("[교환 횟수: %d]\n", counter);
}

/* 개선1: 각 패스에서 교환 횟수가 0이면 정렬을 종료 */
void bubble_sort2(int a[], int n) {
	int counter = 0;

	for (int i = 0; i < n - 1; i++) {
		int exchg = 0;
		for (int j = n - 1; j > i; j--) {
			if (a[j - 1] > a[j]) {
				swap(int, a[j - 1], a[j]);
				counter++;
				exchg++;
			}
		}

		if (exchg == 0) break;
	}

	printf("[%s]\n", __func__);
	printf("[교환 횟수: %d]\n", counter);
}

/* 개선2: 
어떤 시점 이후 교환이 수행되지 않는다면 그보다 앞쪽 요소는 이미 정렬된 상태
*/
void bubble_sort3(int a[], int n) {
	int counter = 0;

	int k = 0;
	while (k < n - 1) {
		int last = n - 1;    // 마지막 교환 위치를 저장 (오른쪽 요소)
		for (int j = n - 1; j > k; j--) {
			if (a[j - 1] > a[j]) {
				swap(int, a[j - 1], a[j]);
				counter++;
				last = j;
			}
		}

		k = last;
	}

	printf("[%s]\n", __func__);
	printf("[교환 횟수: %d]\n", counter);
}

// =========================================================================

/* 단순 삽입 정렬 */
void insertion_sort(int a[], int n) {
	int i, j;
	for (i = 1; i < n; i++) {
		int tmp = a[i];
		for (j = i; j > 0 && a[j - 1] > tmp; j--)
			a[j] = a[j - 1];

		a[j] = tmp;
	}

	printf("[%s]\n", __func__);
}

// =========================================================================

/* 
[선택 정렬] 
아직 정렬되지 않은 부분에서 가장 작은 값을 선택하고, 
아직 정렬되지 않은 부분의 첫 요소와 교환을 (n - 1)회 반복합니다.
*/
void selection_sort(int a[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		int min = i;
		for (j = i + 1; j < n; j++)
			if (a[min] > a[j]) min = j;

		swap(int, a[i], a[min]);

		puts("----------------------------------------------");
		puts("[정렬된 부분]");
		for (int k = 0; k <= i; k++)
			printf("%d ", a[k]);
		putchar('\n');

		puts("[정렬되지 않은 부분]");
		for (int l = i + 1; l < n; l++)
			printf("%d ", a[l]);
		putchar('\n');
		puts("----------------------------------------------\n\n");
	}

	printf("[%s]\n", __func__);
}

// =========================================================================

/* 
[셸 정렬]
단순 삽입 정렬을 개선한 알고리즘
*/
void shell_sort(int a[], int n) {
	int i, j, h;
	for (h = n / 2; h > 0; h /= 2) {
		for (i = h; i < n; i++) {
			int tmp = a[i];
			for (j = i - h; j >= 0 && a[j] > tmp; j -= h)
				a[j + h] = a[j];

			a[j + h] = tmp;
		}
	}

	printf("[%s]\n", __func__);
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

	printf("[%s]\n", __func__);
}

// =========================================================================

/*
[퀵 정렬]

*/
void quick_sort(int a[], int left, int right) {
	int pl = left;
	int pr = right;
	int x = a[(pl + pr) / 2];   // 피벗

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

// =========================================================================

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

int merge_sort(int a[], int n) {
	if ((buff = calloc(n, sizeof(int))) == NULL) return -1;

	__mergeSort(a, 0, n - 1);
	free(buff);

	printf("[%s]\n", __func__);
	return 0;
}

// =========================================================================

void Sort_Test() {
	Sort(merge_sort, 0);
}
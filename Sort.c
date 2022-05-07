#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sort.h"

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)

// =========================================================================

static int* bf;

static int* memalloc(int n) {
	srand(time(NULL));

	int* x = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		*(x + i) = rand() % 366;

	bf = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		bf[i] = x[i];

	return x;
}

static void Sort(void(*fp)(int*, int)) {
	int nx;
	printf("배열의 크기? ");
	scanf_s("%d", &nx);

	int* x = memalloc(nx);

	prt_arr(x, nx);
	fp(x, nx);
	prt_arr(x, nx);
}

static void prt_arr(const int a[], int n) {
	int counter = 0;
	for (int i = 0; i < n; i++) {
		printf("%4d ", a[i]);
		if (++counter % 10 == 0) putchar('\n');
	}
	putchar('\n');
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


void Sort_Test() {
	Sort(selection_sort);
}
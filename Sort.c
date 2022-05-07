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
	printf("�迭�� ũ��? ");
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

/* �ܼ� ���� ���� */
void bubble_sort(int a[], int n) {
	int counter = 0;

	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j - 1] > a[j]) {
				swap(int, a[j - 1], a[j]);
				counter++;
			}

	printf("[%s]\n", __func__);
	printf("[��ȯ Ƚ��: %d]\n", counter);
}

/* ����1: �� �н����� ��ȯ Ƚ���� 0�̸� ������ ���� */
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
	printf("[��ȯ Ƚ��: %d]\n", counter);
}

/* ����2: 
� ���� ���� ��ȯ�� ������� �ʴ´ٸ� �׺��� ���� ��Ҵ� �̹� ���ĵ� ����
*/
void bubble_sort3(int a[], int n) {
	int counter = 0;

	int k = 0;
	while (k < n - 1) {
		int last = n - 1;    // ������ ��ȯ ��ġ�� ���� (������ ���)
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
	printf("[��ȯ Ƚ��: %d]\n", counter);
}

// =========================================================================

/* �ܼ� ���� ���� */
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
[���� ����] 
���� ���ĵ��� ���� �κп��� ���� ���� ���� �����ϰ�, 
���� ���ĵ��� ���� �κ��� ù ��ҿ� ��ȯ�� (n - 1)ȸ �ݺ��մϴ�.
*/
void selection_sort(int a[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		int min = i;
		for (j = i + 1; j < n; j++)
			if (a[min] > a[j]) min = j;

		swap(int, a[i], a[min]);

		puts("----------------------------------------------");
		puts("[���ĵ� �κ�]");
		for (int k = 0; k <= i; k++)
			printf("%d ", a[k]);
		putchar('\n');

		puts("[���ĵ��� ���� �κ�]");
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
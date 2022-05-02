#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

// 기본
void Bubble_Sort(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
				swap(int, a[j - 1], a[j]);
}

// Q1. 버블 정렬의 각 패스에서 비교, 교환을 왼쪽부터 수행하도록 수정
void Bubble_Sort2(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 1; j < n - i; j++)
			if (a[j - 1] > a[j])
				swap(int, a[j], a[j - 1]);

		printf("[루프 %d]: ", i + 1);
		for (int i = 0; i < n; i++)
			printf("%-5d", a[i]);
		putchar('\n');
	}
}

// 버블 정렬 개선 알고리즘: 교환 횟수가 0이면 종료
void Bubble_Sort3(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int exchg = 0;
		printf("----------패스%02d---------\n", i + 1);
		for (int j = n - 1; j > i; j--) {
			if (a[j - 1] > a[j]) {
				printf("a[%d] <----> a[%d]\n", j - 1, j);
				printf("%d와 %d을(를) 교환합니다.\n", a[j - 1], a[j]);
				putchar('\n');
				swap(int, a[j - 1], a[j]);
				exchg++;
			}
		}

		printf("%d번째 패스, 교환 횟수 = %d\n", i + 1, exchg);
		printf("----------------------------\n");
		puts("\n");
		if (!exchg) break;
	}
}

// 버블 정렬 개선 알고리즘2
// 어떤 시점 이후 교환이 수행되지 않는다면 그보다 앞쪽 요소는 이미 정렬을 마친 상태
void Bubble_Sort4(int a[], int n) {
	int k = 0;
	while (k < n - 1) {
		int last = n - 1;
		for (int j = n - 1; j > k; j--) {
			if (a[j - 1] > a[j]) {
				swap(int, a[j - 1], a[j]);
				last = j;
			}
		}

		printf("k = %d, last = %d\n", k, last);
		k = last;
	}
}

// 오름차순으로 정렬되어 있나 체크해주는 함수
int is_sorted(int a[], int n) {
	int exchg = 0;
	for (int i = 0; i < n - 1; i++)
		if (a[i] > a[i + 1]) exchg++;

	return exchg > 0 ? 0 : 1;
}


void bsort_test() {
	int nx;
	int* x;

	srand(time(NULL));

	puts("[Bubble Sort]");
	printf("요소의 개수: ");
	scanf_s("%d", &nx);
	x = (int*)malloc(sizeof(int) * nx);

	for (int i = 0; i < nx; i++) {
		x[i] = rand() % 200 - 50;
		printf("%4d", x[i]);
	}
	puts("\n");
	

	Bubble_Sort4(x, nx);
	puts("Bubble Sorting is Done!");

	for (int i = 0; i < nx; i++)
		printf("%4d", x[i]);
	putchar('\n');

	printf("정렬 상태: %s\n", is_sorted(x, nx) == 1 ? "완료" : "미완료");

	free(x);
}
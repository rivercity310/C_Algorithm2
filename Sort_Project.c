#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

/*
사용자에게 무작위 정수를 입력받아 배열을 완성시킨 뒤, 원소 검색 방법을 제공하고
선형 검색이면 정렬 여부를 묻지 않고 이진 검색이면 정렬 여부를 물은 뒤 
검색을 수행하는 프로그램을 작성

[정렬]: (1)버블 정렬, (2)단순 선택 정렬, (3)단순 삽입 정렬
[검색]: (1)선형 검색, (2)이진 검색
*/

typedef enum {
	BUBBLE = 1, SELECTION, INSERTION, SHELL
} SORT_MENU;

typedef enum {
	EXIT, LINEAR, BINARY
} SHC_MENU;

int lin_search_p(int a[], int n, int key) {
	int i;
	a[n] = key;

	for (i = 0; i < n; i++)
		if (a[i] == key) break;

	return i == n ? -1 : i;
}

int bin_search_p(int a[], int n, int key) {
	int pl = 0;
	int pr = n - 1;
	int pc;

	do {
		pc = (pl + pr) / 2;

		if (a[pc] == key) return pc;
		else if (a[pc] > key) pr = pc - 1;
		else pl = pc + 1;
	} while (pl <= pr);

	return -1;
}

void bubble_sort_p(int a[], int n) {
	int k = 0;

	while (k < n - 1) {
		int last = n - 1;
		for (int j = n - 1; j > k; j--) {
			if (a[j - 1] > a[j]) {
				swap(int, a[j - 1], a[j]);
				last = j;
			}
		}

		k = last;
	}
}

void selection_sort_p(int a[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		int min = i;
		for (j = i + 1; j < n; j++) {
			if (a[min] > a[j]) min = j;
		}

		swap(int, a[i], a[min]);
	}
}

void insertion_sort_p(int a[], int n) {
	int i, j;
	for (i = 1; i < n; i++) {
		int tmp = a[i];
		for (j = i; j > 0 && a[j - 1] > tmp; j--) {
			a[j] = a[j - 1];
		}

		a[j] = tmp;
	}
}

void Shell_sort_p(int a[], int n) {
	int i, j, h;
	for (h = n / 2; h > 0; h /= 2) {
		for (i = h; i < n; i++) {
			int tmp = a[i];
			for (j = i - h; j >= 0 && a[j] > tmp; j -= h)
				a[j + h] = a[j];

			a[j + h] = tmp;
		}
	}
}

SHC_MENU sch_menu() {
	puts("검색을 시작합니다..");
	puts("어떤 방법으로 검색할까요?");

	int s;
	printf("(1)선형 검색, (2)이진 검색, (0)종료 >> ");
	scanf_s("%d", &s);
	
	return (SHC_MENU)s;
}

SORT_MENU sort_menu() {
	puts("어떤 방법으로 정렬할까요?");
	
	int s;
	printf("(1)버블 정렬, (2)단순 선택 정렬, (3)단순 삽입 정렬, (4)셸 정렬 >> ");
	scanf_s("%d", &s);

	return (SORT_MENU)s;
}

void sort_project() {
	int* x;
	int nx;
	
	puts("[검색 서비스]");
	printf("배열의 크기를 입력하세요: ");
	scanf_s("%d", &nx);

	x = (int*)malloc(sizeof(int) * (nx + 1));
	for (int i = 0; i < nx; i++) {
		printf("x[%d]: ", i);
		scanf_s("%d", &x[i]);
	}
	puts("배열 입력이 완료되었습니다...");

	while (1) {
		int idx, key;
		SHC_MENU s;
		switch (s = sch_menu()) {
		case EXIT:
		{
			puts("프로그램을 종료합니다....");
			free(x);
			return;
		}
		case LINEAR:
		{
			printf("검색할 값? ");
			scanf_s("%d", &key);
			idx = lin_search_p(x, nx, key);

			if (idx != -1) printf("x[%d] = %d\n", idx, x[idx]);
			else puts("존재하지 않는 값이네요..");
			break;
		}
		case BINARY:
		{
			puts("이진 검색을 하려면 먼저 배열을 정렬해야 합니다..");

			SORT_MENU sm;
			switch (sm = sort_menu()) {
			case BUBBLE:
				bubble_sort_p(x, nx);
				break;
			case SELECTION:
				selection_sort_p(x, nx);
				break;
			case INSERTION:
				insertion_sort_p(x, nx);
				break;
			case SHELL:
				Shell_sort_p(x, nx);
				break; 
			}
			puts("정렬이 완료되었습니다..");
			puts("[배열 x]");
			for (int i = 0; i < nx; i++)
				printf("%d ", x[i]);
			putchar('\n');

			printf("검색할 값? ");
			scanf_s("%d", &key);
			idx = bin_search_p(x, nx, key);

			if (idx != -1) printf("x[%d] = %d\n", idx, x[idx]);
			else puts("존재하지 않는 값이네요..");
			break;
		}
		}
	}

}
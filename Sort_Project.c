#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

/*
����ڿ��� ������ ������ �Է¹޾� �迭�� �ϼ���Ų ��, ���� �˻� ����� �����ϰ�
���� �˻��̸� ���� ���θ� ���� �ʰ� ���� �˻��̸� ���� ���θ� ���� �� 
�˻��� �����ϴ� ���α׷��� �ۼ�

[����]: (1)���� ����, (2)�ܼ� ���� ����, (3)�ܼ� ���� ����
[�˻�]: (1)���� �˻�, (2)���� �˻�
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
	puts("�˻��� �����մϴ�..");
	puts("� ������� �˻��ұ��?");

	int s;
	printf("(1)���� �˻�, (2)���� �˻�, (0)���� >> ");
	scanf_s("%d", &s);
	
	return (SHC_MENU)s;
}

SORT_MENU sort_menu() {
	puts("� ������� �����ұ��?");
	
	int s;
	printf("(1)���� ����, (2)�ܼ� ���� ����, (3)�ܼ� ���� ����, (4)�� ���� >> ");
	scanf_s("%d", &s);

	return (SORT_MENU)s;
}

void sort_project() {
	int* x;
	int nx;
	
	puts("[�˻� ����]");
	printf("�迭�� ũ�⸦ �Է��ϼ���: ");
	scanf_s("%d", &nx);

	x = (int*)malloc(sizeof(int) * (nx + 1));
	for (int i = 0; i < nx; i++) {
		printf("x[%d]: ", i);
		scanf_s("%d", &x[i]);
	}
	puts("�迭 �Է��� �Ϸ�Ǿ����ϴ�...");

	while (1) {
		int idx, key;
		SHC_MENU s;
		switch (s = sch_menu()) {
		case EXIT:
		{
			puts("���α׷��� �����մϴ�....");
			free(x);
			return;
		}
		case LINEAR:
		{
			printf("�˻��� ��? ");
			scanf_s("%d", &key);
			idx = lin_search_p(x, nx, key);

			if (idx != -1) printf("x[%d] = %d\n", idx, x[idx]);
			else puts("�������� �ʴ� ���̳׿�..");
			break;
		}
		case BINARY:
		{
			puts("���� �˻��� �Ϸ��� ���� �迭�� �����ؾ� �մϴ�..");

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
			puts("������ �Ϸ�Ǿ����ϴ�..");
			puts("[�迭 x]");
			for (int i = 0; i < nx; i++)
				printf("%d ", x[i]);
			putchar('\n');

			printf("�˻��� ��? ");
			scanf_s("%d", &key);
			idx = bin_search_p(x, nx, key);

			if (idx != -1) printf("x[%d] = %d\n", idx, x[idx]);
			else puts("�������� �ʴ� ���̳׿�..");
			break;
		}
		}
	}

}
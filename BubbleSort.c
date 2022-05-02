#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

// �⺻
void Bubble_Sort(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
				swap(int, a[j - 1], a[j]);
}

// Q1. ���� ������ �� �н����� ��, ��ȯ�� ���ʺ��� �����ϵ��� ����
void Bubble_Sort2(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 1; j < n - i; j++)
			if (a[j - 1] > a[j])
				swap(int, a[j], a[j - 1]);

		printf("[���� %d]: ", i + 1);
		for (int i = 0; i < n; i++)
			printf("%-5d", a[i]);
		putchar('\n');
	}
}

// ���� ���� ���� �˰���: ��ȯ Ƚ���� 0�̸� ����
void Bubble_Sort3(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int exchg = 0;
		printf("----------�н�%02d---------\n", i + 1);
		for (int j = n - 1; j > i; j--) {
			if (a[j - 1] > a[j]) {
				printf("a[%d] <----> a[%d]\n", j - 1, j);
				printf("%d�� %d��(��) ��ȯ�մϴ�.\n", a[j - 1], a[j]);
				putchar('\n');
				swap(int, a[j - 1], a[j]);
				exchg++;
			}
		}

		printf("%d��° �н�, ��ȯ Ƚ�� = %d\n", i + 1, exchg);
		printf("----------------------------\n");
		puts("\n");
		if (!exchg) break;
	}
}

// ���� ���� ���� �˰���2
// � ���� ���� ��ȯ�� ������� �ʴ´ٸ� �׺��� ���� ��Ҵ� �̹� ������ ��ģ ����
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

// ������������ ���ĵǾ� �ֳ� üũ���ִ� �Լ�
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
	printf("����� ����: ");
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

	printf("���� ����: %s\n", is_sorted(x, nx) == 1 ? "�Ϸ�" : "�̿Ϸ�");

	free(x);
}
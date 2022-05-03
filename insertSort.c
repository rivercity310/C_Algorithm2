#include <stdio.h>

void print_ary(int a[], int n, const char* msg) {
	printf("%s\n", msg);
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n');
}

void insertion(int a[], int n) {
	int i, j;
	for (i = 1; i < n; i++) {
		print_ary(a, n, "[���� ��]");

		int tmp = a[i];
		for (j = i; j > 0 && a[j - 1] > tmp; j--) {
			a[j] = a[j - 1];
			print_ary(a, n, "[��� �б�]");
		}
		a[j] = tmp;

		print_ary(a, n, "[���� �� ���]");
		puts("\n\n");
	}
}

int bin_search(int a[], int n, int key) {
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

void insertion2(int a[], int n) {
	int i, j;
	for (i = 1; i < n; i++) {
		int tmp = a[i];
		for (j = i; j > 0 && a[j - 1] > tmp; j--)
			a[j] = a[j - 1];

		a[j] = tmp;  // a[0] ~ a[j]�� ������ ��ģ ����
	}
}

void insertSort_test() {
	int a[] = { 5, 4, 3, 2, 1, 0 };
	int n = sizeof(a) / sizeof(int);
		
	insertion(a, n);
	int idx = bin_search(a, n, 8);
	if (idx != -1) printf("a[%d] = %d\n", idx, a[idx]);
	else puts("�������� �ʴ� Ű�Դϴ�.");
}
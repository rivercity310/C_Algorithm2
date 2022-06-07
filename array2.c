#include <stdio.h>

void arith_seq(int a[], int size, int d) {
	for (int i = 1; i < size; i++)
		a[i] = a[i - 1] + d;
}

void arith_test() {
	int a[10];
	int d;
	printf("ù��? ");
	scanf_s("%d", &a[0]);

	printf("����? ");
	scanf_s("%d", &d);

	arith_seq(a, 10, d);

	printf("��������: ");
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);
	putchar('\n');
}

int* find_key(int a[], int size, int key, int* counter) {
	static int idx[10] = { 0, };
	
	for (int i = 0; i < size; i++) {
		if (a[i] == key) {
			idx[(*counter)++] = i;
		}
	}

	printf("idx\n");
	for (int i = 0; i < *(counter); i++) {
		printf("%d ", idx[i]);
	}
	putchar('\n');
	printf("ã�� �׸��� ��� %d���Դϴ�.\n", *(counter));
	
	return idx;
}

void find_key_test() {
	int a[10] = { 12, 45, 62, 12, 99, 83, 23, 12, 72, 37 };
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);
	putchar('\n');

	int find;
	printf("ã�� ��? ");
	scanf_s("%d", &find);

	int counter = 0;
	int* idx = find_key(a, 10, find, &counter);
	
	printf("ã�� �׸��� �ε���: ");
	for (int i = 0; i < counter; i++)
		printf("%d ", *(idx + i));
}
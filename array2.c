#include <stdio.h>

void arith_seq(int a[], int size, int d) {
	for (int i = 1; i < size; i++)
		a[i] = a[i - 1] + d;
}

void arith_test() {
	int a[10];
	int d;
	printf("첫항? ");
	scanf_s("%d", &a[0]);

	printf("공차? ");
	scanf_s("%d", &d);

	arith_seq(a, 10, d);

	printf("등차수열: ");
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
	printf("찾은 항목은 모두 %d개입니다.\n", *(counter));
	
	return idx;
}

void find_key_test() {
	int a[10] = { 12, 45, 62, 12, 99, 83, 23, 12, 72, 37 };
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);
	putchar('\n');

	int find;
	printf("찾을 값? ");
	scanf_s("%d", &find);

	int counter = 0;
	int* idx = find_key(a, 10, find, &counter);
	
	printf("찾은 항목의 인덱스: ");
	for (int i = 0; i < counter; i++)
		printf("%d ", *(idx + i));
}
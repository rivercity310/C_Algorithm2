#include <stdio.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

/*
[���� ����] -> ���������� ����, O(n^2)
���� ���ĵ��� ���� �κп��� ���� ���� ���� �����ϰ�, ���� ���ĵ��� ���� �κ���
ù ��ҿ� ��ȯ�� (n - 1)ȸ �ݺ��մϴ�.
*/
void selection_sort(int a[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		int min = i;
		for (j = i + 1; j < n; j++) {
			if (a[min] > a[j]) min = j;
		}

		printf("%d�� %d��(��) ��ȯ�մϴ�.\n", a[i], a[min]);
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
}

void selection_sort_test() {
	int a[] = { 5, 4, 3, 2, 1 };
	int size = sizeof(a) / sizeof(int);

	puts("[���� ��]");
	for (int i = 0; i < size; i++)
		printf("%d ", a[i]);
	putchar('\n');

	selection_sort(a, size);

	puts("[���� ��]");
	for (int i = 0; i < size; i++)
		printf("%d ", a[i]);
	putchar('\n');
}
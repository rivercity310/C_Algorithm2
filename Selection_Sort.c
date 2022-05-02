#include <stdio.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

/*
[선택 정렬] -> 안정적이지 않음, O(n^2)
아직 정렬되지 않은 부분에서 가장 작은 값을 선택하고, 아직 정렬되지 않은 부분의
첫 요소와 교환을 (n - 1)회 반복합니다.
*/
void selection_sort(int a[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		int min = i;
		for (j = i + 1; j < n; j++) {
			if (a[min] > a[j]) min = j;
		}

		printf("%d와 %d을(를) 교환합니다.\n", a[i], a[min]);
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
}

void selection_sort_test() {
	int a[] = { 5, 4, 3, 2, 1 };
	int size = sizeof(a) / sizeof(int);

	puts("[정렬 전]");
	for (int i = 0; i < size; i++)
		printf("%d ", a[i]);
	putchar('\n');

	selection_sort(a, size);

	puts("[정렬 후]");
	for (int i = 0; i < size; i++)
		printf("%d ", a[i]);
	putchar('\n');
}
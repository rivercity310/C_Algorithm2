#include <stdio.h>
#include <stdlib.h>
#include "test.h"

#define N 20

void s_print() {
	int row = 0;
	int col = -1;
	int op = 1;
	int cnt = 0;
	int arr[N][N];
	int n;

	printf("(MAX = %d)n? ", N);
	scanf_s("%d", &n);

	int tmp = n;

	while (1) {
		for (int i = 0; i < tmp; i++) {
			col += op;
			arr[row][col] = ++cnt;
		}

		if (--tmp == 0) break;

		for (int i = 0; i < tmp; i++) {
			row += op;
			arr[row][col] = ++cnt;
		}

		op *= -1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%-5d", arr[i][j]);
		putchar('\n');
	}
}

int main() {
	struct_ex11();
}
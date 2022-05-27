#include <stdio.h>
#include <stdlib.h>

void snail_print() {
	int num;
	printf("Á¤¼ö? (MAX=20) ");
	scanf_s("%d", &num);
	
	int arr[20][20] = { 0 };
	int row = 0;
	int col = -1;
	int len = num;
	int op = 1;
	int cnt = 0;

	while (1) {
		for (int i = 0; i < len; i++) {
			col += op;
			arr[row][col] = ++cnt;
		}

		if (--len == 0) break;

		for (int i = 0; i < len; i++) {
			row += op;
			arr[row][col] = ++cnt;
		}

		op *= -1;
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++)
			printf("%-5d", arr[i][j]);
		putchar('\n');
	}
}
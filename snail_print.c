#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static int** x;

/*
(toRight, isUp)
(1, 1) => 1���� ������ �������� ++ ����
(1, 0) => n^2���� ������ �������� -- ����
(0, 1) => 1���� �Ʒ� �������� ++ ����
(0, 0) => n^2���� �Ʒ� �������� -- ����
(-1, -1) => ����
*/

void snail(int n, bool toRight, bool isUp) {
	int op = 1;
	int cnt = isUp ? 0 : (n * n) + 1;
	int row = toRight ? 0 : -1;
	int col = toRight ? -1 : 0;

	if (toRight) {
		while (1) {

			for (int i = 0; i < n; i++) {
				col += op;
				if (isUp) *(*(x + row) + col) = ++cnt;
				else *(*(x + row) + col) = --cnt;
			}

			if (--n == 0) break;

			for (int i = 0; i < n; i++) {
				row += op;
				if (isUp) *(*(x + row) + col) = ++cnt;
				else *(*(x + row) + col) = --cnt;
			}

			op *= -1;
		}
	}
	else {
		while (1) {
			for (int i = 0; i < n; i++) {
				row += op;
				if (isUp) *(*(x + row) + col) = ++cnt;
				else *(*(x + row) + col) = --cnt;
			}

			if (--n == 0) break;

			for (int i = 0; i < n; i++) {
				col += op;
				if (isUp) *(*(x + row) + col) = ++cnt;
				else *(*(x + row) + col) = --cnt;
			}

			op *= -1;
		}
	}
}

void snail_print() {
	int n;
	printf("N? ");
	scanf_s("%d", &n);

	if ((x = (int**)malloc(sizeof(int*) * n)) != NULL) {
		for (int i = 0; i < n; i++) {
			*(x + i) = (int*)malloc(sizeof(int) * n);
		}
	}

	while (1) {
		int direction;
		printf("����? (1/0) ");
		scanf_s("%d", &direction);

		int scaleUp;
		printf("ũ��? (1/0) ");
		scanf_s("%d", &scaleUp);

		if (direction == -1 && scaleUp == -1) break;
		snail(n, direction, scaleUp);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) 
				printf("%-5d", x[i][j]);
			putchar('\n');
		}
	}
	

	for (int i = 0; i < n; i++)
		if (*(x + i) != NULL) {
			printf("*(x + %d) �޸� ����, �ּ� = %p\n", i, *(x + i));
			free(*(x + i));
		}
	
	if (x != NULL) {
		printf("x �޸� ����, �ּ� = %p\n", x);
		free(x);
	}
}
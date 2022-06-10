#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// size x size 정방행렬
void snail_dmem(int** x, int size) {
	int op = 1;
	int n = size;
	int cnt = 0;
	int row = 0;
	int col = -1;


	while (1) {
		for (int i = 0; i < n; i++) {
			col += op;
			*(*(x + row) + col) = ++cnt;
		}

		if (--n == 0) break;

		for (int i = 0; i < n; i++) {
			row += op;
			*(*(x + row) + col) = ++cnt;
		}
		
		op *= -1;
	}


	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			printf("%-5d", x[i][j]);
		
		putchar('\n');
	}
}

void dmem_ex4() {
	srand(time(NULL));
	int row, column;
	
	printf("Row? ");
	scanf_s("%d", &row);

	printf("Column? ");
	scanf_s("%d", &column);

	int** x = (int**)malloc(sizeof(int*) * row);
	if (x != NULL) 
		for (int i = 0; i < row; i++)
			*(x + i) = (int*)malloc(sizeof(int) * column);
	
	/*
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (x + i != NULL && *(x + i) + j != NULL) {
				*(*(x + i) + j) = rand() % 100;
				printf("%-5d", *(*(x + i) + j));
			}
		}
		putchar('\n');
	}
	*/
	snail_dmem(x, row);

	for (int i = 0; i < row; i++)
		free(*(x + i));

	free(x);
}
#include <stdio.h>

#define ROWS_CHECK 8
#define DIAGONAL_CHECK (ROWS_CHECK - 1) * 2 + 1

int flag_a[ROWS_CHECK];
int flag_b[DIAGONAL_CHECK];
int flag_c[DIAGONAL_CHECK];
int pos[ROWS_CHECK];
int counter = 0;

extern void prt_arr(int a[], int n);

void set(int i) {
	for (int j = 0; j < ROWS_CHECK; j++) {
		if (!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + ROWS_CHECK - 1]) {
			pos[i] = j;

			if (i == ROWS_CHECK - 1) {
				counter++;
				prt_arr(pos, ROWS_CHECK);
			}
			else {
				flag_a[j] = flag_b[i + j] = flag_c[i - j + ROWS_CHECK - 1] = 1;
				set(i + 1);
				flag_a[j] = flag_b[i + j] = flag_c[i - j + ROWS_CHECK - 1] = 0;
			}
		}
	}
}

void Eight_Queen() {
	set(0);
	printf("전체 조합의 개수 = %d\n", counter);
}
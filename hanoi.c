#include <stdio.h>

int counter_h;

int hanoi(int n, int x, int y) {
	counter_h++;

	if (n > 1)
		hanoi(n - 1, x, 6 - x - y);

	printf("¿ø¹İ[%d]: %d -> %d\n", n, x, y);

	if (n > 1) 
		hanoi(n - 1, 6 - x - y, y);
}

int getCounter_h() {
	return counter_h;
}
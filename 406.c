#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 2

unsigned long long fibo(int n) {
	static int fib[500] = { 0, };

	int cnt = 0;
	fib[cnt++] = 1;
	fib[cnt++] = 1;

	if (fib[n]) return fib[n];
	else fib[n] = fibo(n - 1) + fibo(n - 2);
}

void ex7_406() {
	while (1) {
		int n;
		printf("N? ");
		scanf_s("%d", &n);
		if (n == -1) break;

		printf("피보나치 %d번째 값은 %llu\n", n, fibo(n));
	}
}

typedef struct {
	double x;
	double y;
} Point;

void set_point(Point* p, double x, double y) {
	p->x = x;
	p->y = y;
}

double get_length(Point* p1, Point* p2) {
	return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}

void prt_point(Point* p1, Point* p2) {
	printf("(%.2lf, %.2lf)와 (%.2lf, %.2lf)", p1->x, p1->y, p2->x, p2->y);
	printf("사이의 거리 : %.2lf\n", get_length(p1, p2));
	
}

void ex8_406() {
	Point* p = (Point*)malloc(sizeof(Point) * SIZE);

	Point* s = p;
	for (int i = 0; i < SIZE; i++) {
		double x, y;
		printf("점의 좌표? ");
		scanf_s("%lf %lf", &x, &y);

		set_point(s + i, x, y);
	}

	prt_point(s, s + 1);
	free(p);
}
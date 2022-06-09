#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)
#define SIZE 3

typedef struct {
	int x;
	int y;
} Point;

typedef struct {
	Point* lb;
	Point* ru;
} Rect;

void swap_dots(int* x1, int* x2) {
	int tmp = *x1;
	*x1 = *x2;
	*x2 = tmp;
}

// p1을 좌하단점, p2를 우상단점으로 하게끔 정규화
void normalize(Rect* r) {
	if (r->lb->x > r->ru->x) 
		swap(int, r->lb->x, r->ru->x);

	if (r->lb->y > r->ru->y)
		swap(int, r->lb->y, r->ru->y);
}



void print_point(const Point* p1, const Point* p2) {
	int mid_x = (p1->x + p2->x) / 2;
	int mid_y = (p1->y + p2->y) / 2;

	printf("(%d, %d)\t(%d, %d)\t", p1->x, p1->y, p2->x, p2->y);
	printf("(%d, %d)\n", mid_x, mid_y);
}

void struct_ex10() {
	Rect* rects = (Rect*)malloc(sizeof(Rect) * SIZE);
	Rect* p = rects;
	for (int i = 0; i < SIZE; i++) {
		p->lb = (Point*)malloc(sizeof(Point));
		p->ru = (Point*)malloc(sizeof(Point));

		printf("좌하단 x: ");
		scanf_s("%d", &p->lb->x);
		printf("좌하단 y: ");
		scanf_s("%d", &p->lb->y);

		printf("우상단 x: ");
		scanf_s("%d", &p->ru->x);
		printf("우상단 y: ");
		scanf_s("%d", &p->ru->y);

		p++;
	}
	
	p = rects;
	for (int i = 0; i < SIZE; i++) {
		print_point(p->lb, p->ru);
		p++;
	}

	puts("\n\nNormalizing...\n");
	p = rects;
	for (int i = 0; i < SIZE; i++) {
		normalize(p);
		p++;
	}

	p = rects;
	for (int i = 0; i < SIZE; i++) {
		print_point(p->lb, p->ru);
		p++;
	}

	p = rects;
	for (int i = 0; i < SIZE; i++, p++) {
		if (p->lb != NULL) {
			printf("(p + %d)->lb 해제\n", i);
			free(p->lb);
		}
		if (p->ru != NULL) {
			printf("(p + %d)->ru 해제\n", i);
			free(p->ru);
		}
	}

	if (rects != NULL) {
		printf("rects 해제");
		free(rects);
	}
}
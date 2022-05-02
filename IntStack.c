//#include <stdio.h>
//#include <stdlib.h>
//
///*
//max: 스택 용량
//ptr: 스택 포인터
//stk: 스택 첫 요소에 대한 포인터
//
//스택이 비어있으면 ptr은 0이고 가득 차 있으면 ptr은 max의 값과 같음
//stk[0] ~ stk[ptr - 1]
//*/
//typedef struct {
//	int max;
//	int ptr;
//	int* stk;
//} IntStack;
//
//
//int Initialize(IntStack* s, int max) {
//	s->ptr = 0;
//
//	// 배열 생성 실패
//	if ((s->stk = calloc(max, sizeof(int))) == NULL) {
//		s->max = 0;
//		return -1;
//	}
//
//	s->max = max;
//	return 0;
//}
//
//int Push(IntStack* s, int x) {
//	if (s->ptr >= s->max) return -1;      // Stack Full
//
//	s->stk[s->ptr++] = x;
//	return 0;
//}
//
//int Pop(IntStack* s, int* x) {
//	if (s->ptr <= 0) return -1;          // Stack Empty
//
//	*x = s->stk[s->ptr--];
//	return 0;
//}
//
//int Peek(const IntStack* s, int* x) {
//	if (s->ptr <= 0) return -1;
//
//	*x = s->stk[s->ptr - 1];
//	return 0;
//}
//
//void Clear(IntStack* s) {
//	s->ptr = 0;
//}
//
//int Capacity(const IntStack* s) {
//	return s->max;
//}
//
//int Size(const IntStack* s) {
//	return s->ptr;
//}
//
//int IsEmpty(const IntStack* s) {
//	return s->ptr <= 0;
//}
//
//int IsFull(const IntStack* s) {
//	return s->ptr >= s->max;
//}
//
//int Search(const IntStack* s, int x) {
//	// top부터 bottom으로 선형 검색
//	for (int i = s->ptr - 1; i >= 0; i--)
//		if (s->stk[i] == x)
//			return i;
//
//	return -1;
//}
//
//void Print(const IntStack* s) {
//	for (int i = 0; i < s->ptr; i++)
//		printf("%d ", s->stk[i]);
//	putchar('\n');
//}
//
//void Terminate(IntStack* s) {
//	if (s->stk != NULL)
//		free(s->stk);
//
//	s->max = s->ptr = 0;
//}
//
//void IntStackTest_() {
//	IntStack s;
//	if (Initialize(&s, 64) == -1) {
//		puts("스택 생성 실패!");
//		return -1;
//	}
//
//	while (1) {
//		int menu, x;
//		printf("현재 데이터 %d / %d\n", Size(&s), Capacity(&s));
//		printf("1. 푸시 2. 팝 3. 피크 4. 출력 0. 종료");
//		scanf_s("%d", &menu);
//
//		if (menu == 0) break;
//		switch (menu) {
//		case 1:
//			printf("데이터: ");
//			scanf_s("%d", &x);
//			if (Push(&s, x) == -1)
//				puts("\a오류: 푸시 실패!");
//			break;
//		}
//	}
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//

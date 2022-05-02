//#include <stdio.h>
//#include <stdlib.h>
//
///*
//max: ���� �뷮
//ptr: ���� ������
//stk: ���� ù ��ҿ� ���� ������
//
//������ ��������� ptr�� 0�̰� ���� �� ������ ptr�� max�� ���� ����
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
//	// �迭 ���� ����
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
//	// top���� bottom���� ���� �˻�
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
//		puts("���� ���� ����!");
//		return -1;
//	}
//
//	while (1) {
//		int menu, x;
//		printf("���� ������ %d / %d\n", Size(&s), Capacity(&s));
//		printf("1. Ǫ�� 2. �� 3. ��ũ 4. ��� 0. ����");
//		scanf_s("%d", &menu);
//
//		if (menu == 0) break;
//		switch (menu) {
//		case 1:
//			printf("������: ");
//			scanf_s("%d", &x);
//			if (Push(&s, x) == -1)
//				puts("\a����: Ǫ�� ����!");
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

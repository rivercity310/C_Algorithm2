#ifndef __IntStack
#define __IntStack

/*
max: ���� �뷮
ptr: ���� ������
stk: ������ ù ��ҿ� ���� ������
*/
typedef struct {
	int max;     
	int ptr;
	int* stk;
} IntStack;

// ���� �ʱ�ȯ
int Initialize(IntStack* s, int max);


#endif
#ifndef __IntStack
#define __IntStack

/*
max: 스택 용량
ptr: 스택 포인터
stk: 스택의 첫 요소에 대한 포인터
*/
typedef struct {
	int max;     
	int ptr;
	int* stk;
} IntStack;

// 스택 초기환
int Initialize(IntStack* s, int max);


#endif
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node* next;
	int data;
} Node;

void add_node(Node** pp_head, Node** pp_tail, int data) {
	if ((*pp_head) != NULL) {
		(*pp_tail)->next = (Node*)malloc(sizeof(Node));
		(*pp_tail) = (*pp_tail)->next;
	}
	else {
		(*pp_head) = (Node*)malloc(sizeof(Node));
		*pp_tail = *pp_head;
	}

	if ((*pp_tail) != NULL) {
		(*pp_tail)->data = data;
		(*pp_tail)->next = NULL;
	}
}

void lk_test() {
	Node* p_head = NULL, * p_tail = NULL, * p;

	while (1) {
		int data;
		printf(">> ");
		scanf_s("%d", &data);

		if (data == 9999) break;
		add_node(&p_head, &p_tail, data);
	}

	int sum = 0;
	p = p_head;
	while (p != NULL) {
		if (p != p_head) printf(" + ");
		printf("%d", p->data);
		sum += p->data;
		p = p->next;
	}
	printf(" = %d\n", sum);

	p = p_head;
	while (p_head != NULL) {
		p_head = p_head->next;
		free(p);
		p = p_head;
	}
	p_tail = p_head;
}
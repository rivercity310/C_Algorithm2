#include <stdio.h>
#include <stdlib.h>

typedef struct {
	double height;
	double weight;
} Person;

typedef struct node {
	struct node* next;
	Person* data;
} Node;

void add_node(Node** pp_head, Node** pp_tail, double height) {
	if ((*pp_head) != NULL) {
		(*pp_tail)->next = (Node*)malloc(sizeof(Node));
		(*pp_tail) = (*pp_tail)->next;
	}
	else {
		(*pp_head) = (Node*)malloc(sizeof(Node));
		*pp_tail = *pp_head;
	}

	if ((*pp_tail) != NULL) {
		(*pp_tail)->data->height = height;
		(*pp_tail)->next = NULL;
	}
}

void lk_test() {
	Node* p_head = NULL, * p_tail = NULL, * p;
	while (1) {
		Person person;
		printf("Å° >> ");
		scanf_s("%lf", &(person.height));
		printf("¸ö¹«°Ô >> ");
		scanf_s("%lf", &(person.weight));

		int retry;
		printf("´õ? ");
		scanf_s("%d", &retry);
			
		if (retry == 0) break;
		add_node(&p_head, &p_tail, person.height);
	}

	double sum = 0;
	p = p_head;
	while (p != NULL) {
		if (p != p_head) printf(" + ");
		printf("%.2lf", p->data->height);
		sum += p->data->height;
		p = p->next;
	}
	printf(" = %.2lf\n", sum);

	p = p_head;
	while (p_head != NULL) {
		p_head = p_head->next;
		free(p);
		p = p_head;
	}
	p_tail = p_head;
}
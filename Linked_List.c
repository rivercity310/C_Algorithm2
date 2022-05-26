#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[10];
	double weight;
	double height;
} Person;

typedef struct node {
	Person person;
	struct node* next;
} Node;

void add_node(Node** pp_head, Node** pp_tail, Person* person) {
	if ((*pp_head) != NULL) {
		(*pp_tail)->next = (Node*)malloc(sizeof(Node));
		(*pp_tail) = (*pp_tail)->next;
	}
	else {
		(*pp_head) = (Node*)malloc(sizeof(Node));
		(*pp_tail) = (*pp_head);
	}

	if ((*pp_tail) != NULL) {
		(*pp_tail)->next = NULL;
		(*pp_tail)->person.weight = person->weight;
		(*pp_tail)->person.height = person->height;
		strcpy_s((*pp_tail)->person.name, sizeof(person->name), person->name);
	}
}

void lk_test() {
	Node* p_head = NULL;
	Node* p_tail = NULL;
	Node* p;
	
	while (1) {
		Person* person = (Person*)malloc(sizeof(Person));
		if (person != NULL) {
			printf("이름? ");
			scanf_s("%s", person->name, (unsigned int)sizeof(person->name));
			if (strncmp(person->name, ".", 1) == 0) break;

			printf("키? ");
			scanf_s("%lf", &person->height);

			printf("몸무게? ");
			scanf_s("%lf", &person->weight);

			add_node(&p_head, &p_tail, person);

			free(person);
		}
	}

	double sum_weight = 0;
	p = p_head;
	while (p != NULL) {
		if (p != p_head) printf(" + ");
		sum_weight += p->person.weight;
		printf("%.2lf", p->person.weight);
		p = p->next;
	}
	printf(" = %.2lf\n", sum_weight);

	while (p_head != NULL) {
		p = p_head->next;
		free(p_head);
		p_head = p;
	}
	p_tail = p_head;
}
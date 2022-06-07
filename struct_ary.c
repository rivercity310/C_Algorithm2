#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[20];
	int price;
	int inventory;
} Product;


void print_address(Product* p) {
	puts("==========================================================");
	printf("[p�� �ּ� = %p]\n", p);
	printf("p->name�� �ּ� = %p\t, �� = %s\n", p->name, p->name);
	printf("p->price�� �ּ� = %p\t, �� = %d\n", &p->price, p->price);
	printf("p->inventory�� �ּ� = %p\t, �� = %d\n", &p->inventory, p->inventory);
	puts("==========================================================");
}

void add_products(Product** p, const char* name, int n_size, int price, int inventory) {
	if ((*p = (Product*)malloc(sizeof(Product))) != NULL) {
		strcpy_s((*p)->name, n_size, name);
		(*p)->price = price;
		(*p)->inventory = inventory;
	}
}

void struct_ary() {
	Product* products[5] = { NULL, };
	int size = sizeof(products) / sizeof(products[0]);
	int counter = 0;

	for (int i = 0; i < size; i++) {
		char name[20];
		int price, inventory;

		printf("��ǰ��? ");
		scanf_s("%s", name, (unsigned int)sizeof(name));
		if (strcmp(name, ".") == 0) break;

		printf("���� ���? ");
		scanf_s("%d %d", &price, &inventory);

		add_products(&products[i], name, sizeof(name), price, inventory);
		counter++;
	}

	for (int i = 0; i < counter; i++) {
		Product* p = products[i];
		printf("[%s %d�� ���:%d]\n", p->name, p->price, p->inventory);
	}

	puts("\n\n");
	printf("[[products�� �ּ� = %p]]\n", &products);
	for (int i = 0; i < counter; i++)
		print_address(products[i]);

	for (int i = 0; i < counter; i++)
		if (products[i] != NULL) {
			printf("products[%d] �޸� ����\n", i);
			free(products[i]);
		}
}
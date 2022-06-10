#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 3

typedef struct {
	char name[20];
	char department[10];
	int salary;
} Employee;

void prt_employee(Employee* e) {
	char buf[100];
	sprintf_s(buf, sizeof(buf), "%s/ %s/ %d����", e->name, e->department, e->salary);
	puts(buf);
}

void srh_employee(Employee* e, const char* name) {
	int flag = 0;
	for (int i = 0; i < SIZE; i++, e++) {
		if (strcmp(e->name, name) == 0) {
			flag = 1;
			break;
		}
	}

	if (flag == 1) prt_employee(e);
	else printf("%s�� ã�� �� �����ϴ�.\n", name);
}

int compare_name(const void* m, const void* n) {
	return strcmp(((Employee*)m)->name, ((Employee*)n)->name);
}

int compare_salary(const void* m, const void* n) {
	return ((Employee*)m)->salary - ((Employee*)n)->salary;
}

void dmem3_ex7() {
	Employee* e = (Employee*)malloc(sizeof(Employee) * SIZE);
	Employee* p = e;

	puts("[���� ���]");
	for (int i = 0; i < SIZE; i++, p++) {
		printf("�̸�? ");
		scanf_s("%s", p->name, (unsigned int)sizeof(p->name));

		printf("�μ���? ");
		scanf_s("%s", p->department, (unsigned int)sizeof(p->department));

		printf("����(����)? ");
		scanf_s("%d", &p->salary);
	}
	printf("%d���� ������ ����߽��ϴ�.\n", SIZE);

	p = e;
	puts("[���� ���]");
	for (int i = 0; i < SIZE; i++) {
		prt_employee(p++);
	}

	p = e;
	while (1) {
		char name[10];
		printf("�˻��� �̸�? ");
		scanf_s("%s", name, (unsigned int)sizeof(name));
		if (strcmp(name, ".") == 0) break;
		else srh_employee(e, name);
	}
	
	p = e;
	puts("<< �̸��� ���� >>");
	qsort(p, SIZE, sizeof(p[0]), compare_name);
	for (int i = 0; i < SIZE; i++, p++) prt_employee(p);
	

	p = e;
	puts("<< ������ ���� >>");
	qsort(p, SIZE, sizeof(p[0]), compare_salary);
	for (int i = 0; i < SIZE; i++, p++) prt_employee(p);

	free(e);
}
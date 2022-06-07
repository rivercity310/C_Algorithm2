#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)

// ���� �̸��� Ȯ���ڸ� �Է¹޾Ƽ� Ȯ���ڸ� ������ ���ϸ� ���
void string_ex1() {
	char name[30];
	printf("���ϸ�? ");
	scanf_s("%s", name, (unsigned int)sizeof(name));
	
	char ext[10];
	printf("Ȯ����? ");
	scanf_s("%s", ext, (unsigned int)sizeof(ext));

	strcat_s(name, sizeof(name), ".");
	strcat_s(name, sizeof(name), ext);

	printf("��ü ���ϸ�: %s", name);
}

// ������ ���ڿ��� �Է¹޾� �������� ������ ���� ���α׷� �ۼ�
void string_ex3() {
	char str[100];
	gets_s(str, sizeof(str));

	printf("�Է��� ���ڿ�: %s", str);

	int counter = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (isalpha(str[i])) {
			counter++;
		}
	}

	printf("�������� ����: %d\n", counter);
}

// ���ڿ��� �������� ����� �Լ� �ۼ��ϱ�
void reverse_str(char a[], int size) {
	for (int i = 0; i < size / 2; i++) {
		printf("a[%d] = %c", i, a[i]);
		printf("\ta[%d] = %c", size - 1 - i, a[size - i - 1]);
		putchar('\n');
		swap(char, a[i], a[size - 1 - i]);
	}
}

void string_ex5() {
	char str[30];
	printf("���ڿ�? ");
	gets_s(str, sizeof(str));

	int size = strlen(str);
	reverse_str(str, size);
	printf("����: %s", str);
}

// ��ҹ��ڸ� �������� �ʰ� ���ڿ��� ���ϴ� �Լ� �ۼ�
int strcmp_ic(char* lhs, int lhs_size, char* rhs, int rhs_size) {
	for (int i = 0; i < lhs_size; i++) {
		if (isalpha(lhs[i])) lhs[i] = tolower(lhs[i]);
		if (isalpha(rhs[i])) rhs[i] = tolower(rhs[i]);
	}

	return strcmp(lhs, rhs);
}

void string_ex6() {
	char str1[30];
	printf("ù��° ���ڿ�? ");
	scanf_s("%s", str1, (unsigned int)sizeof(str1));

	char str2[30];
	printf("�ι�° ���ڿ�? ");
	scanf_s("%s", str2, (unsigned int)sizeof(str2));

	char tmp1[30];
	char tmp2[30];
	strcpy_s(tmp1, sizeof(tmp1), str1);
	strcpy_s(tmp2, sizeof(tmp2), str2);

	int cmp = strcmp_ic(tmp1, strlen(tmp1), tmp2, strlen(tmp2));
	
	if (cmp == 0) printf("%s == %s\n", str1, str2);
	else if (cmp > 0) printf("%s > %s\n", str1, str2);
	else printf("%s < %s\n", str1, str2);
}


// �ð� ���ڿ��� �Ű������� ���޹޾� ��ȿ�� �ð����� �˻�
void check_timeStr(const char* t_str) {
	int t = atoi(t_str);

	printf("t = %d\n", t);

	int hour = t / 10000;
	int min = (t / 100) % 100;
	int sec = t % 10000 % 100;

	if (hour > 24 || min > 60 || sec > 60) {
		printf("�߸� �Է��߽��ϴ�.\n");
		printf("hhmmss �������� �Է��ϼ���.\n");
	}
	else {
		printf("%02d:%02d:%02d�� ��ȿ�� �ð��Դϴ�.\n", hour, min, sec);
	}
}

void string_ex7() {
	while (1) {
		char t_str[7];
		printf("�ð�? (.�Է� �� ����) ");
		scanf_s("%s", t_str, (unsigned int)sizeof(t_str));
		
		if (strlen(t_str) == 1 && t_str[0] == '.') break;

		check_timeStr(t_str);
	}
}





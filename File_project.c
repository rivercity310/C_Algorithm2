#include <stdio.h>
#include <string.h>
#include <locale.h>

void f_backup() {
	char in_fname[128];
	char out_fname[128];

	errno_t err;
	FILE* fin = NULL;
	FILE* fout = NULL;
	char str[BUFSIZ];

	printf("���� �̸�? ");
	gets_s(in_fname, sizeof(in_fname));

	err = fopen_s(&fin, in_fname, "r");
	if (err != 0) {
		printf("%s ���� ���� ����!\n", in_fname);
		return 1;
	}

	strcpy_s(out_fname, sizeof(in_fname), in_fname);
	strcat_s(out_fname, 5, ".bak");

	err = fopen_s(&fout, out_fname, "w");
	if (err != 0) {
		printf("%s ���� ���� ����!\n", out_fname);
		return 1;
	}

	while (fgets(str, sizeof(str), fin) != NULL)
		fputs(str, fout);

	fclose(fin);
	fclose(fout);

	printf("���� ��� ����: %s�� ��� �Ϸ�\n", out_fname);
}


void f_project() {
	/*
	UTF-8 ������� ���ڵ� �� ���Ͽ��� ���ڿ� �о����
	*/

	setlocale(LC_ALL, "ko-KR");

	errno_t err;
	FILE* fp = NULL;

	err = fopen_s(&fp, "test.txt", "rt,ccs=UTF-8");
	if (err != 0) {
		puts("���α׷� ���� ����!");
		return -1;
	}

	wchar_t buf[100];
	fgetws(buf, 100, fp);

	wprintf(L"%s\n", buf);

	fclose(fp);
}
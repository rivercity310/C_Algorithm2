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

	printf("파일 이름? ");
	gets_s(in_fname, sizeof(in_fname));

	err = fopen_s(&fin, in_fname, "r");
	if (err != 0) {
		printf("%s 파일 열기 실패!\n", in_fname);
		return 1;
	}

	strcpy_s(out_fname, sizeof(in_fname), in_fname);
	strcat_s(out_fname, 5, ".bak");

	err = fopen_s(&fout, out_fname, "w");
	if (err != 0) {
		printf("%s 파일 열기 실패!\n", out_fname);
		return 1;
	}

	while (fgets(str, sizeof(str), fin) != NULL)
		fputs(str, fout);

	fclose(fin);
	fclose(fout);

	printf("파일 백업 성공: %s로 백업 완료\n", out_fname);
}


void f_project() {
	/*
	UTF-8 방식으로 인코딩 된 파일에서 문자열 읽어오기
	*/

	setlocale(LC_ALL, "ko-KR");

	errno_t err;
	FILE* fp = NULL;

	err = fopen_s(&fp, "test.txt", "rt,ccs=UTF-8");
	if (err != 0) {
		puts("프로그램 열기 실패!");
		return -1;
	}

	wchar_t buf[100];
	fgetws(buf, 100, fp);

	wprintf(L"%s\n", buf);

	fclose(fp);
}
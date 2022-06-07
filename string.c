#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)

// 파일 이름과 확장자를 입력받아서 확장자를 포함한 파일명 출력
void string_ex1() {
	char name[30];
	printf("파일명? ");
	scanf_s("%s", name, (unsigned int)sizeof(name));
	
	char ext[10];
	printf("확장자? ");
	scanf_s("%s", ext, (unsigned int)sizeof(ext));

	strcat_s(name, sizeof(name), ".");
	strcat_s(name, sizeof(name), ext);

	printf("전체 파일명: %s", name);
}

// 한줄의 문자열을 입력받아 영문자의 개수를 세는 프로그램 작성
void string_ex3() {
	char str[100];
	gets_s(str, sizeof(str));

	printf("입력한 문자열: %s", str);

	int counter = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (isalpha(str[i])) {
			counter++;
		}
	}

	printf("영문자의 개수: %d\n", counter);
}

// 문자열을 역순으로 만드는 함수 작성하기
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
	printf("문자열? ");
	gets_s(str, sizeof(str));

	int size = strlen(str);
	reverse_str(str, size);
	printf("역순: %s", str);
}

// 대소문자를 구분하지 않고 문자열을 비교하는 함수 작성
int strcmp_ic(char* lhs, int lhs_size, char* rhs, int rhs_size) {
	for (int i = 0; i < lhs_size; i++) {
		if (isalpha(lhs[i])) lhs[i] = tolower(lhs[i]);
		if (isalpha(rhs[i])) rhs[i] = tolower(rhs[i]);
	}

	return strcmp(lhs, rhs);
}

void string_ex6() {
	char str1[30];
	printf("첫번째 문자열? ");
	scanf_s("%s", str1, (unsigned int)sizeof(str1));

	char str2[30];
	printf("두번째 문자열? ");
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


// 시간 문자열을 매개변수로 전달받아 유효한 시간인지 검사
void check_timeStr(const char* t_str) {
	int t = atoi(t_str);

	printf("t = %d\n", t);

	int hour = t / 10000;
	int min = (t / 100) % 100;
	int sec = t % 10000 % 100;

	if (hour > 24 || min > 60 || sec > 60) {
		printf("잘못 입력했습니다.\n");
		printf("hhmmss 형식으로 입력하세요.\n");
	}
	else {
		printf("%02d:%02d:%02d는 유효한 시간입니다.\n", hour, min, sec);
	}
}

void string_ex7() {
	while (1) {
		char t_str[7];
		printf("시간? (.입력 시 종료) ");
		scanf_s("%s", t_str, (unsigned int)sizeof(t_str));
		
		if (strlen(t_str) == 1 && t_str[0] == '.') break;

		check_timeStr(t_str);
	}
}





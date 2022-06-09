#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)

// 시저 암호: 암호화하고자 하는 문자열의 각 알파벳에 암호 키를 더해 다른 알파벳으로 치환
void string_ex8() {
	while (1) {
		char str[30];
		printf("문자열? ");
		scanf_s("%s", str, (unsigned int)sizeof(str));
		if (strlen(str) == 1 && str[0] == '.') break;

		int key;
		printf("암호키(정수)? ");
		scanf_s("%d", &key);

		for (int i = 0; i < strlen(str); i++) {
			str[i] += key;
		}

		printf("암호화된 문자열: ");
		puts(str);

		for (int i = 0; i < strlen(str); i++) {
			str[i] -= key;
		}

		printf("복호화된 문자열: ");
		puts(str);

		puts("\n");
	}
}

// 회원가입 유효성 검사
// ID: 영문자로 시작, 영문자와 숫자로만 구성, 최소 8자
void string_ex9() {
	while (1) {
	TOP: {
		char id[20];
		printf("ID? ");
		scanf_s("%s", id, (unsigned int)sizeof(id));

		int n = strlen(id);

		if (n < 8) {
			puts("ID는 최소 8자 이상.");
			goto TOP;
		}

		if (!isalpha(id[0])) {
			puts("ID는 영문자로 시작.");
			goto TOP;
		}

		for (int i = 0; i < n; i++) {
			if (!isalnum(id[i])) {
				puts("ID는 영문자와 숫자로만 구성.");
				goto TOP;
			}
		}
		
		printf("%s는 ID로 사용할 수 있습니다.\n", id);
		break;
		}
	}
}

// 시, 분, 초에 해당하는 정수값을 매개변수로 받아 "hh:mm:ss" 형식의 문자열 리턴하는 함수 작성
// 정수 -> 문자열 : itoa = 비표준함수 사용X, sprintf_s 사용하기
int make_timeStr(int hour, int min, int sec) {
	if (hour < 0 || hour >= 24) return -1;
	if (min < 0 || min >= 60) return -1;
	if (sec < 0 || sec >= 60) return -1;

	char buf[9];
	sprintf_s(buf, sizeof(buf), "%02d:%02d:%02d\0", hour, min, sec);

	puts(buf);

	return strlen(buf);
}

void string_ex10() {
	while (1) {
		printf("시 분 초? ");
		int h, m, s;
		scanf_s("%d %d %d", &h, &m, &s);

		int c;
		if ((c = make_timeStr(h, m, s)) == -1)
			break;
	}
}

// 이동할 글자수를 입력받아 문자열을 왼쪽이나 오른쪽으로 회전
/*
rotate 알고리즘: reverse 알고리즘으로 구현
1. 2개의 그룹으로 나눠서 reverse 
2. 전체를 다시 reverse
*/
void rotate_str(char* a, int size, int r) {
	int k = size - r;
	if (r > 0) {

		// 앞부분 reverse
		for (int i = 0; i < k; i++)
			if (i >= k / 2)
				swap(char, a[i], a[k - 1 - i]);

		printf("[앞부분 reverse (0 ~ %d)]\n", k - 1);
		puts(a);

		// 뒷부분 reverse
		int u = 0;
		for (int i = k; i < size; i++) {
			if (i >= (k + size) / 2) swap(char, a[i], a[size - 1 - u]);
			u++;
		}

		printf("[뒷부분 reverse (%d ~ %d)]\n", k, size - 1);
		puts(a);

		// 전체 reverse
		for (int i = 0; i < size; i++)
			if (i >= size / 2) swap(char, a[i], a[size - i - 1]);
	}
}

void string_ex11() {
	char str[30];
	printf("문자열? ");
	gets_s(str, sizeof(str));
	
	while (1) {
		int r;
		printf("이동할 글자수? ");
		scanf_s("%d", &r);
		if (r == 0) break;

		rotate_str(str, strlen(str), r);
		puts(str);
	}
}
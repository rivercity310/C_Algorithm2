#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)

// ���� ��ȣ: ��ȣȭ�ϰ��� �ϴ� ���ڿ��� �� ���ĺ��� ��ȣ Ű�� ���� �ٸ� ���ĺ����� ġȯ
void string_ex8() {
	while (1) {
		char str[30];
		printf("���ڿ�? ");
		scanf_s("%s", str, (unsigned int)sizeof(str));
		if (strlen(str) == 1 && str[0] == '.') break;

		int key;
		printf("��ȣŰ(����)? ");
		scanf_s("%d", &key);

		for (int i = 0; i < strlen(str); i++) {
			str[i] += key;
		}

		printf("��ȣȭ�� ���ڿ�: ");
		puts(str);

		for (int i = 0; i < strlen(str); i++) {
			str[i] -= key;
		}

		printf("��ȣȭ�� ���ڿ�: ");
		puts(str);

		puts("\n");
	}
}

// ȸ������ ��ȿ�� �˻�
// ID: �����ڷ� ����, �����ڿ� ���ڷθ� ����, �ּ� 8��
void string_ex9() {
	while (1) {
	TOP: {
		char id[20];
		printf("ID? ");
		scanf_s("%s", id, (unsigned int)sizeof(id));

		int n = strlen(id);

		if (n < 8) {
			puts("ID�� �ּ� 8�� �̻�.");
			goto TOP;
		}

		if (!isalpha(id[0])) {
			puts("ID�� �����ڷ� ����.");
			goto TOP;
		}

		for (int i = 0; i < n; i++) {
			if (!isalnum(id[i])) {
				puts("ID�� �����ڿ� ���ڷθ� ����.");
				goto TOP;
			}
		}
		
		printf("%s�� ID�� ����� �� �ֽ��ϴ�.\n", id);
		break;
		}
	}
}

// ��, ��, �ʿ� �ش��ϴ� �������� �Ű������� �޾� "hh:mm:ss" ������ ���ڿ� �����ϴ� �Լ� �ۼ�
// ���� -> ���ڿ� : itoa = ��ǥ���Լ� ���X, sprintf_s ����ϱ�
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
		printf("�� �� ��? ");
		int h, m, s;
		scanf_s("%d %d %d", &h, &m, &s);

		int c;
		if ((c = make_timeStr(h, m, s)) == -1)
			break;
	}
}

// �̵��� ���ڼ��� �Է¹޾� ���ڿ��� �����̳� ���������� ȸ��
/*
rotate �˰���: reverse �˰������� ����
1. 2���� �׷����� ������ reverse 
2. ��ü�� �ٽ� reverse
*/
void rotate_str(char* a, int size, int r) {
	int k = size - r;
	if (r > 0) {

		// �պκ� reverse
		for (int i = 0; i < k; i++)
			if (i >= k / 2)
				swap(char, a[i], a[k - 1 - i]);

		printf("[�պκ� reverse (0 ~ %d)]\n", k - 1);
		puts(a);

		// �޺κ� reverse
		int u = 0;
		for (int i = k; i < size; i++) {
			if (i >= (k + size) / 2) swap(char, a[i], a[size - 1 - u]);
			u++;
		}

		printf("[�޺κ� reverse (%d ~ %d)]\n", k, size - 1);
		puts(a);

		// ��ü reverse
		for (int i = 0; i < size; i++)
			if (i >= size / 2) swap(char, a[i], a[size - i - 1]);
	}
}

void string_ex11() {
	char str[30];
	printf("���ڿ�? ");
	gets_s(str, sizeof(str));
	
	while (1) {
		int r;
		printf("�̵��� ���ڼ�? ");
		scanf_s("%d", &r);
		if (r == 0) break;

		rotate_str(str, strlen(str), r);
		puts(str);
	}
}
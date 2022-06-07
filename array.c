#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10
#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)

void reserve() {
	char seats[N];
	for (int i = 0; i < N; i++)
		seats[i] = 'O';

	// ���ŵ� �¼���
	int counter = 0;
	while (1) {
		printf("���� �¼�: [");
		for (int i = 0; i < N; i++)
			printf("%c ", seats[i]);
		puts("]");

		int n;
		printf("������ �¼���? ");
		scanf_s("%d", &n);

		if (n > N - counter) {
			printf("���� �¼����� %d�̹Ƿ� %d�¼��� ������ �� �����ϴ�.\n", N - counter, n);
			break;
		}
		else {
			for (int i = counter; i < n + counter; i++) {
				printf("%d ", i + 1);
			}

			for (int i = counter; i < N && i < counter + n; i++)
				seats[i] = 'X';
			printf("�� �¼��� �����߽��ϴ�.\n");
		}

		counter += n;
	}
}


void shuffle() {
	int music_list[N] = { 12, 43, 39, 98, 71, 63, 8, 16, 54, 85 };
	
	printf("���� ��: ");
	for (int i = 0; i < N; i++)
		printf("%d ", music_list[i]);
	putchar('\n');

	srand(time(NULL));
	// shuffle
	for (int i = 0; i < N - 1; i++) {
		int idx = i;
		int r;     // idx���� ũ�� N���� �۰ų� ���� ���� ��������
		while (1) {
			r = rand() % N;          // 0 ~ 9
			if (r > idx && r <= N) break;
		}

		printf("%d <-> %d ��ȯ\n", idx, r);
		swap(int, music_list[idx], music_list[r]);
	}

	printf("���� ��: ");
	for (int i = 0; i < N; i++)
		printf("%d ", music_list[i]);
	putchar('\n');
}



typedef struct {
	int midterm_test;
	int final_test;
	int team_play;
	int attendence;
} Grade;

void grades() {
	Grade g[5] = {
		{28, 28, 26, 9}, {30, 27, 30, 10}, {25, 26, 24, 8}, {18, 22, 22, 5}, {24, 25, 30, 10}
	};

	double ave[5] = { 0, };
	Grade* tmp = &g;
	printf("\t\t�߰�\t�⸻\t����\t�⼮\t����\n");
	for (int i = 0; i < 5; i++) {
		int total = tmp->attendence + tmp->final_test + tmp->midterm_test + tmp->team_play;

		printf("�л�  %d��:\t", i + 1);
		printf("%d\t%d\t%d\t%d\t%d\n", tmp->midterm_test, tmp->final_test, tmp->team_play, tmp->attendence, total);

		ave[0] += tmp->midterm_test;
		ave[1] += tmp->final_test;
		ave[2] += tmp->team_play;
		ave[3] += tmp->attendence;
		ave[4] += total;

		tmp++;
	}

	printf("�׸� ���:\t");
	for (int i = 0; i < 5; i++) {
		printf("%.1lf\t", (ave[i] / 5));
	}
	putchar('\n');
}







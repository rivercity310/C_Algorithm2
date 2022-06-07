#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10
#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)

void reserve() {
	char seats[N];
	for (int i = 0; i < N; i++)
		seats[i] = 'O';

	// 예매된 좌석수
	int counter = 0;
	while (1) {
		printf("현재 좌석: [");
		for (int i = 0; i < N; i++)
			printf("%c ", seats[i]);
		puts("]");

		int n;
		printf("예매할 좌석수? ");
		scanf_s("%d", &n);

		if (n > N - counter) {
			printf("남은 좌석수가 %d이므로 %d좌석을 예매할 수 없습니다.\n", N - counter, n);
			break;
		}
		else {
			for (int i = counter; i < n + counter; i++) {
				printf("%d ", i + 1);
			}

			for (int i = counter; i < N && i < counter + n; i++)
				seats[i] = 'X';
			printf("번 좌석을 예매했습니다.\n");
		}

		counter += n;
	}
}


void shuffle() {
	int music_list[N] = { 12, 43, 39, 98, 71, 63, 8, 16, 54, 85 };
	
	printf("셔플 전: ");
	for (int i = 0; i < N; i++)
		printf("%d ", music_list[i]);
	putchar('\n');

	srand(time(NULL));
	// shuffle
	for (int i = 0; i < N - 1; i++) {
		int idx = i;
		int r;     // idx보다 크고 N보다 작거나 같은 정수 랜덤추출
		while (1) {
			r = rand() % N;          // 0 ~ 9
			if (r > idx && r <= N) break;
		}

		printf("%d <-> %d 교환\n", idx, r);
		swap(int, music_list[idx], music_list[r]);
	}

	printf("셔플 후: ");
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
	printf("\t\t중간\t기말\t팀플\t출석\t총점\n");
	for (int i = 0; i < 5; i++) {
		int total = tmp->attendence + tmp->final_test + tmp->midterm_test + tmp->team_play;

		printf("학생  %d번:\t", i + 1);
		printf("%d\t%d\t%d\t%d\t%d\n", tmp->midterm_test, tmp->final_test, tmp->team_play, tmp->attendence, total);

		ave[0] += tmp->midterm_test;
		ave[1] += tmp->final_test;
		ave[2] += tmp->team_play;
		ave[3] += tmp->attendence;
		ave[4] += total;

		tmp++;
	}

	printf("항목별 평균:\t");
	for (int i = 0; i < 5; i++) {
		printf("%.1lf\t", (ave[i] / 5));
	}
	putchar('\n');
}







#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 3

typedef enum cf {
	Ballad, HipHop, Soul, Dance, Pop
} Cf;

typedef struct {
	char title[20];
	char artist[20];
	Cf cfi;
} Song;

Cf prt_Cf() {
	int s;
	printf("�帣?\n");
	do {
		printf("0. �߶��, 1. ����, 2. �ҿ�, 3. ��, 4. �� >> ");
		scanf_s("%d", &s);
	} while (s > 5 || s < 0);

	return (Cf)s;
}

void prt_songs(Song* s) {
	char buf[100];
	sprintf_s(buf, sizeof(buf), "%20s%20s%20s", "����", "����", "�帣");
	puts(buf);

	for (int i = 0; i < SIZE; i++, s++) {
		char cfstr[10];
		switch (s->cfi) {
		case Ballad: strcpy_s(cfstr, 10, "ballad"); break;
		case HipHop: strcpy_s(cfstr, 10, "hip-hop"); break;
		case Soul: strcpy_s(cfstr, 10, "soul"); break;
		case Dance: strcpy_s(cfstr, 10, "dance"); break;
		case Pop: strcpy_s(cfstr, 10, "pop"); break;
		}

		sprintf_s(buf, sizeof(buf), "%20s%20s%20s", s->title, s->artist, cfstr);
		puts(buf);
	}
};

void struct_ex11() {
	Song* songs = (Song*)malloc(sizeof(Song) * SIZE);
	Song* p = songs;

	for (int i = 0; i < SIZE; i++, p++) {
		printf("����? ");
		gets_s(p->title, sizeof(p->title));

		printf("��Ƽ��Ʈ? ");
		gets_s(p->artist, sizeof(p->artist));

		p->cfi = prt_Cf();
		while (getchar() != '\n');
	}

	p = songs;
	prt_songs(p);

	while (1) {
		p = songs;
		char keywords[10];
		printf("Ű����(����/��Ƽ��Ʈ)? ");
		scanf_s("%s", keywords, (unsigned int)sizeof(keywords));
		if (strcmp(keywords, ".") == 0) break;

		char buf[100];
		sprintf_s(buf, sizeof(buf), "%20s%20s%20s", "����", "����", "�帣");
		puts(buf);
		for (int i = 0; i < SIZE; i++, p++) {
			if (strstr(p->artist, keywords) || strstr(p->title, keywords)) {
				char cfstr[10];
				switch (p->cfi) {
				case Ballad: strcpy_s(cfstr, 10, "ballad"); break;
				case HipHop: strcpy_s(cfstr, 10, "hip-hop"); break;
				case Soul: strcpy_s(cfstr, 10, "soul"); break;
				case Dance: strcpy_s(cfstr, 10, "dance"); break;
				case Pop: strcpy_s(cfstr, 10, "pop"); break;
				}

				sprintf_s(buf, sizeof(buf), "%20s%20s%20s", p->title, p->artist, cfstr);
				puts(buf);
			}
		}

	}

	if (songs != NULL) free(songs);
	p = NULL;
}
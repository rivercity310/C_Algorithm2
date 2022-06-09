#include <stdio.h>
#include <stdlib.h>

#define filename "date.txt"
#define SIZE 7

typedef struct {
	int year;
	int month;
	int day;
} Date;

void struct_ex12() {
	Date* d = (Date*)malloc(sizeof(Date) * SIZE);
	FILE* fp = NULL;	
	
	Date* p = d;
	if (fopen_s(&fp, filename, "r") == 0) {
		for (int i = 0; i < SIZE; i++, p++) {
			fscanf_s(fp, "%d %d %d", &p->year, &p->month, &p->day);
			printf("%02d/%02d/%02d\n", p->year, p->month, p->day);
		}
	}


	char buf[1000];
	p = d;
	if (fopen_s(&fp, "date.dat", "wb") == 0) {

		for (int i = 0; i < SIZE; i++, p++) {
			fprintf_s(fp, "%02d/%02d/%02d\n", p->month, p->day, p->year);
			sprintf_s(buf, sizeof(buf), "%02d/%02d/%02d", p->month, p->day, p->year);

			fwrite(buf, 1, 12, fp);
			puts(buf);
		}

		printf("ack!!\n");
		fread_s(buf, sizeof(buf), 12, 7, fp);
		puts(buf);
	}

	
	

	free(d);
	p = NULL;
	if (fp != NULL) fclose(fp);
}
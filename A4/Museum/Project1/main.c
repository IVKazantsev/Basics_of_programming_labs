#define _CRT_SECURE_NO_WARNINGS // Для запуска программы в VisualStudio
#include <stdio.h>
int main() {
	char* fname = "C:/Users/Honor/Desktop/Lectures/Programming/Practice/A4/Museum/Project1/txt.txt";
	FILE* fd = fopen(fname, "r");
	if (!fd) {
		printf("can't open file %s\n", fname);
		return 1;
	}
	int c, max = 1, k = 0, t1 = 0, t2 = 0, time[1440] = {0};
	while ((c = fgetc(fd)) != EOF) {
		if ((c >= '0') && (c <= '9')) {
			switch (k)
				{
				case 0:
					t1 += (c - '0') * 600;
					k += 1;
					break;
				case 1:
					t1 += (c - '0') * 60;
					k += 1;
					break;
				case 2:
					t1 += (c - '0') * 10;
					k += 1;
					break;
				case 3:
					t1 += (c - '0');
					k += 1;
					break;
				case 4:
					t2 += (c - '0') * 600;
					k += 1;
					break;
				case 5:
					t2 += (c - '0') * 60;
					k += 1;
					break;
				case 6:
					t2 += (c - '0') * 10;
					k += 1;
					break;
				case 7:
					t2 += (c - '0');
					for (int i = t1; i <= t2; i++) time[i]++;
					k = 0; t1 = 0; t2 = 0;
					break;
			}
		}
	}
	fclose(fd);
	for (int i = 0; i < 1440; i++)
		if (max < time[i]) max = time[i];
	printf("%d", max);
	return 0;
}
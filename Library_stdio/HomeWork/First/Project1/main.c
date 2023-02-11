#define _CRT_SECURE_NO_WARNINGS // Для запуска программы в VisualStudio
#include <stdio.h>

int main() {
	char* fname = "C:/Users/Honor/Desktop/Lectures/Programming/Practice/Library_stdio/HomeWork/First/Project1/BogeyBeast.txt";
	FILE* fd = fopen(fname, "r");
	if (!fd) {
		printf("can't open file %s\n", fname);
		return 1;
	}
	int c; int flag = 0; int k = 0;
	while ((c = fgetc(fd)) != EOF) {
		if ((c == 45) || (c == 39)) flag = 2;
		else if (((c < 65 || c > 90) && (c < 97 || c > 122))) flag = 1;
		else if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) && (flag == 0 || flag == 1)) {
			k += 1;
			flag = 2;
		}
	}
	fclose(fd);
	printf("%d\n", k);
	return 0;
}


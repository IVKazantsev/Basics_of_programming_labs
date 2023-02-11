#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	char* fname = "C:/Users/Honor/Desktop/Lectures/Programming/Practice/Library_stdio/HomeWork/Second/Project1/main.c";
	FILE* fd = fopen(fname, "r");
	if (!fd) {
		printf("can't open file %s\n", fname);
		return 1;
	}
	int i = -1;
	while (fseek(fd, i, SEEK_END) == 0) {
		putchar(fgetc(fd));
		i--;
	}
	fclose(fd);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



int main() {
	
	return 0;
}



void test1() {
	char* fname = "C:/Users/Honor/Desktop/Lectures/Programming/Practice/Library_stdio/stdio-2/main.c";
	char buf[256];
	FILE* fd = fopen(fname, "r");
	if (!fd) {
		printf("can't open file %s\n", fname);
		return 1;
	}
	while (fgets(buf, sizeof(buf), fd))
		puts(buf);
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

void readAndOutputFile(char* filename) {
	// ������� � f - ������ � ������; r - read; fd  -	�������� ����������
	FILE* fd = fopen(filename, "r");
	if (fd == NULL) {
		printf("�� ���� ������� ���� %s\n", filename);
		return 1;
	}
	int c;
	while ((c = fgetc(fd)) != EOF) { //��� ������, ��� ������� �����-�� ��� �������
		putchar(c);
	}
	// ����������� ����� ������� ����
	fclose(fd);
}


int main() {
	setlocale(LC_ALL, "Russian");
	//readAndOutputFile("C:/Users/Honor/Desktop/Lectures/Programming/Practice/Library_stdio/stdio-1/main.c");
	char buf[10];
	gets(buf);
	printf("%s\n", buf);


	// char *gets(char* s); // ������ �� '\n'
	// char *fgets(char* s, int n, FILE* stream);
	
	// while((c = getchar()) != EOF) {
	//		putchar(c);
	// }	
	return 0;
}

// ��������������� ����, ����� 
	//int c = getchar(); putchar(c); // putchar('a'); EOF; getchar �������� � stdin putchar �������� � stdout
	//int fgetc(FILE*); fputc(int, FILE*)
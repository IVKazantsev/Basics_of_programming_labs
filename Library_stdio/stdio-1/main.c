#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

void readAndOutputFile(char* filename) {
	// начиная с f - работа с файлом; r - read; fd  -	файловый дескриптор
	FILE* fd = fopen(filename, "r");
	if (fd == NULL) {
		printf("не могу открыть файл %s\n", filename);
		return 1;
	}
	int c;
	while ((c = fgetc(fd)) != EOF) { //Это значит, что вернуло какой-то код символа
		putchar(c);
	}
	// Обязательно нужно закрыть файл
	fclose(fd);
}


int main() {
	setlocale(LC_ALL, "Russian");
	//readAndOutputFile("C:/Users/Honor/Desktop/Lectures/Programming/Practice/Library_stdio/stdio-1/main.c");
	char buf[10];
	gets(buf);
	printf("%s\n", buf);


	// char *gets(char* s); // читает до '\n'
	// char *fgets(char* s, int n, FILE* stream);
	
	// while((c = getchar()) != EOF) {
	//		putchar(c);
	// }	
	return 0;
}

// Неформатируемый ввод, вывод 
	//int c = getchar(); putchar(c); // putchar('a'); EOF; getchar работает с stdin putchar работает с stdout
	//int fgetc(FILE*); fputc(int, FILE*)
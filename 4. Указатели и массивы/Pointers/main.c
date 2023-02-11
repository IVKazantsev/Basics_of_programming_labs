#include <stdio.h>

// Указатели и массивы. Адресная арифметика.

void f(int m[]) {}
// void f(int* m) {}. Эквивалентные записи.

int strlen(char* s) {
	//printf("my strlen\n");
	int count = 0;
//	while (s[count++]);
//	return count - 1;
	while (*s) {
		count++;
		s++;
	}
	return count;
}

int main() {
	char* ss = "abcd";
	char abcd[] = { 'a', 'b', 'c', 'd', 'e', 0}; // Представление символьной строки
	printf("%d\n", strlen(abcd));
	/*
	int a = 1, y = 2, z[10] = {0};
	int* p,* q;
	double* w; void* v;
	p = &a;
	// *p == a
	*p = 0; // В этом случае a = 0. p указывает на a.
	p = &z[5];
	p[-1]; // это будет p[4].
	p = NULL; // нельзя присваивать int кроме NULL(нулевой указатель).
	q = p;
	w = p; // нельзя присваивать разные типы.
	w = (double*)p; // так можно.
	v = p; //void-у можно присваивать др-ие типы.
	*v; // так нельзя.

	// функ-ции и указатели
	f(z);
	f(p);

	p++; p--; // можно, работает по другому.
	p = &z[0];
	p[0]; p[1]; // присваивание элем-тов z.

	p = &z[5];
	p[0]; // это будет z[5].

	// z[i] == *(z + i);
	*/
	//char* s = "abcd";
	//for (int i = 0; i < 5; i++)
	//	printf("%d ", s[i]);
	//printf("\n");

	//char c = 'D';
	//c = c + 1;
	//for (int i = 0; i < 128; i++)
	//	printf("%c", i);

	return 0;
}
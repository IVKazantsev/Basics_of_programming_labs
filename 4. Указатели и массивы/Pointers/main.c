#include <stdio.h>

// ��������� � �������. �������� ����������.

void f(int m[]) {}
// void f(int* m) {}. ������������� ������.

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
	char abcd[] = { 'a', 'b', 'c', 'd', 'e', 0}; // ������������� ���������� ������
	printf("%d\n", strlen(abcd));
	/*
	int a = 1, y = 2, z[10] = {0};
	int* p,* q;
	double* w; void* v;
	p = &a;
	// *p == a
	*p = 0; // � ���� ������ a = 0. p ��������� �� a.
	p = &z[5];
	p[-1]; // ��� ����� p[4].
	p = NULL; // ������ ����������� int ����� NULL(������� ���������).
	q = p;
	w = p; // ������ ����������� ������ ����.
	w = (double*)p; // ��� �����.
	v = p; //void-� ����� ����������� ��-�� ����.
	*v; // ��� ������.

	// ����-��� � ���������
	f(z);
	f(p);

	p++; p--; // �����, �������� �� �������.
	p = &z[0];
	p[0]; p[1]; // ������������ ����-��� z.

	p = &z[5];
	p[0]; // ��� ����� z[5].

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
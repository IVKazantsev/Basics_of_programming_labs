#include <stdio.h>

int bracket(char* s){
	int i = 0, j = 0;
	while (*s) {
		if (*s == '(') i++;
		else if (*s == ')') j++;
		if (j > i) return 0;
		s++;
	}
	if (i == j) return 1;
	else return 0;
}

int main() {
	char* s1 = "2+3*(a-b)", * s2 = "((3+2)", * s3 = ")(3+2)", * s4 = "((a+8)*10-4)", * s5 = "x*(2+2))", * s6 = "2+)a-b)",* s7 = ")((s+3)";
	printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n", bracket(s1), bracket(s2), bracket(s3), bracket(s4), bracket(s5), bracket(s6), bracket(s7));
	return 0;
}
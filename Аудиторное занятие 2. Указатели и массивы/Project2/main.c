#include <stdio.h>
#include <math.h>

int atoi(char* s) {
	int len = 0;
	while (s[len] != 0) len++;
	int value = 0, i = 1;
	while (*s) {
		if (*s < '0' || *s > '9') return -1;
		else value += (((int)*s - '0') * pow(10, (len - i)));
		i++;
		s++;
	}
	return value;
}

int main() {
	char* s1 = "555", * s2 = "9821", * s3 = "-100", * s4 = "abc",* s5 = "12345678";
	printf("%d\n%d\n%d\n%d\n%d\n", atoi(s1), atoi(s2), atoi(s3), atoi(s4), atoi(s5));
	return 0;
}
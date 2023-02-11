//Первая задача
/*#include <stdio.h>
int strcmp0(char* s1, char* s2) {
	while (*s1 == *s2) {
		s1++;
		s2++;
	}
	if (* s1 < * s2) return -1;
	if (* s1 > * s2) return 1;
	return 0;
}

int strcmp1(char* s1, char* s2) {
	while (*s1 && *s2) {
		if (*s1 != *s2) return (*s1 < *s2 ? -1 : 1);
		s1++;
		s2++;
	}
	if (!*s1 && !*s2) return 0;
	if (!*s1) return -1;
	if (!*s2) return 1;
}


int main() {
	char* s1 = "aa", * s2 = "ab", * s3 = "aab", * s4 = "b";
	printf("strcmp0(%s, %s) = %d\n", s1, s1, strcmp1(s1, s1));
	printf("strcmp0(%s, %s) = %d\n", s1, s2, strcmp1(s1, s2));
	printf("strcmp0(%s, %s) = %d\n", s1, s3, strcmp1(s1, s3));
	printf("strcmp0(%s, %s) = %d\n", s1, s4, strcmp1(s1, s4));
	printf("strcmp0(%s, %s) = %d\n", s4, s1, strcmp1(s4, s1));
	return 0;
}
*/

//Вторая задача
/*#include <stdio.h>
int palindrom(char* s) {
	char* r = s;
	while (*r++);
	r--; r--;
	while(s < r) {
		if (*s != *r)
			return 0;
		s++;
		r--;
	}
	return 1;
}

int main() {
	char* s = "ABBA";
	printf("palindrom(%s) = %d\n", s, palindrom(s));
	return 0;
}
*/

// Третья задача
/*#include <stdio.h>
int strstr(char* s1, char* s2) {

}

int main() {

	return 0;
}*/
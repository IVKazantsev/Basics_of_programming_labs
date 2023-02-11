#include <stdio.h>

int strlen(char* s) {
	int len = 0;
	while (s[len] != 0) len++;
	return len;
}

int strcmp(char* s1, char* s2) {
	int count1 = 0;
	int count2 = 0;
	for (int i = 0; i < strlen(s1); i++) {
		if (s1[i] < s2[i]) break;
		count1 += (int)s1[i];
	}
	for (int i = 0; i < strlen(s2); i++) {
		if (s1[i] > s2[i]) break;
		count2 += (int)s2[i];
	}
	if (count1 == count2) return 0;
	else if (count1 > count2) return 1;
	else return -1;
}

main() {
	char* s1 = "ad",* s2 = "abc";
	printf("%d\n", strcmp(s1, s2));
	return 0;
}
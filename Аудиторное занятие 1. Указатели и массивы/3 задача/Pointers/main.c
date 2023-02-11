#include <stdio.h>
int strlen(char* s) {
	int len = 0;
	while (s[len] != 0) len++;
	return len;
}
char* strstr(char* s1, char* s2) {
	int first = 1;
	int count = 0;
	int value = 0;
	for (int i = 0; i < strlen(s1); i++) {
		if (strlen(s2) > strlen(s1)) return NULL;
		else if (s1[i] == s2[count]) {
			if (first == 1) value = i;
			count++;
			first = 0;
		}
		else {
			if ((count == strlen(s2)) && (first == 0)) break;
			else {
				count = 0;
				first = 1;
				value = NULL;
			}
		}
	}
	if (((first == 0) && (count != strlen(s2))) || (first == 1)) return NULL;
	else return (&(s1[value]));
}
main() {
	char* s1 = "ababc";
	char* s2 = "ba";
	char* endstr = strstr(s1, s2);
	return 0;
}
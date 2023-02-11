#include <stdio.h>

int strlen(char* s) {
	int len = 0;
	while (s[len] != 0) len++;
	return len;
}

palindrom(char* p) {
	int flag = 0;
	if (strlen(p) == 2) {
		for (int i = 0; i < 3; i++) {
			if (p[i] < 70) {
				if (p[i] != p[strlen(p) - 1 - i] && p[i] + 32 != p[strlen(p) - 1 - i] && p[i] != p[strlen(p) - 1 - i] + 32) {
					flag = 1;
					break;
				}
			}
			if (p[i] > 70) {
				if (p[i] != p[strlen(p) - 1 - i] && p[i] + 32 != p[strlen(p) - 1 - i] && p[i] != p[strlen(p) - 1 - i] + 32) {
					flag = 1;
					break;
				}
			}
		}
	}
	for (int i = 0; i < (strlen(p) / 2); i++) {
		if (p[i] < 70) {
			if (p[i] != p[strlen(p) - 1 - i] && p[i] + 32 != p[strlen(p) - 1 - i] && p[i] != p[strlen(p) - 1 - i] + 32) {
				flag = 1;
				break;
			}
		}
		else if (p[i] > 70) {
			if (p[i] != p[strlen(p) - 1 - i] && p[i] + 32 != p[strlen(p) - 1 - i] && p[i] != p[strlen(p) - 1 - i] + 32) {
				flag = 1;
				break;
			}
		}
	}
	if (flag == 0) return 1;
	else return 0;
}

main() {
	char* p1 = "AbDBa";
	if (palindrom(p1) == 0) printf("NOT palindrom");
	if (palindrom(p1) == 1) printf("Palindrom");
	return 0;
}

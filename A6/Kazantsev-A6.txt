#include <stdio.h>
#define N 28
int hopcost(char* str, int k) {
	int price = 0, i = 0, Flag = 0, flag = 0;
	while (i < N) {
		for (int j = i; j <= (i + k); j++) {
			flag = 0;
			if (str[j] == str[i]) i = j;
			if (j >= N) { Flag = 1; break; }
		}
		if (Flag == 1) break;
		for (int j = (i + k); j >= i; j--) {
			for (int l = (j + k); l > j; l--) {
				if ((str[j] == str[l]) && ((str[j] >= 'A') && (str[j] <= 'Z'))) {
					i = j;
					price++;
					flag = 0;
				}
				else flag = 1;
				if ((l >= N) && ((str[i] < 'A') || (str[i] > 'Z'))) { flag = 1; break; }
			}
		}
	}
	if ((i != N) && (flag == 1)) price++;
	return price;
}

int main() {
	printf("%d", hopcost("ABCDDBBCCADEACBABCABBACCADEA", 3));
	return 0;
}
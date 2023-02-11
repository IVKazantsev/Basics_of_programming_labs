#include <stdio.h>

int main() {
	int n = 30;
	for (int i = 0; i < 8; i++) {
		int b = (n >> (28 - i * 4)) & 0xF;
		if (b <= 9) printf("%d", b);
		else if (b == 10) printf("A");
		else if (b == 11) printf("B");
		else if (b == 12) printf("C");
		else if (b == 13) printf("D");
		else if (b == 14) printf("E");
		else if (b == 15) printf("F");
	}

	return 0;
}
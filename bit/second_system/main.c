#include <stdio.h>

int main() {
	int n = 16;
	for (int i = 0; i < 32; i++) {
		int b = (n >> (31 - i)) & 0x1;
		printf("%d", b);
	}
	return 0;
}
#include <stdio.h>
#define N 8

int main() {
	int x[N] = { 0, 0, 1, 1, 2, 2, 3, 3}, y[N] = { 0, 1, 0, 1, 0, 1, 0, 1}, a, b, c, z, count = 0;
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++) {
			z = 0;
			for (int k = 0; k < N; k++) {
				if (k != i && k != j) {
					a = (x[i] - x[k]) * (x[i] - x[k]) + (y[i] - y[k]) * (y[i] - y[k]);
					b = (x[j] - x[k]) * (x[j] - x[k]) + (y[j] - y[k]) * (y[j] - y[k]);
					c = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
					if (c == a + b) z++;
				}
			}
			if (z == 2) count++;
		}
	printf("%d", count / 2);
	return 0;
}
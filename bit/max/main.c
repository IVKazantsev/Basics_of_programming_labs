#include <stdio.h>

// оличество значимых цифр
int znach(int n) {
	int k = 0;
	for (int i = 0; i < 32; i++) {
		int b = (n >> (31 - i)) & 0x1;
		if (b == 1) return (32 - k);
		k += 1;
	}
}

int main() {
	int n = 11, a[32] = { 0 }, b = znach(n), max = 0, t = 0, stepen = 1;
	// ѕрисвоение двоичного числа массиву
	for (int i = 0; i < 32; i++) a[i] = ((n >> (31 - i)) & 0x1);

	for (int h = 1; h < b; h++) {
		// ѕредставление двоичного числа в дес€тичной системе и проверка на максимальное значение
		for (int p = 0; p < b; p++) {
			if ((p == 0) && (a[31] == 1)) t = t + 1;
			else if (p != 0) {
				stepen *= 2;
				t += a[31 - p] * stepen;
			}
		}
		if (max < t) max = t;
		t = 0, stepen = 1;
		// ÷икл перестановки
		a[31 - b] = a[31];
		for (int j = 0; j < b; j++) a[31 - j] = a[31 - j - 1];
		a[31 - b] = 0;

	}
	//ѕредставление последнего двоичного числа в дес€тичной системе и проверка на максимальное значение
	for (int p = 0; p < b; p++) {
		if ((p == 0) && (a[31] == 1)) t = t + 1;
		else {
			stepen *= 2;
			t += a[31 - p] * stepen;
		}
	}
	if (max < t) max = t;
	printf("%d", max);
	return 0;
}
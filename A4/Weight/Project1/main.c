#include <stdio.h>

int isPrime(int n) { // проверка на простоту
    for (int d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 1; // не простое
       return 0; // простое
}
int nextPrime(int n) { // следующее простое число
    for (int i = n + 1; i < 99999; i++)
        if (isPrime(i) == 0) return i;
    return 0;
}

int main() {
    int m, N = 8; // m - следующее простое число после N, N - кол-во гирь
    if (N == 2) printf("1 2");
    else if (isPrime(N) == 0)
        for (int i = N - 1; i >= ((N + 1) / 2); i--) printf("%d %d\n", i, N - i);
    else
        while (N > 0) {
            m = nextPrime(N);
            if ((m == 0) || (m >= 2 * N)) break;
            for (int i = (m - N); i <= (m / 2); i++) printf("%d %d\n", i, m - i);
            N = m - N - 1;
        }
	return 0;
}

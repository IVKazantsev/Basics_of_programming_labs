#include <stdio.h>
//#include <stdlib.h>
#define B 1
#define K 2
#define X 3

#define abs(i) ((i) < 0 ? -(i) : (i)) // Если i меньше 0, то менять на -i, иначе оставлять.

int main() {
	int b[8][8] = {0};
	//B - слон. Пусть стоит на f5[4][5].
	int Bi = 4, Bj = 5;
	b[Bi][Bj] = B;
	//K - конь. Пусть стоит на d3[2][3].
	int Ki = 2, Kj = 3;
	b[Ki][Kj] = K;


	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (b[i][j] == B) continue;
			if (b[i][j] == K) { 
				// Лево
				if ((i + 1 < 8) && (j - 2 >= 0) && b[i + 1][j - 2] != B) b[i + 1][j - 2] = X;
				if ((i - 1 >= 0) && (j - 2 >= 0) && b[i - 1][j - 2] != B) b[i - 1][j - 2] = X;
				// Право
				if ((i + 1 < 8) && (j + 2 < 8) && b[i + 1][j + 2] != B) b[i + 1][j + 2] = X;
				if ((i - 1 >= 0) && (j + 2 < 8) && b[i - 1][j + 2] != B) b[i - 1][j + 2] = X;
				// Верх
				if ((i + 2 < 8) && (j + 1 < 8) && b[i + 2][j + 1] != B) b[i + 2][j + 1] = X;
				if ((i + 2 < 8) && (j - 1 >= 0) && b[i + 2][j - 1] != B) b[i + 2][j - 1] = X;
				// Низ
				if ((i - 2 >= 0) && (j + 1 < 8) && b[i - 2][j + 1] != B) b[i - 2][j + 1] = X;
				if ((i - 2 >= 0) && (j - 1 >= 0) && b[i - 2][j - 1] != B) b[i - 2][j - 1] = X;

			}

			if (abs(Bi - i) == abs(Bj - j)) {
				if (!(abs(Bi - Ki) == abs(Bj - Kj)))
					b[i][j] = X;
				else {
					int BKx = Ki - Bi, BKy = Kj - Bj, KCx = i - Ki, KCy = j - Kj, AxB = BKx * KCy - BKy * KCx;
					int KBx = Bi - Ki, KBy = Bj - Kj, scalprod = KBx * KCx + KBy * KCy;
					if (!(AxB == 0 && scalprod <= 0))
						b[i][j] = X;
				}
			}
		}
	}


	for (int i = 7; i >= 0; i--) {
		for (int j = 0; j < 8; j++) {
			if (b[i][j] == B) printf(" B");
			else if (b[i][j] == K) printf(" K");
			else if (b[i][j] == X) printf(" x");
			else printf("%2d", b[i][j]);

		}
		printf("\n");
	}
	return 0;
}
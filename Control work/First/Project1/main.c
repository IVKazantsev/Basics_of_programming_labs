#include <stdio.h>
#define N 7

int main() {
    int x, y, value = 1, Snake[N][N];
    for (int i = 0; i < N; i++) { // �� ������� ��������� ������������
        if ((i % 2) == 0) { // ׸���� ���������
            x = 0, y = i;
            while (y >= 0) {
                Snake[x][y] = value;
                x++, y--, value++;
            }
        }
        else { // �������� ���������
            x = i, y = 0;
            while (x >= 0) {
                Snake[x][y] = value;
                x--, y++, value++;
            }
        }
    }
    if ((N % 2) == 0) { // ׸���� ������� �������
        for (int i = 1; i < N; i++) { // ����� ������� ���������
            if ((i % 2) == 0) { // ׸���� ���������
                x = N - 1, y = i;
                while (y <= (N - 1)) {
                    Snake[x][y] = value;
                    x--, y++, value++;

                }
            }
            else { // �������� ���������
                x = i, y = N - 1;
                while (x <= (N - 1)) {
                    Snake[x][y] = value;
                    x++, y--, value++;
                }
            }
        }
    }
    else { // �������� ������� �������
        for (int i = 1; i < N; i++) { // ����� ������� ���������
            if ((i % 2) == 0) { // ׸���� ���������
                x = i, y = N - 1;
                while (x <= (N - 1)) {
                    Snake[x][y] = value;
                    x++, y--, value++;
                }
            }
            else { // �������� ���������
                x = N - 1, y = i;
                while (y <= (N - 1)) {
                    Snake[x][y] = value;
                    x--, y++, value++;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) { // ����� �������
        for (int j = 0; j < N; j++)
            printf("%2d ", Snake[i][j]);
        printf("\n");
    }
    return 0;
}

#include "SomeFunction.hpp"
#include <math.h>

const int N_max = 1000;

bool isPrime(int x)
{
    // Тело
    if (x < 2)
        // Возврат результата
        return false;
    for (int d = 2; d <= sqrt(x); d++)
        if (x % d == 0)
            return false;
    return true;
}

// Обмен двух переменных
// void - функция ничего не возвращает (процедура)
void swap(int& a, int& b) // & - это передача по ссылке
{
    int tmp = a;
    a = b;
    b = tmp;
}

// Сортировка
void sort(int n, int mas[N_max])
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n - 1; j++)
            if (mas[i] < mas[j])
                swap(mas[i], mas[j]);
}

// Поиск суммы цифр числа
int sumOfDigits(int x)
{
    int sum = 0;
    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    }
}
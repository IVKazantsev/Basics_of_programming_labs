#include <stdio.h>

// void f(int n) {} // void - "ничто". Функция, которая ничего не возвращает - это процедура

// void f(int n, ...){} // "Возможно, создали только для printf"

int summ(int n) // перечисление переменных(int n) должно происходить индивидуально
{
	int sum = 0;
	for (int i = 1; i < n; i++)
		sum += i;
	return sum;
}

int factorial1(int n) {
	int f1 = 1;
	for (int i = 1; i <= n; i++)
		f1 *= i;
	return f1;
}

// n! = n*(n-1)
int factorial2(int n) {
	if (n == 1) return 1;
	return (n * factorial2(n - 1));
}

int main()
{
	printf("summ = %d\n", summ(100));
	printf("factorial1 = %d\n", factorial1(3));
	printf("factorial2 = %d\n", factorial2(3));

	return 0;
}
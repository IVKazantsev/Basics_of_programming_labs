
#include <iostream>
#include "SomeFunctions.hpp"

int main()
{
    int n = 37;
    std::cout << sumOfDigits(n) << " " << n << std::endl;

    int n = 5;
    int arr[N] = { 5,3,1,-20,0 };
    sort(n, arr);
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " " << std::endl;

    int a, b;;
    std::cin >> a >> b;

    swap(a, b);
    std::cout << a << " " << b << std::endl;

    int x;
    std::cin >> x;

    // Определение простоты числа
    std::cout << isPrime(x) << std::endl;
}
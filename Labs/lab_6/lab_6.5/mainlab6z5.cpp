#include <iostream>
#include <cmath>

bool contains_7(int n) {
    
    while (n > 0) {
    if (n % 10 == 7)
        return true;
    n = n / 10;
    }
    return false;
}

bool not_contains_6(int n) {
    while (n > 0) {
        if (n % 10 == 6)
            return false;
        n = n / 10;
    }
    return true;
}

bool is_prime(int n) {
    if (n == 1) return false;
    int r = sqrt(n);
    for (int d = 2; d <= r; d++) {
        if (n % d == 0) 
            return false;
    }
    return true;
}


int main() {
    int n;
    std::cout << "Введите количество чисел в последовательности: ";
    std::cin >> n;

    int a[10000];
    std::cout << "Введите числа последовательности: ";
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    

    int newsize = 0;

    for (int i = 0; i < n; i++) {
        if (!(contains_7(a[i]) && not_contains_6(a[i]))) {
            a[newsize++] = a[i];
        }
    }

    int finalsize = newsize;

    for (int i = 0; i < newsize; i++) {
        if (is_prime(a[i]) && finalsize < 10000) {
            a[finalsize++] = a[i];
        }
    }

    std::cout << "Результат: ";
    for (int i = 0; i < finalsize; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}


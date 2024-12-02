#include <iostream>

int pervone(int num) {
    while (num >= 10) {
        num /= 10;
    }

    return num;
}

int sumdigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum; 
}

void sort(int a[], int n) {

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int firstdigit1 = pervone(a[i]);
            int firstdigit2 = pervone(a[j]);

            if (firstdigit1 > firstdigit2 || (firstdigit1 == firstdigit2 && sumdigits(a[i]) > sumdigits(a[j])) || (firstdigit1 == firstdigit2 && sumdigits(a[i]) == sumdigits(a[j]) && a[i] > a[j])) {
                std::swap(a[i], a[j]);
            }
        }
    }
}

int main() {
    int n;
    std::cout << "Введите количество чисел в последовательноси: ";
    std::cin >> n;

    int a[1000];

    std::cout << "Введите числа последовательности: ";
    for (int i = 0; i < n; i++)  std::cin >> a[i];

    sort(a, n);

    std::cout << "Результат: ";
    for (int i = 0; i < n; i++) std::cout << a[i] << " ";



    return 0;
}
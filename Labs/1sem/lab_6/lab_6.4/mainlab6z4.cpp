#include <iostream>

int main() {
    int a[1000];
    int n;


    std::cout << "Введите количество чисел в последовательности: ";
    std::cin >> n;

    std::cout << "Введите числа последовательности: ";
    for (int i = 0; i < n; i++) std::cin >> a[i];


    int unical = 0;
    for (int i = 0; i < n; i++) {
        bool dublicate = false;
        for (int j = 0; j < unical; j++) {
            if (a[i] == a[j]) {
                dublicate = true;
                break;
            } 
        }

        if (dublicate == false) {
            a[unical] = a[i];
            unical++;
        }
    } 
    
    std::cout << "Выводим без дубликатов: ";
    for (int i = 0; i < unical; i++) std::cout << a[i] << " ";

    std::cout << std::endl;

    return 0;
}
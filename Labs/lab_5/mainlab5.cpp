#include <iostream>    //1 задание
#include <limits>


int main() {

    int n;

    std::cout << "Введите количество чисел в последовательности: ";
    std::cin >> n;

    int proizv = 1;
    int minNum = std::numeric_limits<int>::max();   // для нахождения минимального числа
    int minInd = -1;
    bool flag = false;

    for (int i = 1; i <= n; i++) {
        int number;
        std::cout << "Введите число номер " << i << ": ";     // последовательность
        std::cin >> number;

        int lastdigit = number % 10;
        if (lastdigit == 2 || lastdigit == 4) {
            flag = true;
            proizv *= number;               // произведение на 2 и 4
            if (number < minNum) {
                minNum = number;            // минимальное число
                minInd = i;                 // номер минимального числа
            }
        }
    }

    if (flag) {
        std::cout << "Произведение чисел оканчивающихся на 2 и 4: " << proizv << std::endl;
        std::cout << "Наименьше из таких чисел: " << minNum << std::endl;
        std::cout << "Номера этого числа: " << minInd << std::endl;
    } 
        else {
            std::cout << "Чисел оканчивающихся на 2 и 4, нет" << std::endl;
        }


// 2 задание

    long long N;
    std::cout << "Введите число N(N<10^9) для второго задания: ";
    std::cin >> N;

    int maxdigit = 0;
    
    while (N > 0) {
        int lastdigit = N%10;
        if (lastdigit > maxdigit) {
            maxdigit = lastdigit;
        }
        N = N/ 10;
    }

    std::cout << "Наибольшая цифра: " << maxdigit << " (2 задание)";


    return 0;

}
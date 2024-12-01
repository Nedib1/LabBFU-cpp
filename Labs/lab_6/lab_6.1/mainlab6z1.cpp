#include <iostream>
int pervone(int num) {
    while (num >= 10) {
        num /= 10;                        //первая цифра      
    }                           

    return num;
}

void sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {     //сортировка
            if (a[i] > a[j]) {
                std::swap(a[i], a[j]);
            }
        }
    }
}

int main() {

    int n;
    std::cout << "Введите колчество числел в последовательности: ";
    std::cin >> n;

    int a[10000];
    bool flag = false;

    std::cout << "Введите числа: "; 
    for (int i = 0; i < n; i++) {     // последовательность
        std::cin >> a[i];
        if (pervone(a[i]) == 1) {
            flag = true;
        }
    }

    if (flag) sort(a, n); 

    std::cout << "Результат: ";
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";  
    }

 

    return 0;
}
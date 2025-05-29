#include <iostream>
using namespace std;

long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Введите число N: ";
    cin >> n;

    if (n < 1 || n > 19) {
        cout << "Неверное значение N!" << endl;
        return 1;
    }

    cout << "Факториал: " << factorial(n) << endl;
    return 0;
}

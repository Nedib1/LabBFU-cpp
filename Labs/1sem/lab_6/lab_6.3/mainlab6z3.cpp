#include <iostream>

const int max_m = 100;

void zamena(int mat[max_m][max_m], int n, int m) {
    int blizstr = 0;
    int minsum = INT_MAX;


    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = 0; j < m; j++) {
            sum += mat[i][j];
        }

        if (std::abs(sum) < minsum) {
            minsum = std::abs(sum);
            blizstr = i;
        }
    }

    for (int j = 0; j < m; j++) mat[blizstr][j] = 0; 
    
}

int main() {
    int n, m;
    int mat[max_m][max_m];

    std::cout << "Введите количество строк и столбцов: ";
    std::cin >> n >> m;

    std::cout << "Введите элементы матрицы: " << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> mat[i][j];
        }
    }

    zamena(mat, n ,m);

    std::cout << "Результат: " << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }

}

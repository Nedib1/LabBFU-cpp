#include "mat.hpp"
#include <iostream>

namespace matproccesing {

    void readmat(int mat[max_size][max_size], int& n) {
        std::cout << "Введите размер матрицы: ";
        std::cin >> n;

        std::cout << "Введите элементы матрицы: " << std::endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cin >> mat[i][j];
            }
        }
    }

    bool is_prime(int n) {
        if (n == 1) return false;
        int r = sqrt(n);
        for (int d = 2; d <= r; d++)
            if (n % d == 0) return false;
        return true;
    }

    bool nalprime(int mat[max_size][max_size], int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (is_prime(abs(mat[i][j]))) return true;
            }
        }
        return false;
    }

    bool odinakstolb(int mat[max_size][max_size], int n, int stolb1, int stolb2) {
        for (int i = 0; i < n; i++) {
            if (mat[i][stolb1] != mat[i][stolb2]) return false;
        }
        return true;
    }

    bool nalodinakstolb(int mat[max_size][max_size], int n) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (odinakstolb(mat, n, i, j)) return true;
            }
        }
        return false;
    }

    int rowabssum(int row[max_size], int n) {
        int sum = 0;
        for (int j = 0; j < n; j++) sum += abs(row[j]);

        return sum;
    }

    void sortrowabssum(int mat[max_size][max_size], int n) {
        int rowsum[max_size], index[max_size];

        for (int i = 0; i < n; i++) {
            rowsum[i] = rowabssum(mat[i], n);
            index[i] = i;
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (rowsum[i] > rowsum[j]) {
                    std::swap(rowsum[i], rowsum[j]);
                    std::swap(index[i],index[j]);
                }
            }
        }

        int copmat[max_size][max_size];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                copmat[i][j] = mat[index[i]][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = copmat[i][j];
            }
        }
    }

    void writemat(int mat[max_size][max_size], int n) {
        std::cout << "Результат: " << std::endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << mat[i][j] << " ";  
            }
            std::cout << std::endl;
        }
    }


}
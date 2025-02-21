#include "mat.hpp"
#include <iostream>

int main() {
    using namespace matproccesing;

    int mat[max_size][max_size];
    int n;

    readmat(mat, n);

    if (nalodinakstolb(mat, n) && nalprime(mat, n)) {
        sortrowabssum(mat, n);
    }

    writemat(mat, n);

    return 0;
}
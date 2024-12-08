#ifndef mat_hpp
#define mat_hpp

const int max_size = 100;

namespace matproccesing {
    void readmat(int mat[max_size][max_size], int& n);
    bool is_prime(int n);
    bool nalprime(int mat[max_size][max_size], int n);
    bool odinakstolb(int mat[max_size][max_size], int n, int stolb1, int stolb2);
    bool nalodinakstolb(int mat[max_size][max_size], int n);
    int rowabssum(int row[max_size], int n);
    void sortrowabssum(int mat[max_size][max_size], int n);
    void writemat(int mat[max_size][max_size], int n);
}


#endif
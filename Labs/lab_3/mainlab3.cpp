#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int x,i;
    cin >> x >> i;

    if ((x>0) && (x<pow(10,9)) && ((i>=0) && (i<32))) 
    {
        cout << (x | (1 << i)) << endl;
    }
    else
    {
        cout <<" нельзя установить i-ый числа x в 1" << endl;
    } 


}
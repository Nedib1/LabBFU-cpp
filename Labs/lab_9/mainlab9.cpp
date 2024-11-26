#include <iostream>
#include <iomanip>

int main() 
{
    int a;
    std::cin >> a;

    unsigned char * p = (unsigned char *) &a;

    for (int i = 0; i < sizeof(a); i++) {
        int b = *(p + i);
        std::cout << "байт" << i + 1 << ": 0x" <<std::hex << std::setw(2) << std::setfill('0') << (int)b << "\n";
    }

    return 0;

}
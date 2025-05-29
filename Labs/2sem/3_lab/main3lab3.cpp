#include <iostream>
#include <cmath>

class square
{
    public:
        double a;


        square(double length) {
            a = length;
        }

        square(int side = 1) {
            a = side;
        }

        int getArea() {
            return a * a;
        }

        int perimeter() {
            return a * 4;
        }

        int diagonal() {
            return sqrt(2) * a;
        }

        void printInfo(bool detail) {
            std::cout << "length: " << a << std::endl;

            if(detail) {
             std::cout << "Area: " << getArea() << std::endl;
             std::cout << "perimeter: " << perimeter() << std::endl;
             std::cout << "diagonal: " << diagonal() << std::endl;
            }
        }


};

int main() {
    square sqr1;
    square sqr2;

    sqr1.a = 1;
    

    sqr2.a = 5;


    sqr1.printInfo(true);
    sqr2.printInfo(false);
}
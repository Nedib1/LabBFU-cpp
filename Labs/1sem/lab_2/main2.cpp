#include <iostream>
#include <cmath>

using namespace std;

int main() 
{

    double a,b,c;

    cin>>a>>b>>c;

    double p=(a+b+c)/2;

    if ((a>0 && b>0 && c>0) && ((a+b>c) && (a+c>b) && (c+b>a)))
    {
        cout << sqrt(p*(p-a)*(p-b)*(p-c)) << endl;
    }
    else 
    {
        cout << "такого треугольника не существует" << endl;
    }

}
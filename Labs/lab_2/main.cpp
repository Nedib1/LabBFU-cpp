#include <iostream>
#include <cmath>

using namespace std;

int main() 
{

    int a,b,c;

    cin>>a>>b>>c;

    int p=(a+b+c)/2;

    if (a>0 && b>0 && c>0)
    {
        cout << sqrt(p*(p-a)*(p-b)*(p-c)) << endl;
    }

}
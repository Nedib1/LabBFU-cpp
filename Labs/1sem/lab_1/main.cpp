#include <iostream>     
#include <limits>       

using namespace std;

int main () {
    string text = "1. Переменная - это ячейка в памяти выделяемая под значение какого-либо типа данных(коробка с вещью)\n"
    "2. Типы данных\n"
    "1) Целочисленные\n"
    "- short, 2 байта, -32768...32767\n"
    "- int, 4 байта, -2^31...2^31-10\n"
    "- long long, 8 байт, 0...2^32-1\n"
    "2) Символьный\n"
    "- char, 1 байт, -128...127\n"
    "3) Вещественный\n"
    "- float, 4 байт, точность 6-7 цифр\n"
    "- double, 8 байт, точность 15-16 цифр\n"
    "4) Логический\n"
    "- bool, 1 байт, True/False\n"
"Арифметические операции\n";
	cout<<"максимальные значения"<<endl;
    cout<<numeric_limits<int>::max()<<" int "<<endl;
	cout<<+numeric_limits<char>::max()<<" char "<<endl;
    cout<<numeric_limits<double>::max()<<" double "<<endl;
    cout<<numeric_limits<bool>::max()<<" bool "<<endl;
	cout<<numeric_limits<long>::max()<<" long "<<endl;
    cout<<numeric_limits<long double>::max()<<" long long "<<endl;
    cout<<numeric_limits<short>::max()<<" short "<<endl;
    cout<<numeric_limits<float>::max()<<" float "<<endl;
    cout<<endl;
	cout<<"минимальные значения"<<endl;
    cout<<numeric_limits<int>::min()<<" int "<<endl;
	cout<<+numeric_limits<char>::min()<<" char "<<endl;
    cout<<numeric_limits<double>::min()<<" double "<<endl;
    cout<<numeric_limits<bool>::min()<<" bool "<<endl;
	cout<<numeric_limits<long>::min()<<" long "<<endl;
    cout<<numeric_limits<long double>::min()<<" long long "<<endl;
    cout<<numeric_limits<short>::min()<<" short "<<endl;
    cout<<numeric_limits<float>::min()<<" float "<<endl;
	cout<<endl;

	cout << "размер в байтах" << endl;
	cout << " int " << sizeof(int) << " bytes" << endl;
	cout << " char " << sizeof(char) << " bytes" << endl;
	cout << " double " << sizeof(double) << " bytes" << endl;
	cout << " bool " << sizeof(bool) << " bytes" << endl;
	cout << " long " << sizeof(long) << " bytes" << endl;
	cout << " long double " << sizeof(long double) << " bytes" << endl;
	cout << " short " << sizeof(short) << " bytes" << endl;
	cout << " float " << sizeof(float) << " bytes" << endl;
	cout<<endl;

	cout<<"арифметические операции"<<endl;
	cout<<"int"<<endl;
	int a,b;
	a=1323232;
	b=1223232;
	cout<<"a=1323232"<<" "<<"b=1223232"<<" "<<"a+b"<<"="<<a+b<<endl;
    cout<<endl;
	cout<<"char"<<endl;
	char c,d;
	c=char(120);
	d=char(110);
	cout<<"c=120"<<" "<<"d=110"<<" "<<"c*d"<<"="<<c*d<<endl;
    cout<<endl;
    cout<<"double"<<endl;
	double a1,a2;
    a1=1.34;
    a2=1.42;
    cout<<"a1=1.34"<<" "<<"a2=1.42"<<" "<<"a1/a2"<<"="<<a1/a2<<endl;
    cout<<endl;
    cout<<"bool"<<endl;
    bool b1,b2;
    b1=1;
    b2=0;
    cout<<"b1=1"<<" "<<"b2=0"<<" "<<"b1*b2"<<"="<<b1*b2<<endl; 
    cout<<endl;
    cout<<"long"<<endl;
    long c1,c2;
    c1=30000L;
    c2=20000L;
    cout<<"c1=30000"<<" "<<"c2=20000"<<" "<<"c1-c2"<<"="<<c1-c2<<endl;
    cout<<endl;
    cout<<"long long"<<endl;
    long double d1,d2;
    d1=1.414L;
    d2=1.322L;
    cout<<"d1=1.414"<<" "<<"d2=1.322"<<" "<<"d1+d2"<<"="<<d1+d2<<endl;
    cout<<endl;
    cout<<"short"<<endl;
    short v1,v2;
    v1=(short)-22333;
    v2=(short)23233;
    cout<<"v1=-22333"<<" "<<"v2=23233"<<" "<<"v1+v2"<<"="<<v1+v2<<endl;
    cout<<endl;
    cout<<"float"<<endl;
    float g1,g2;
    g1=3.14f;
    g2=1.17f;
    cout<<"g1=3.14"<<" "<<"g2=1.17"<<" "<<"g1*g2"<<"="<<g1*g2<<endl;

    return 0;
}

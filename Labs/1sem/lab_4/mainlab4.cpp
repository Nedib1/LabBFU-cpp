#include <iostream>

int main() {

    int a,b,c;

    std::cout << "Введите значения для первого задания :"<< " ";
    std::cin >> a >> b >> c;

    if ((a%b == 0) && (b>c)) {
        std::cout << "Результат первого задания :" << a/b+c << std::endl;
    } 
    
    else if ((a%b == 0) && (b<c)) {
        std::cout<< "Результат первого задания :" << a/b-c << std::endl;
    }
    else {
        std::cout << "Результат первого задания :" << " " << (a+b)*c << std::endl;
    }


    int n;
    std::cout << "(2 задание) Введите месяц :" << " ";
    std::cin >> n;
    switch(n) {
        case 1:
            std::cout << "Январь" << std::endl;
            break;
        case 2:
            std::cout << "Февраль" << std::endl;
            break;
        case 3:
            std::cout << "Март" << std::endl;
            break;
        case 4:
            std::cout << "Апрель" << std::endl;
            break;
        case 5:
            std::cout << "Май" << std::endl;
            break;
        case 6:
            std::cout << "Июнь" << std::endl;
            break;
        case 7:
            std::cout << "Июль" << std::endl;
            break;
        case 8:
            std::cout << "Август" << std::endl;
            break;
        case 9:
            std::cout << "Сентябрь" << std::endl;
            break;
        case 10:
            std::cout << "Октябрь" << std::endl;
            break;
        case 11:
            std::cout << "Ноябрь" << std::endl;
            break;
        case 12:
            std::cout << "Декабрь" << std::endl;
            break;
        default:
            std::cout << "Неверно введен месяц, Ошибка!(2 задание)" << std::endl;
            break;


    }


    int x;
    std::cout << "(3 задание) введите х (-1 или 1) :" << " ";
    std::cin >> x;

    if (x == -1) {
        std::cout << "Negative number" << std::endl;
    }
    else if (x == 1) {
        std::cout << "Positive number" << std::endl;
    }
    else {
        std::cout << "Неверное значение" << std::endl;
    }


    return 0;
}
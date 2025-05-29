#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class BigInt {
private:
    vector<int> digits; // цифры в обратном порядке

    // Вспомогательная функция для удаления нулей слева
    void trim() {
        while (digits.size() > 1 && digits.back() == 0)
            digits.pop_back();
    }

public:
    // 1. Конструктор по умолчанию (0)
    BigInt() {
        digits.push_back(0);
    }

    // 2. Конструктор из строки
    BigInt(const string& number) {
        for (int i = number.size() - 1; i >= 0; --i)
            digits.push_back(number[i] - '0');
        trim();
    }

    // 3. Конструктор копирования (дефолтный подойдёт)
    // 4. Деструктор (не нужен - всё управляется автоматически)

    // 5. Оператор +=
    BigInt& operator+=(const BigInt& other) {
        int carry = 0, i = 0;
        while (i < digits.size() || i < other.digits.size() || carry) {
            if (i == digits.size())
                digits.push_back(0);
            digits[i] += carry + (i < other.digits.size() ? other.digits[i] : 0);
            carry = digits[i] / 10;
            digits[i] %= 10;
            i++;
        }
        return *this;
    }

    // 6. Оператор +
    BigInt operator+(const BigInt& other) const {
        BigInt result = *this;
        result += other;
        return result;
    }

    // 7. Оператор *=
    BigInt& operator*=(const BigInt& other) {
        vector<int> result(digits.size() + other.digits.size(), 0);
        for (size_t i = 0; i < digits.size(); ++i)
            for (size_t j = 0; j < other.digits.size(); ++j)
                result[i + j] += digits[i] * other.digits[j];

        int carry = 0;
        for (size_t i = 0; i < result.size(); ++i) {
            result[i] += carry;
            carry = result[i] / 10;
            result[i] %= 10;
        }

        digits = result;
        trim();
        return *this;
    }

    // 8. Оператор *
    BigInt operator*(const BigInt& other) const {
        BigInt result = *this;
        result *= other;
        return result;
    }

    // 9. Операторы сравнения
    bool operator==(const BigInt& other) const {
        return digits == other.digits;
    }

    bool operator!=(const BigInt& other) const {
        return !(*this == other);
    }

    bool operator<(const BigInt& other) const {
        if (digits.size() != other.digits.size())
            return digits.size() < other.digits.size();
        for (int i = digits.size() - 1; i >= 0; --i)
            if (digits[i] != other.digits[i])
                return digits[i] < other.digits[i];
        return false;
    }

    bool operator>(const BigInt& other) const {
        return other < *this;
    }

    // 10. Поток вывода
    friend ostream& operator<<(ostream& out, const BigInt& number) {
        for (int i = number.digits.size() - 1; i >= 0; --i)
            out << number.digits[i];
        return out;
    }

    // 11. Поток ввода
    friend istream& operator>>(istream& in, BigInt& number) {
        string s;
        in >> s;
        number = BigInt(s);
        return in;
    }
};



 int main() {
    BigInt a("123456789123456789");
    BigInt b("987654321987654321");

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    BigInt sum = a + b;
    BigInt mul = a * b;

    cout << "a + b = " << sum << endl;
    cout << "a * b = " << mul << endl;

    if (a < b)
        cout << "a < b" << endl;
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class BigInt {
private:
    vector<int> digits;     // цифры в обратном порядке
    bool is_negative;       // true, если число отрицательное

    void trim() {
        while (digits.size() > 1 && digits.back() == 0)
            digits.pop_back();
        if (digits.size() == 1 && digits[0] == 0)
            is_negative = false; // -0 не существует
    }

    // Сравнение модулей
    bool abs_less(const BigInt& other) const {
        if (digits.size() != other.digits.size())
            return digits.size() < other.digits.size();
        for (int i = digits.size() - 1; i >= 0; --i)
            if (digits[i] != other.digits[i])
                return digits[i] < other.digits[i];
        return false;
    }

    // Вычитание по модулю (|a| >= |b|)
    BigInt abs_subtract(const BigInt& other) const {
        BigInt result;
        result.digits.clear();
        int carry = 0;
        for (size_t i = 0; i < digits.size(); ++i) {
            int sub = digits[i] - carry - (i < other.digits.size() ? other.digits[i] : 0);
            if (sub < 0) {
                sub += 10;
                carry = 1;
            } else carry = 0;
            result.digits.push_back(sub);
        }
        result.trim();
        return result;
    }

public:
    // Конструктор по умолчанию
    BigInt() : is_negative(false) {
        digits.push_back(0);
    }

    // Конструктор из строки
    BigInt(const string& number) {
        is_negative = number[0] == '-';
        int start = is_negative ? 1 : 0;
        for (int i = number.size() - 1; i >= start; --i)
            digits.push_back(number[i] - '0');
        trim();
    }

    // Оператор ввода
    friend istream& operator>>(istream& in, BigInt& num) {
        string s;
        in >> s;
        num = BigInt(s);
        return in;
    }

    // Оператор вывода
    friend ostream& operator<<(ostream& out, const BigInt& num) {
        if (num.is_negative) out << '-';
        for (int i = num.digits.size() - 1; i >= 0; --i)
            out << num.digits[i];
        return out;
    }

    // Сложение
    BigInt operator+(const BigInt& other) const {
        if (is_negative == other.is_negative) {
            BigInt result;
            result.is_negative = is_negative;
            result.digits.clear();

            int carry = 0;
            for (size_t i = 0; i < max(digits.size(), other.digits.size()) || carry; ++i) {
                int sum = carry;
                if (i < digits.size()) sum += digits[i];
                if (i < other.digits.size()) sum += other.digits[i];
                result.digits.push_back(sum % 10);
                carry = sum / 10;
            }

            result.trim();
            return result;
        } else {
            if (abs_less(other)) {
                BigInt res = other.abs_subtract(*this);
                res.is_negative = other.is_negative;
                return res;
            } else {
                BigInt res = abs_subtract(other);
                res.is_negative = is_negative;
                return res;
            }
        }
    }

    // Унарный минус
    BigInt operator-() const {
        BigInt result = *this;
        if (!(digits.size() == 1 && digits[0] == 0))
            result.is_negative = !is_negative;
        return result;
    }

    // Вычитание
    BigInt operator-(const BigInt& other) const {
        return *this + (-other);
    }

    // Умножение
    BigInt operator*(const BigInt& other) const {
        BigInt result;
        result.digits = vector<int>(digits.size() + other.digits.size(), 0);
        result.is_negative = is_negative != other.is_negative;

        for (size_t i = 0; i < digits.size(); ++i)
            for (size_t j = 0; j < other.digits.size(); ++j)
                result.digits[i + j] += digits[i] * other.digits[j];

        int carry = 0;
        for (size_t i = 0; i < result.digits.size(); ++i) {
            result.digits[i] += carry;
            carry = result.digits[i] / 10;
            result.digits[i] %= 10;
        }

        result.trim();
        return result;
    }

    // Операторы сравнения
    bool operator==(const BigInt& other) const {
        return is_negative == other.is_negative && digits == other.digits;
    }

    bool operator!=(const BigInt& other) const {
        return !(*this == other);
    }

    bool operator<(const BigInt& other) const {
        if (is_negative != other.is_negative)
            return is_negative;

        if (!is_negative) { // оба положительные
            if (digits.size() != other.digits.size())
                return digits.size() < other.digits.size();
            for (int i = digits.size() - 1; i >= 0; --i)
                if (digits[i] != other.digits[i])
                    return digits[i] < other.digits[i];
        } else { // оба отрицательные
            if (digits.size() != other.digits.size())
                return digits.size() > other.digits.size();
            for (int i = digits.size() - 1; i >= 0; --i)
                if (digits[i] != other.digits[i])
                    return digits[i] > other.digits[i];
        }
        return false;
    }

    bool operator>(const BigInt& other) const {
        return other < *this;
    }
};




int main() {
    BigInt a("-1000000000000000000000001");
    BigInt b("1000000000000000000000000");

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "a + b = " << (a + b) << endl;
    cout << "a - b = " << (a - b) << endl;
    cout << "a * b = " << (a * b) << endl;

    if (a < b) cout << "a < b" << endl;
    else cout << "a >= b" << endl;
}

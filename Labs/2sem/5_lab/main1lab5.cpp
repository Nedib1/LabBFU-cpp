#include <iostream>
#include <stdexcept>
using namespace std;

class MyVector {
private:
    int* data;
    size_t _size;
    size_t _capacity;

    void reallocate(size_t new_capacity) {
        int* new_data = new int[new_capacity];
        for (size_t i = 0; i < _size; ++i)
            new_data[i] = data[i];
        delete[] data;
        data = new_data;
        _capacity = new_capacity;
    }

public:
    // 1. Базовый конструктор
    MyVector() : data(nullptr), _size(0), _capacity(0) {}

    // 2. Конструктор копирования
    MyVector(const MyVector& other) : _size(other._size), _capacity(other._capacity) {
        data = new int[_capacity];
        for (size_t i = 0; i < _size; ++i)
            data[i] = other.data[i];
    }

    // 3. Оператор присваивания копированием
    MyVector& operator=(const MyVector& other) {
        if (this != &other) {
            delete[] data;
            _size = other._size;
            _capacity = other._capacity;
            data = new int[_capacity];
            for (size_t i = 0; i < _size; ++i)
                data[i] = other.data[i];
        }
        return *this;
    }

    // 4. Деструктор
    ~MyVector() {
        delete[] data;
    }

    // Методы

    void resize(size_t new_size) {
        if (new_size > _capacity)
            reserve(new_size);
        if (new_size > _size)
            for (size_t i = _size; i < new_size; ++i)
                data[i] = 0; // заполняем нулями
        _size = new_size;
    }

    void reserve(size_t new_capacity) {
        if (new_capacity > _capacity)
            reallocate(new_capacity);
    }

    void shrink_to_fit() {
        if (_capacity > _size)
            reallocate(_size);
    }

    int& front() {
        if (_size == 0) throw out_of_range("Vector is empty");
        return data[0];
    }

    int& back() {
        if (_size == 0) throw out_of_range("Vector is empty");
        return data[_size - 1];
    }

    size_t size() const {
        return _size;
    }

    bool empty() const {
        return _size == 0;
    }

    size_t capacity() const {
        return _capacity;
    }

    void push_back(int value) {
        if (_size == _capacity)
            reserve(_capacity == 0 ? 1 : _capacity * 2);
        data[_size++] = value;
    }

    void insert(size_t index, int value) {
        if (index > _size)
            throw out_of_range("Insert index out of range");

        if (_size == _capacity)
            reserve(_capacity == 0 ? 1 : _capacity * 2);

        for (size_t i = _size; i > index; --i)
            data[i] = data[i - 1];

        data[index] = value;
        ++_size;
    }

    void erase(size_t index) {
        if (index >= _size)
            throw out_of_range("Erase index out of range");

        for (size_t i = index; i < _size - 1; ++i)
            data[i] = data[i + 1];

        --_size;
    }

    int& operator[](size_t index) {
        if (index >= _size)
            throw out_of_range("Index out of range");
        return data[index];
    }

    const int& operator[](size_t index) const {
        if (index >= _size)
            throw out_of_range("Index out of range");
        return data[index];
    }
};



int main() {
    MyVector vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    cout << "vec[1] = " << vec[1] << endl;

    vec.insert(1, 15); // 10 15 20 30
    vec.erase(2);      // 10 15 30

    cout << "Size: " << vec.size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;

    for (size_t i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";
    cout << endl;

    cout << "Front: " << vec.front() << endl;
    cout << "Back: " << vec.back() << endl;

    vec.resize(5);
    cout << "After resize(5): ";
    for (size_t i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";
    cout << endl;

    vec.shrink_to_fit();
    cout << "Capacity after shrink_to_fit: " << vec.capacity() << endl;
}

#include <iostream>


// Структура узла двусвязного списка
struct Node {
    int info;
    Node* prev;
    Node* next;
};

// Функция для создания нового узла
Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->info = val;
    newNode->prev = newNode->next = nullptr;
    return newNode;
}

// Функция для вставки элемента в двусвязный циклический список
void append_elements(Node*& head, int val) {
    Node* newNode = createNode(val);
    if (!head) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
    }
}

// Функция для удаления чисел, кратных 15
void remove_numbers(Node * top)
{
    Node * p = top->next;
    while (p != top) {
        if (p->info % 15 == 0) {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            Node * temp = p;
            p = p->next;
            delete temp;
        }
        else {
            p = p->next;
        }
    }
}

// Функция проверки, является ли число простым
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

// Функция дублирования простых чисел
void duplicatePrimes(Node*& head) {
    if (!head) return;
    Node* p = head;
    do {
        if (isPrime(p->info)) {
            Node* newNode = createNode(p->info);
            newNode->next = p->next;
            newNode->prev = p;
            p->next->prev = newNode;
            p->next = newNode;
            p = newNode->next;
        } else {
            p = p->next;
        }
    } while (p != head);
}

// Функция сортировки по убыванию первой цифры
int firstDigit(int n) {
    while (n >= 10) n /= 10;
    return n;
}

void sortDescendingByFirstDigit(Node*& head) { //сортировка по убыванию
    if (!head) return;
    Node* i = head;
    do {
        Node* j = i->next;
        while (j != head) {
            if (firstDigit(i->info) < firstDigit(j->info)) {
                std::swap(i->info, j->info);
            }
            j = j->next;
        }
        i = i->next;
    } while (i != head);
}

// Функция вывода списка
void print_list(Node * top)
{
    Node * p = top->next;  
    while (p != top) {
        std::cout << p->info << " ";  
        p = p->next;  
    }
}

int main() {
    Node* head = nullptr;
    int n, val;
    std::cout << "Введите количество элементов: ";
    std::cin >> n;
    
    std::cout << "Введите последовательность: ";
    for (int i = 0; i < n; i++) {
        std::cin >> val;
        append_elements(head, val);
    }
    
    bool ascending = true;
    remove_numbers(head);
    duplicatePrimes(head);
    sortDescendingByFirstDigit(head);
    
    std::cout << "Результат: ";
    print_list(head);
    
    return 0;
}
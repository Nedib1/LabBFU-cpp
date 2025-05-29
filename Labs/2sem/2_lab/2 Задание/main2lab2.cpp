#include <iostream>
#include <vector>
using namespace std;

// Функция быстрой сортировки
void quickSort(vector<int>& arr, int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2]; // опорный элемент

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

int main() {
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "Отсортированный массив:\n";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

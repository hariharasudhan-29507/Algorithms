#include <iostream>

using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void printArray(int arr[], int n) {
    cout << "[";
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i + 1 < n) cout << ", ";
    }
    cout << "]";
}

int main() {
    cout << "enter number of elements:";
    int n;
    if (!(cin >> n)) return 0;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "enter array element:" << (i+1) << ":";
        cin >> arr[i];
    }

    cout << "Original array:" << '\n';
    printArray(arr, n);
    cout << '\n';

    quickSort(arr, 0, n - 1);

    cout << "Sorted array:" << '\n';
    printArray(arr, n);
    cout << '\n';

    delete[] arr;
    return 0;
}

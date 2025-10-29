#include <iostream>
using namespace std;

// 🧠 Partition logic: places pivot at correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot = last element
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); // move smaller element to left
        }
    }
    swap(arr[i + 1], arr[high]); // place pivot in correct spot
    return i + 1;
}

// 🔁 Recursive quicksort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // get pivot index
        quicksort(arr, low, pi - 1);        // sort left
        quicksort(arr, pi + 1, high);       // sort right
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

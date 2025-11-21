#include <iostream>
using namespace std;

void display(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void bubbleSort(int arr[], int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        cout << "Pass " << i + 1 << ": ";
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        display(arr, size);  // display array after each pass
    }
}
int main() {
    int arr[10], size;
    cout << "Enter size of array: ";
    cin >> size;
    cout << "Enter array elements:\n";
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    cout << "\n--- Bubble Sort Intermediate Passes ---\n";
    bubbleSort(arr, size);
    cout << "\nFinal Sorted Array: ";
    display(arr, size);
    return 0;
}



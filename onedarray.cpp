#include <iostream>
using namespace std;
void traverse(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int insert(int arr[], int n, int element, int position, int size) {
    if (n >= size) {
        cout << "Insertion failed: Array is full." << endl;
        return n;
    }
    if (position < 0 || position > n) {
        cout << "Insertion failed: Invalid position." << endl;
        return n;
    }
    for (int i = n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    n++;
    return n;
}
int deleteElement(int arr[], int n, int position) {
    if (position < 0 || position >= n) {
        cout << "Deletion failed: Invalid position." << endl;
        return n;
    }
    for (int i = position; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    return n;
}
int main() {
    const int SIZE = 10;
    int arr[SIZE] = {1, 2, 3, 4, 5};
    int n = 5;
    cout << "Initial array: ";
    traverse(arr, n);
    // Insert 10 at index 2
    n = insert(arr, n, 10, 2, SIZE);
    cout << "Array after insertion: ";
    traverse(arr, n);
    // Delete element at index 4
    n = deleteElement(arr, n, 4);
    cout << "Array after deletion: ";
    traverse(arr, n);
    return 0;
}

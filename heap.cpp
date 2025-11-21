#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i) {
    int largest = i;          // Assume current index is largest
    int left = 2 * i + 1;     // Left child index
    int right = 2 * i + 2;    // Right child index
    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;
    // If right child is larger than current largest
    if (right < n && arr[right] > arr[largest])
        largest = right;
    // If largest is not the root, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void buildMaxHeap(int arr[], int n) {
    // Start from last non-leaf node and heapify each
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}
void display(int arr[], int n) {
    cout << "Heap Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    buildMaxHeap(arr, n);
    display(arr, n);
    return 0;
}


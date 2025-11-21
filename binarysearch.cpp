#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;           // Key found
        else if (arr[mid] < key)
            low = mid + 1;        // Search right half
        else
            high = mid - 1;       // Search left half
    }
    return -1;                    // Key not found
}
int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91}; // Sorted array
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 23;   // Value to search (change as needed)
    int result = binarySearch(arr, n, key);
    if (result != -1)
        cout << "Element " << key << " found at index " << result << endl;
    else
        cout << "Element " << key << " not found in the array." << endl;
    return 0;
}

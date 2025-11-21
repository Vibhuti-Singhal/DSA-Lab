#include <iostream>
using namespace std;
int rowMajorAddress(int base, int elementSize, int row, int col, int totalCols) {
    return base + ((row * totalCols) + col) * elementSize;
}
int columnMajorAddress(int base, int elementSize, int row, int col, int totalRows) {
    return base + ((col * totalRows) + row) * elementSize;
}
int main() {
    int baseAddress = 1000;  // Hypothetical base address
    int elementSize = 4;     // Size of each element in bytes
    int rows = 3;
    int cols = 4;
    int i = 2;  // 3rd row (0-indexed)
    int j = 1;  // 2nd column (0-indexed)
    int rowAddr = rowMajorAddress(baseAddress, elementSize, i, j, cols);
    int colAddr = columnMajorAddress(baseAddress, elementSize, i, j, rows);
    cout << "Address of element A[" << i << "][" << j << "]:" << endl;
    cout << "Row-major order: " << rowAddr << endl;
    cout << "Column-major order: " << colAddr << endl;
    return 0;
}



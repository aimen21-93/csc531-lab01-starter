
#include "lab01.hpp"

bool insertAt(int a[], int& size, int cap, int pos, int x) {

    // Reject insertion if array is full or position is invalid
    if (size >= cap || pos < 0 || pos > size) {
        return false;
    }

    // Shift elements one position to the right
    for (int i = size; i > pos; i--) {
        a[i] = a[i - 1];
    }

    // Insert the new element
    a[pos] = x;

    // Increase logical size
    size++;

    return true;
}

bool deleteAt(int a[], int& size, int pos) {

    // Reject invalid deletion positions
    if (pos < 0 || pos >= size) {
        return false;
    }

    // Shift elements one position to the left
    for (int i = pos; i < size - 1; i++) {
        a[i] = a[i + 1];
    }

    // Decrease logical size
    size--;

    return true;
}

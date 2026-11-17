#include <iostream>
#include <utility> // For std::swap

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            std::swap(arr[i++], arr[j]);
        }
    }
    
    // Place pivot in its correct position
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortRecursive(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSortRecursive(arr, low, pi - 1);  // Sort elements before pivot
        quickSortRecursive(arr, pi + 1, high); // Sort elements after pivot
    }
}


void quickSortIterative(int arr[], int n) {
    if (n <= 1) return;

    int* lowStack = new int[n];
    int* highStack = new int[n];
    int top = -1;

    lowStack[++top] = 0;
    highStack[top] = n - 1;

    while (top >= 0) {
        int low = lowStack[top];
        int high = highStack[top--];

        int pi = partition(arr, low, high);

        // If there are elements on the left side of pivot, push range to stack
        if (pi - 1 > low) {
            lowStack[++top] = low;
            highStack[top] = pi - 1;
        }

        // If there are elements on the right side of pivot, push range to stack
        if (pi + 1 < high) {
            lowStack[++top] = pi + 1;
            highStack[top] = high;
        }
    }

    delete[] lowStack;
    delete[] highStack;
}

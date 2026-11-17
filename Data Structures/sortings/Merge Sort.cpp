#include <iostream>
#include <algorithm> // For std::min

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int* L = new int[n1];
    int* R = new int[n2];

    // Copy data to temporary vectors
    for (int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // Merge the temporary vectors back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Copy any remaining elements
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}


void mergeSortRecursive(int arr[], int left, int right) {
    if (left >= right) return; // Base case: 1 element or invalid range

    int mid = left + (right - left) / 2; // Prevents integer overflow

    mergeSortRecursive(arr, left, mid);      // Sort left half
    mergeSortRecursive(arr, mid + 1, right); // Sort right half
    merge(arr, left, mid, right);            // Merge sorted halves
}



void mergeSortIterative(int arr[], int n) {

    // currSize doubles on each pass: 1, 2, 4, 8, ...
    for (int currSize = 1; currSize < n; currSize *= 2) {
        
        // Pick starting point of different subarrays of current size
        for (int leftStart = 0; leftStart < n - 1; leftStart += 2 * currSize) {
            
            // Find ending point of left subarray and right subarray
            int mid = std::min(leftStart + currSize - 1, n - 1);
            int rightEnd = std::min(leftStart + 2 * currSize - 1, n - 1);

            // Only merge if there is a right subarray to merge with
            if (mid < rightEnd) {
                merge(arr, leftStart, mid, rightEnd);
            }
        }
    }
}

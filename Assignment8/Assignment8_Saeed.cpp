#include <iostream>
using namespace std;

// Function to merge two sorted subarrays into a single sorted array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays to hold the two subarrays
    int leftArr[n1], rightArr[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

    // Merge the temporary arrays back into the original array
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Recursive function to implement Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Calculate the middle index

        // Recursively sort the two halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to handle user input and display the sorted array
int main() {
    int n;

    // Input: size of the array
    cout << "Enter the size of the array (1 to 100): ";
    cin >> n;

    // Handle invalid input for size
    if (n < 1 || n > 100) {
        cout << "Invalid size. Please enter a number between 1 and 100." << endl;
        return 1;
    }

    int arr[n];

    // Input: elements of the array
    cout << "Enter " << n << " elements (positive or negative integers): " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sort the array using Merge Sort
    mergeSort(arr, 0, n - 1);

    // Output: display the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

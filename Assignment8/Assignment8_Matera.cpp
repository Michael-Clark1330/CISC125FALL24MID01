#include <iostream>
#include <limits> // For numeric_limits

using namespace std;

// Merge function to combine two sorted subarrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of left subarray
    int n2 = right - mid;    // Size of right subarray

    // Create temporary arrays
    int leftArr[n1], rightArr[n2];

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

    // Merge the temp arrays back into the original array
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

    // Copy remaining elements of leftArr, if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArr, if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Recursive mergeSort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort the two halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Updated inputArray function with better error handling
void inputArray(int arr[], int& size) {
    cout << "Enter the size of the array (1-100): ";
    while (true) {
        cin >> size;
        if (cin.fail() || size < 1 || size > 100) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Enter a valid size (1-100): ";
        } else {
            break;
        }
    }

    cout << "Enter " << size << " integers: ";
    for (int i = 0; i < size; i++) {
        while (true) {
            cin >> arr[i];
            if (cin.fail()) {
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "Invalid input. Enter an integer: ";
            } else {
                break;
            }
        }
    }
}

// Display function to print the sorted array
void displayArray(const int arr[], int size) {
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    int size;
    int arr[100];

    // Input the array
    inputArray(arr, size);

    // Perform Merge Sort
    mergeSort(arr, 0, size - 1);

    // Display the sorted array
    displayArray(arr, size);

    return 0;
}

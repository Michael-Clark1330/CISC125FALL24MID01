#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    const int n1 = mid - left + 1;
    const int n2 = right - mid;

    // Create temporary arrays for left and right
    int leftArr[50], rightArr[50];

    // Copy into temporary arrays
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];//adds from the left till it reaches the middle;
    }
        
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];//starts from the middle till it reaches the end
    }
       
    // Merge the arrays back into the original array
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr, if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr, if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Merge Sort function to divide the array into two halves
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Find the middle point

        // Recursively sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

void inputArray(int arr[], int& size) {
    cout << "---Array Sorter---" << endl;

    while (true) {
        cout << "Enter the size of the array: ";
        cin >> size;

        // Check for valid array size
        if (size < 1 || size > 100) {
            cout << "The array must be between 1 and 100." << endl;
            cout << "Try Again..." << endl;
        }
        else {

            cout << "Enter " << size << " numbers:" << endl;
            for (int i = 0; i < size; i++) {
                cin >> arr[i];
            }
            return;
        }

   }
}

// Function to display the sorted array
void displayArray(int arr[], int size) {
    cout << "SORTED ARRAY:  ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[100];
    int size;

    // Input the array from the user
    inputArray(arr, size);

    // Sort the array using Merge Sort
    mergeSort(arr, 0, size - 1);

    // Display the sorted array
    displayArray(arr, size);

    return 0;
}
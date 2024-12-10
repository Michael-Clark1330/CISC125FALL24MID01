#include <iostream>
using namespace std;

// Inputting function to merge two subarrays into single array.
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of left subarray
    int n2 = right - mid;    // Size of right subarray

    // Temporary arrays added.
    int leftArr[n1], rightArr[n2];

    // Data is copied to temp arrays.
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merging arrays.
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

    // Copy remaining elements of leftArr[].
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArr[].
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Recursive function added to implement mergeSort.
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function added to handle the input, sorting, and output functions.
void handleMergeSort() {
    int n;
    cout << "Enter the size of the array (1 to 100): ";
    cin >> n;

  
    if (n < 1 || n > 100) {
        cout << "Invalid size. Please enter a size between 1 and 100.\n";
        return;
    }

    int arr[n];
    cout << "Enter " << n << " integers (positive or negative): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // mergeSort performing in action.
    mergeSort(arr, 0, n - 1);

    // Display the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function for running.
int main() {
    handleMergeSort();
    return 0;
}

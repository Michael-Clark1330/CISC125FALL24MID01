#include <iostream>
using namespace std;


//---------------------------------------------------------------------------------
// Created function to merge subarrays. n1 for left, n2 for right
// Following this would be adding temporary arrays and implementing copied data in // their system

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; 
    int n2 = right - mid;    

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merging temporary arrays
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

    // Copy elements of left array
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy elements of right array
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Recursive Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
            
        merge(arr, left, mid, right);
    }
}

//---------------------------------------------------------------------------------
// Main Function prompting user input regarding array and displays output
int main() {
    int n;

    // Input array size
    cout << "Enter array size (1 to 100): ";
    cin >> n;

    if (n < 1 || n > 100) {
        cout << "Invalid input" << endl;
        return 1;
    }

    int arr[n];

    // Input 
    cout << "\n Enter " << n << " integers: \n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sort
    mergeSort(arr, 0, n - 1);

    // Output 
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
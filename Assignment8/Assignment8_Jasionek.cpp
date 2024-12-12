// MergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// global size parameter just for convenience
int size;

// make the array first
int* makeArray() {
    std::cout << "\n Enter the size of the desired array: ";
    std::cin >> size; 

    if ((not (size > 0)) or (size > 100)) {
        std::cout << "\n Invalid input (size <= 0 or size > 100).";
        return nullptr;
    }
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        int input;
        std::cout << "\n Enter the " << i << "-th element of the array: ";
        std::cin >> input;
        arr[i] = input;
    }
    return arr;
}

// this function displays the array
void displayArray(int* m_arr) {
    std::cout << "\n ";
    for (int i = 0; i < size; i++) {
        std::cout << m_arr[i] << " ";
    }
}

// merge sort appears recursive in nature, hence a recursive definition

// merge two sorted subarrays
void merge(int* arr, int left, int mid, int right) {
    // SPLIT ARRAY
    // calculate sizes of two subarrays to be merged
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // create temp arrays
    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

    // copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    // SORT ARRAY
    // merge the temporary arrays back into orginal array[left..right]
    int i = 0;      
    int j = 0;      
    int k = left;   

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


    // copy remaining elements of leftArr[]
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // copy remaining elements of rightArr[]
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    // delete temp arrays
    delete[] leftArr;
    delete[] rightArr;
}

// main merge sort function
void mergeSort(int* arr, int left, int right) {
    if (left >= right) {
        return; // base case: single element or invalid range
    }

    // find the middle point
    int mid = left + (right - left) / 2;

    // sort the first and second halves
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // merge the sorted halves
    merge(arr, left, mid, right);
}



int main()
{
    int* user_array = makeArray();
    std::cout << " \n Original array: ";
    displayArray(user_array);

    // perform merge sort (array, left, right
    mergeSort(user_array, 0, (size - 1));

    std::cout << "\n Sorted array: ";
    displayArray(user_array);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

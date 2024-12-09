#include <iostream>
using namespace std;

//merges the individual arrays together so that they are in order
void merge(int * array, int low, int mid, int high) {
    int lL = mid - low + 1;
    int lR = high - mid;
    int arrayL[lL], arrayR[lR];
    for (int i = 0; i < lL; i++) {
        arrayL[i] = array[low+i];
    }
    for (int i = 0; i < lR; i++) {
        arrayR[i] = array[mid+1+i];
    }
    int a = 0;
    int b = 0;
    int c = low;
    while (a < lL && b < lR) {
        if (arrayL[a] <= arrayR[b]) {
            array[c] = arrayL[a];
            a++;
        }
        else {
            array[c] = arrayR[b];
            b++;
        }
        c++;
    }
    while (a < lL) {
        array[c] = arrayL[a];
        c++;
        a++;
    }
    while (b < lR) {
        array[c] = arrayR[b];
        c++;
        b++;
    }
}

//sorts the array by way of merging
void mergeSort(int * array, int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}

//declarations
int size, number, go = 1;

int main () {
    //inputing the size of the array
    while (go == 1) {
        cout << "Enter the size of the array: ";
        cin >> size;
        if (size >= 1 && size <= 100) {
            go = 0;
        }
        else{
            cout << "Please enter a value between 1 and 100" << endl;
        }
    }
    int array[size];
   
    //inputting the array values
    for (int i = 0; i < size; i++) {
        while(cout << "Element #" << i+1 << ": ") {
            if(cin >> array[i]){ break; }
            else {
                cin.clear() ;
                cin.ignore() ;
                cout << "Please enter an integer...\n" ;
            }
        }   
    }
    
    //printing the array
    mergeSort(array, 0, size - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}

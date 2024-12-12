#include <iostream>
using namespace std;



//function to merge arrays
void merge(int array[], int left, int middle, int right)
{
  int sizeL = (middle - left + 1);
  int sizeR = (right - middle);
  
  int leftArray[sizeL];
  int rightArray[sizeR];
  

  for (int i = 0; i < sizeL; i++)
  {
    leftArray[i] = array[left + i];
  }
  
  for(int j = 0; j < sizeR; j++)
  {
    rightArray[j] = array[middle + 1 + j];
  }
  
  
  int i = 0;
  int j = 0;
  int n = left;
  
  while (i < sizeL && j < sizeR)
  {
    
    if (leftArray[i] <= rightArray[j])
    {
      array[n] = leftArray[i];
      i++;
    }
    
    else
    {
      array[n] = rightArray[j];
      j++;
    }
    
    n++;
    
  }
  
  
  while (i < sizeL)
  {
    array[n] = leftArray[i];
    i++;
    n++;
  }
  
  while (j < sizeR)
  {
    array[n] = rightArray[j];
    j++;
    n++;
  }
  
}


//recursive mergeSort function
void mergeSort(int array[], int left, int right)
{
  if (left < right)
  {
    int middle = left + (right - left)/2;
    mergeSort(array, left, middle);
    mergeSort(array, middle + 1, right);
    merge(array, left, middle, right);
  }
  
}

int main()
{
  int size;
  
  
  cout << "--- Array Sorter ---" << endl;
  cout << "Enter an array size from 1 to 100: " << endl;
  cin >> size;
  
  
  if (size < 1 || size > 100)
  {
    cout << "Must be between 1 and 100" << endl;
    return 0;
  }
  
  int array[size];
  
  cout << "Enter " << size << " integers: " << endl;
  for (int i = 0; i < size; i++)
  {
    cin >> array[i];
  }
  
  mergeSort(array, 0, size - 1);
  
  cout << "Sorted Array: ";
  for (int i = 0; i < size; i++)
  {
    cout << array[i] << " ";
  }
  
  return 0;
  
}
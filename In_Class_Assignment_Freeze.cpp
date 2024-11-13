#include <iostream>
using namespace std;
//Write a CPP program using recursion to find factorial of a given number.
int num;
int Fact(){
    if (num==0){
        return 1;
    }
    else{
        return num * Fact(num - 1);
    }        
};

int main(){
  int num;
    cout << "Enter a number: ";
    cin >> num;
    
    cout << "Factorial of " << num << " is: " << Fact(num) << endl;

    return 0;


};



/*2. Write a program to find the sum of array elements using recursion
Array input is given by the user
example : arr[10]=[1,2,3,4,5,6,7,8,9,10]
sum of that array should be 55.*/

#include <iostream>
using namespace std;

int largest( const int list[], int LowerIndex, int UpperIndex);

int main(){

    int Array[n] = {1,2,3,4,5,6,7,8,9,10};
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += Array[i];

    cout << "the Sum of the array is: " << sum << endl;
};

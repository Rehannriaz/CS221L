/*
Using the concept of the dynamic array, promt the user to enter the size of the array, promt the user to enter the elements of the array,
and then show the array elements in reverse order.
*/

#include <iostream>

using namespace std;

void printarr(int arr[], int size);
int &revArr(int *arr, int size);

int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int *parr = new int[size];

    cout << "Enter " << size << " numbers : ";
    for (int i = 0; i < size; i++)
        cin >> parr[i];

    cout << "before\n";
    printarr(parr, size);

    cout << "After\n";
    revArr(parr, size);
  
}

void printarr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int &revArr(int *arr, int size)
{
    int *tempArr = new int[size];
    int j = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        tempArr[j++] = arr[i];
    }

    printarr(tempArr,size);

}
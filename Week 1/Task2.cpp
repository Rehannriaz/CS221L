/**
 Sum all the elements of an integer array using the concept of pointer.

 */
#include <iostream>

using namespace std;

int main()
{
    int size;
    int sum = 0;

    cout << "Enter Size: ";
    cin >> size;

    int *arr = new int[size];

    cout << "Enter array of size " << size << endl;
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    for (int i = 0; i < size; i++)
        sum += *(arr + i);

    cout << "SUM = " << sum << endl;
}
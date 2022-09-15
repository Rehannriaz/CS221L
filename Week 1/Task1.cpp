/* 
Swap numbers using pointer calls
*/
#include <iostream>

using namespace std;

void Swapp(int *x1, int *y1);

int main()
{
    int x, y, temp;

    cout << "Enter x and y values: ";
    cin >> x >> y;
    cout << "BEFORE\nX = " << x << endl
         << "Y = " << y << endl;

    cout << "\nAfter\n";
    Swapp(&x, &y);
}

void Swapp(int *x1, int *y1)
{
    int *temp;
    temp = x1;
    x1 = y1;
    y1 = temp;

    cout << "x:" << *x1 << endl;
    cout << "y:" << *y1 << endl;
}
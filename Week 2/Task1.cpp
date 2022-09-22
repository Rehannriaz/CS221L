#include <iostream>
#include <string>
using namespace std;

struct member
{
    string name;
    int age;
    double salary;

    void print()
    {
        cout << "Name = " << name << endl;
        cout << "age = " << age << endl;
        cout << "salary = " << salary << endl;
    }

    void takeInput()
    {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter salary: ";
        cin >> salary;
    }
};

int main()
{
    member *a;
    int size;
    cout << "Enter the number of people:\n";
    cin >> size;

    a = new member[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Person " << i + 1 << endl;
        a[i].takeInput();
    }
    cout << "Total number of people = " << size << endl;
    for (int i = 0; i < size; i++)
    {
        a[i].print();
        cout << "---------------------------\n";
    }
}
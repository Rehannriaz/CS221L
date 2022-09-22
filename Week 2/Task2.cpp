#include <iostream>

using namespace std;

struct student
{
    int rollNo;
    string name;
    int age;
    string Address;

    void equal14()
    {
        if (age == 14)
            cout << "Name: " << name << endl;
    }
    void printEven()
    {
        if (rollNo % 2 == 0)
        {
            cout << "Name: " << name << endl;
        }
    }
    void details()
    {
        cout << "Roll number : " << rollNo << endl;
        cout << "name : " << name << endl;
        cout << "age : " << age << endl;
        cout << "Address : " << Address << endl;
    }

    void input()
    {
        cout << "Enter RollNo: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        bool check=false;
        cout << "Enter Address: ";
        getline(cin, Address);
        do
        {

            cout << "Enter age (between 11 and 14 ): ";
            cin >> age;
            if(age>=11 && age<=14)
                check=true;

        } while (check==false);
    }
};

int main()
{
    student *a;
    int size;
    do
    {
        cout << "enter Number of Students (More Than 10) : ";
        cin >> size;
    } while (size < 10);

    a = new student[size];

    for(int i=0;i<size;i++)
    {
        cout<<"Student No. "<<i+1<<": ";
        a[i].input();
    }
        cout<<"All students whos age = 14 \n\n";
    for(int i=0;i<size;i++)
        a[i].equal14();

        cout<<"All students whos roll number is even \n\n";
    for(int i=0;i<size;i++)
    {
        a[i].printEven();
    }

    int rollNoSearch;
    cout<<"\n\nEnter roll number to search";
    cin>>rollNoSearch;
    for(int i=0;i<size;i++)
    {
        if(a[i].rollNo==rollNoSearch)
           a[i].details();
        
    }

    
}
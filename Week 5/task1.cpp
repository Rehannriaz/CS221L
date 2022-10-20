#include <iostream>

using namespace std;

class queue
{

    struct Node
    {
        int val;
        Node *next;

        Node()
        {
            // val = 0;
            next = NULL;
        }
    };
    Node *listHeadPtr;
    int counter;

public:
    queue()
    {
        listHeadPtr = NULL;
        counter = 0;
    }

    void enqueue(int value)
    {
        Node *curr = new Node;
        curr->val = value;

        if (listHeadPtr == NULL)
        {
            counter++;
            listHeadPtr = curr;
            cout << "Node Queued\n";
            return;
        }
        Node *tempPtr = listHeadPtr;

        while (tempPtr->next != NULL)
            tempPtr = tempPtr->next;

        tempPtr->next = curr;
        counter++;

        cout << "Node Queued\n";
    }

    void print()
    {
        Node *tempPtr = listHeadPtr;

        while (tempPtr != NULL)
        {
            cout << tempPtr->val << " ";
            tempPtr = tempPtr->next;
        }
        cout << endl;
    }

    void addNodeAtHead(int value)
    {
        Node *curr = new Node;
        curr->val = value;

        curr->next = listHeadPtr;
        listHeadPtr = curr;
    }

    int dequeue()
    {
        int num;
        if (listHeadPtr != NULL)
        {
            num = listHeadPtr->val;
            listHeadPtr = listHeadPtr->next;
            counter--;
            cout << "dequeued\n";
            return num;
        }
        else
        {
            cout << "empty queue\n";
            return -404;
        }
    }

    void reverse(int num)
    {
        if(num>counter)
        {
            cout<<"error, not enough elements\n";
            num=counter;
            // return;
        }
        int size = counter*2;
        int *arr;
        arr = new int[size];
        for (int i = 0; i < num; i++)
            arr[i] = dequeue();
        for (int i = 0; i < num; i++)
            addNodeAtHead(arr[i]);
    }

   
};

int main()
{
    queue a;
    a.enqueue(1);
    a.enqueue(2);
    a.enqueue(3);
    a.enqueue(4);
    a.enqueue(5);
    a.enqueue(6);
    a.print();
    a.reverse(4);
    a.print();
}
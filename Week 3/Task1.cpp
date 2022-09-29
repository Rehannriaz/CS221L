#include <iostream>

using namespace std;

/**
 * @brief 
 *  A class List
 */
class List
{
    struct Node
    {
        int val;
        Node *next;
    };
    Node *ListHeadPtr;

public:
    List()
    {
        ListHeadPtr = NULL;
    }

/**
 * @brief adds a node at the head of the linked list
 * 
 * @param value 
 */
    void addNodeAtHead(int value)
    {
        Node *ptrNew = new Node;
        ptrNew->val = value;
        ptrNew->next = ListHeadPtr;
        ListHeadPtr = ptrNew;
    }
    void addNodeAtTail(int value)
    {
        Node *ptrNew = new Node;
        ptrNew->val = value;
        ptrNew->next = NULL;
        Node *ptrTemp = ListHeadPtr;
        if (ListHeadPtr == NULL)
        {
            ListHeadPtr = ptrNew;
            return;
        }
        while (ptrTemp->next != NULL)
            ptrTemp = ptrTemp->next;

        ptrTemp->next = ptrNew;
    }
/**
 * @brief prints the entire linked list
 * 
 */
    void print()
    {
        Node *ptrCurr = ListHeadPtr;
        while (ptrCurr != NULL)
        {
            cout << ptrCurr->val << " ";
            ptrCurr = ptrCurr->next;
        }
        cout << endl;
    }
/**
 * @brief reverses the first two pairs with each other and moving forward
 * 
 */
    void applyRev()
    {
        Node *ptrTemp, *ptrPrev;
        int temp;
        
        ptrTemp = ListHeadPtr;
        int counter = 0;
        while (ptrTemp->next != NULL)
        {
            counter++;
            ptrPrev = ptrTemp;
            ptrTemp = ptrTemp->next;
            if (counter % 2 != 0)
            {
                temp=ptrTemp->val;
                ptrTemp->val=ptrPrev->val;
                ptrPrev->val=temp;
            }
                // cout << ptrTemp->val << "->" << ptrPrev->val << "->";
        }
    }

};

/**
 * @brief int main
 * 
 * @return int 
 */
int main()
{
    List a;
    // a.addNodeAtHead(6);
    // a.addNodeAtHead(5);
    // a.addNodeAtHead(4);
    // a.addNodeAtHead(3);
    // a.addNodeAtHead(2);
    // a.addNodeAtHead(1);
    a.addNodeAtTail(10);
    a.addNodeAtTail(21);
    a.addNodeAtTail(23);
    a.addNodeAtTail(49);
    a.addNodeAtTail(522);
    a.addNodeAtTail(61);

    cout<<"\n BEFORE : \n";
    a.print();

    a.applyRev();
    cout<<"\n AFTER : \n";
    a.print();
}
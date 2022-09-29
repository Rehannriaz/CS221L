#include <iostream>

using namespace std;

/**
 * @brief
 *  A class List
 */
class List
{
    int counter;
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
        counter = 0;
    }

    /**
     * @brief adds a node at the head of the linked list
     *
     * @param value
     */
    void addNodeAtHead(int value)
    {
        counter++;
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
     * @brief Forms the cycle in a linked list
     *
     */
    void formCycle()
    {
        Node *ptrTemp = ListHeadPtr;

        while (ptrTemp->next != NULL)
            ptrTemp = ptrTemp->next;

        ptrTemp->next = ListHeadPtr;
    }

    /**
     * @brief Deletes the loop in the linked list
     *
     */
    void DeleteCycle()
    {
        Node *ptrTemp = ListHeadPtr;

        while (ptrTemp->next != ListHeadPtr)
            ptrTemp = ptrTemp->next;

        ptrTemp->next = NULL;
    }
    /**
     * @brief prints the entire linked list
     *
     */
    void print()
    {
        // if(CycleDetect)
        Node *ptrCurr = ListHeadPtr;
        while (ptrCurr != NULL)
        {
            cout << ptrCurr->val << " ";
            ptrCurr = ptrCurr->next;
        }
        cout << endl;
    }

    /**
     * @brief Detects if the cycle exist
     *
     * @return true
     * @return false
     */
    bool CycleDetect()
    {
        Node *ptrTemp = ListHeadPtr;

        while (1)
        {
            ptrTemp = ptrTemp->next;
            if (ptrTemp->next == ListHeadPtr)
                return true;
            if (ptrTemp->next == NULL)
                return false;
        }
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
                temp = ptrTemp->val;
                ptrTemp->val = ptrPrev->val;
                ptrPrev->val = temp;
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
    // a.addNodeAtHead(10);
    a.addNodeAtTail(522);
    a.addNodeAtTail(213);
    a.addNodeAtTail(2138);
    a.formCycle();
    a.DeleteCycle();
    // cout << "CYCLE : " << a.CycleDetect();
    if (a.CycleDetect())
    {
        cout << "Cycle Detected\n Enter any key to print infinite loop\n";
        system("pause");
        a.print();
        return 0;
    }
    a.print();
    return 0;
}

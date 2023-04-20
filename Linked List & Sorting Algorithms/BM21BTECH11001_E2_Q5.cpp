#include <bits/stdc++.h>
using namespace std;

// class for Node for linked list
class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    // constructor for class Node
    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }

    // default constructor for class node
    Node()
    {
        prev = NULL;
        next = NULL;
    }
};

// New class for linkedList which always has Node* head and Node* tail in it
class linkedList
{
public:
    Node *head;
    Node *tail;

    // constructor for linkedList class. It initializes head and tail node as NULL and further we can update it as per different functions.
    linkedList()
    {
        head = NULL;
        tail = NULL;
    }

    // function to delete last element of list
    // Time complexity:  O(1)
    // Space complexity:  O(1)
    void deleteAtEnd()
    {
        Node *temp = tail;
        tail->prev = tail;
        if (tail != NULL)
            tail->next = NULL;
        else
            head = NULL;
        delete (temp);
    }

    // function to delete first element of list
    // Time complexity:  O(1)
    // Space complexity:  O(1)
    void deleteAtFront()
    {
        Node *temp = head;
        head->next = head;
        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;
        delete (temp);
    }

    // function to delete element of given value from list
    // Time complexity:  O(n)
    // Space complexity:  O(1)
    void deleteValue(int value)
    {
        Node *curr = head;
        Node *Next = head->next;

        if (head->data == value)
        {
            head->next = head;
            if (head != NULL)
                head->prev = NULL;
            else
                tail = NULL;
            delete (curr);
        }
        else
        {
            while (Next->data != value && Next->next != NULL)
            {
                curr = curr->next;
                Next = Next->next;
            }
            if (Next->data == value)
            {
                if (Next->next != NULL)
                {
                    Next->next->prev = curr;
                    tail = curr;
                }
                curr->next = Next->next;
                delete (Next);
            }
        }
    }

    // function to delete data at given index of list wrt head node as index 0
    // Time complexity:  O(n)
    // Space complexity:  O(1)
    void deleteAtIndex(int index)
    {

        if (index == 0)
        {
            deleteAtFront();
            return;
        }

        Node *curr = head;
        Node *Next = head->next;
        int i = 0;
        while (i != index - 1)
        {
            curr = curr->next;
            Next = Next->next;
            i++;
        }
        Next->next->prev = curr;
        curr->next = Next->next;
        delete (Next);
    }

    // function to insert data at the beginning of list
    // Time complexity:  O(1)
    // Space complexity:  O(1)
    void insertAtFront(int value)
    {
        Node *New = new Node(value);
        if (head == NULL)
        {
            head = New;
            tail = New;
        }
        else
        {
            New->next = head;
            head->prev = New;
            head = New;
            head->prev = NULL;
        }
    }

    // function to insert data at any index of list assuming head index is 0
    // Time complexity:  O(n)
    // Space complexity:  O(1)
    void insertAtIndex(int index, int value)
    {

        if (index == 0)
        {
            insertAtFront(value);
            return;
        }

        Node *New = new Node(value);
        Node *ptr = head;
        int i = 0;
        while (i != index - 1)
        {
            ptr = ptr->next;
            i++;
        }
        New->next = ptr->next;
        New->next->prev = New;
        ptr->next = New;
        New->prev = ptr;
    }

    // function to insert data at end of list
    // Time complexity:  O(1)
    // Space complexity:  O(1)
    void insertAtEnd(int value)
    {
        Node *New = new Node(value);
        if (head == NULL)
        {
            head = New;
            tail = New;
        }
        else
        {
            tail->next = New;
            New->prev = tail;
            New->next = NULL;
            tail = New;
            return;
        }
    }

    // function to display/print list from head to tail
    // Time complexity:  O(n)
    // Space complexity:  O(1)
    void display()
    {
        Node *ptr = head;

        if (ptr == NULL)
        {
            cout << "Empty List" << endl;
        }
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    // function to find if given value is in the list or not
    // Time complexity:  O(n)
    // Space complexity:  O(1)
    Node *search(int value)
    {
        Node *ptr = head;

        if (ptr == NULL)
        {
            cout << "Empty List" << endl;
            return NULL;
        }

        else
        {
            while (ptr != NULL)
            {
                if (ptr->data == value)
                {
                    cout << "YES,'" << value << "' is in the list." << endl;
                    return ptr;
                }
                else
                {
                    ptr = ptr->next;
                }
            }
            cout << "NO,'" << value << "' is not in the list." << endl;
            return NULL;
        }
    }

    // function to reverse the DLL
    // Time complexity:  O(n)
    // Space complexity:  O(1)
    void reverseDLL()
    {
        if (head != NULL || tail != NULL)
        {
            Node *temp1 = head, *temp2 = tail;
            while (temp1 != temp2)
            {
                temp1->data += temp2->data;
                temp2->data = temp1->data - temp2->data;
                temp1->data -= temp2->data;
                temp1 = temp1->next;
                if (temp1 == temp2)
                    break;
                else
                    temp2 = temp2->prev;
            }
        }
        // else
        //     cout << "Empty List" << endl;
    }

    // function to know data of head node
    // Time complexity:  O(1)
    // Space complexity:  O(1)
    int HEAD()
    {
        if (head == NULL)
        {
            cout << "Empty List" << endl;
            return -1;
        }

        else
        {
            return head->data;
        }
    }

    // function to know data of tail node
    // Time complexity:  O(1)
    // Space complexity:  O(1)
    int TAIL()
    {
        if (tail == NULL)
        {
            cout << "Empty List" << endl;
            return -1;
        }

        else
        {
            return tail->data;
        }
    }

    // function to display/print list from tail to head
    // Time complexity:  O(n)
    // Space complexity:  O(1)
    void reverseDisplay()
    {
        Node *ptr = tail;

        if (ptr == NULL)
        {
            cout << "Empty List" << endl;
        }
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->prev;
        }
        cout << endl;
    }
};

int main()

{
    // dynamically allocated memory for my list in heap
    linkedList *list = new linkedList();

    // taking input
    int n;
    cout << "Enter total number of elements : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        list->insertAtEnd(x);
    }

    // reversing the DLL
    list->reverseDLL();

    // printing the required output
    list->display();

    // freeing the dynamically allocated memory
    delete (list);

    return 0;
}
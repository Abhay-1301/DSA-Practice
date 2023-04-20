#include <bits/stdc++.h>
using namespace std;

// class for Node for linked list
class Node
{
public:
    int data;
    Node *next;

    // constructor for class Node
    Node(int value)
    {
        data = value;
        next = NULL;
    }

    // default constructor for class node
    Node()
    {
        next = NULL;
    }
};

// New class for linkedList which always has Node* head in it
class linkedList
{
public:
    Node *head;

    // constructor for linkedList class. It initializes head node as NULL and further we can update it as per different functions.
    linkedList()
    {
        head = NULL;
    }

    Node *insertAtEnd(int value)
    {
        Node *New = new Node(value);
        if (head == NULL)
        {
            head = New;
            return head;
        }
        else
        {
            Node *ptr = head;
            while (ptr != NULL)
            {
                if (ptr->next == NULL)
                {
                    ptr->next = New;
                    return head;
                }

                else
                {
                    ptr = ptr->next;
                }
            }
        }
    }
};

// operator overloading compare for minHeap implementation
class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

// function to display/print list
void display(Node *head)
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

// Function to merge k sorted linked lists
Node *mergeKSortedLinkedLists(Node *arr[], int N)
{
    priority_queue<Node *, vector<Node *>, compare> minHeap;

    // Push the head nodes of all the k lists in 'minHeap'
    for (int i = 0; i < N; i++)
    {
        if (arr[i] != NULL)
        {
            minHeap.push(arr[i]);
        }
    }
    // when list is empty
    if (minHeap.empty())
    {
        return NULL;
    }

    Node *temp = new Node(0);
    Node *last = temp;

    // Loop till 'minHeap' is not empty
    while (!minHeap.empty())
    {
        // Get the top element of minHeap and add it to the resultant merged list
        Node *curr = minHeap.top();
        minHeap.pop();
        last->next = curr;
        last = last->next;

        // Check if there is a node next to the top node in the list of which top node is a member and Push it in minHeap
        if (curr->next != NULL)
        {
            minHeap.push(curr->next);
        }
    }

    return temp->next;
}

int main()
{
    // Number of linked lists
    int N;
    cout << "Enter total number of linked list you have: ";
    cin >> N;

    // Array storing heads of linked list
    Node *arr[N];

    // Copy paste this in terminal as input. (It is test case given in question)
    // 3
    // 1 4 5 -1
    // 1 3 4 -1
    // 2 6 -1

    for (int i = 0; i < N; i++)
    {
        linkedList *l = new linkedList();
        int x;
        cout << "Enter first element of linked list " << i + 1 << ": ";
        cin >> x;
        cout << endl;
        while (x != -1)
        {
            arr[i] = l->insertAtEnd(x);
            cout << "Enter -1 if you do not have more elements in this linked list. Enter next element of linked list " << i + 1 << ": ";
            cin >> x;
            cout << endl;
        }
    }

    // Merge the k sorted lists
    Node *head = mergeKSortedLinkedLists(arr, N);

    // Print the merged list
    cout << endl;
    display(head);

    return 0;
}

// Time Complexity: O(N * K * log K)
// Auxiliary Space: O(K)
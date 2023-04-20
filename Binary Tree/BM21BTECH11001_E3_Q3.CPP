#include <bits/stdc++.h>
using namespace std;

// class - Node for binary tree
class Node
{
public:
    Node *left;
    int data;
    Node *right;

    // Constructor for class Node
    Node(int data)
    {
        this->left = NULL;
        this->data = data;
        this->right = NULL;
    }

    // Default Constructor for class Node
    Node()
    {
        this->left = NULL;
        this->right = NULL;
    }
};

// Function for creation of binary tree
// Time Complexity : O(n) , Space Complexity: O(n)
Node *createBinaryTree(Node *root)
{
    cout << "Enter the data : " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
        return NULL;

    cout << "Enter the data to be inserted in left of " << data << endl;
    root->left = createBinaryTree(root->left);
    cout << "Enter the data to be inserted in right of " << data << endl;
    root->right = createBinaryTree(root->right);
    return root;
}

// function for DFS in binary tree
// Time Complexity :     O(n)            Space Complexity : O(n) {recursive stack size of function calls}
Node *DFS(Node *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    Node *ptrL = DFS(root->left, value);
    if (ptrL != NULL)
    {
        return ptrL;
    }
    if (root->data == value)
    {
        cout << "Found ";
        return root;
    }
    Node *ptrR = DFS(root->right, value);
    if (ptrR != NULL)
    {
        return ptrR;
    }
    if (ptrL == NULL && ptrR == NULL)
    {
        return NULL;
    }
}

// Level Order Traversal
// Time Complexity : O(n) , Space Complexity : O(n)
void levelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// zig-zag Traversal
// Time Complexity : O(n) , Space Complexity : O(n)
void zigZagTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    bool reverse = false;

    while (!q.empty())
    {
        int n = q.size();
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();
            int index;
            if (!reverse)
            {
                index = i;
            }

            else
            {
                index = n - i - 1;
            }

            v[index] = temp->data;

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        reverse = !reverse;
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
    }
    cout << endl;
    return;
}

// function for taking continuous input for DFS
void inputForDFS(Node *root)
{
    int data;
    cout << "Enter Data to search in tree. Enter '-1' to terminate program" << endl;
    cin >> data;
    while (data != -1)
    {
        Node *ptr = DFS(root, data);
        if (ptr == NULL)
        {
            cout << "Input Data " << data << " is NOT in the Tree." << endl;
        }
        else
        {
            cout << ptr->data << endl;
        }
        cout << "Enter Data to search in tree. Enter '-1' to terminate program" << endl;
        cin >> data;
    }
    return;
}

int main()
{
    Node *root = NULL;

    root = createBinaryTree(root);
    // 0 1 3 -1 -1 5 -1 -1 2 4 -1 -1 6 -1 -1

    cout << "Level Order Traversal" << endl;
    levelOrderTraversal(root);

    cout << "Zig-Zag Traversal" << endl;
    zigZagTraversal(root);
    
    inputForDFS(root);
    return 0;
}
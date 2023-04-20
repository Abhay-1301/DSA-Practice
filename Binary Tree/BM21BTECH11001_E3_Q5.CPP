#include <bits/stdc++.h>
#include <queue>
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

// Insertion in BST
// Time Complexity : O(h) , O(n)-if skewed tree , Space Complexity : O(h) - recursive call stack space
Node *insertInBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    else
    {
        if (data > root->data)
        {
            root->right = insertInBST(root->right, data);
        }
        else if (data < root->data)
        {
            root->left = insertInBST(root->left, data);
        }
        else if (data = root->data)
        {
            cout << "Already in BST. Can not Insert." << endl;
        }

        return root;
    }
}

// function to take input for insertion
void inputToInsert(Node *&root)
{
    int data;
    cout << "Enter the data to be inserted. Enter -1 to stop input. " << endl;
    cin >> data;
    while (data != -1)
    {
        root = insertInBST(root, data);
        cout << "Enter the data to be inserted. Enter -1 to stop input. " << endl;
        cin >> data;
    }
    return;
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

// function for Kth smallest element in binary search tree
// Time Complexity : O(h) , O(n)-if skewed tree , Space Complexity : O(h) - recursive call stack space
int Kth_smallest(Node *root, int &i, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    int left = Kth_smallest(root->left, i, k);
    if (left != -1)
    {
        return left;
    }
    i++;
    if (i == k)
    {
        return root->data;
    }
    return Kth_smallest(root->right, i, k);
}

// function for Kth largest element in search binary tree
// Time Complexity : O(h) , O(n)-if skewed tree , Space Complexity : O(h) - recursive call stack space
int Kth_largest(Node *root, int &j, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    int right = Kth_largest(root->right, j, k);
    if (right != -1)
    {
        return right;
    }
    j++;
    if (j == k)
    {
        return root->data;
    }
    return Kth_largest(root->left, j, k);
}

// function for finding LCA in binary search tree
// Time Complexity : O(h) , O(n)-if skewed tree , Space Complexity : O(h) - recursive call stack space
int LCAinBST(Node *root, int a, int b)
{
    if (root == NULL)
    {
        return -1;
    }
    else if (a < root->data && b < root->data)
    {
        LCAinBST(root->left, a, b);
    }
    else if (a > root->data && b > root->data)
    {
        LCAinBST(root->right, a, b);
    }
    else
        return root->data;
}

// function to get in order traversal of binary tree
// Time Complexity :     O(n)            Space Complexity : O(n) {recursive stack size of function calls}
void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int main()
{
    Node *root = NULL;
    // 45 21 34 65 89 12 97 2 6 1 65 22 11 77 44 22 99 -1

    inputToInsert(root);

    levelOrderTraversal(root);
    cout << endl;

    inOrder(root);
    cout << endl;

    int i = 0;
    int j = 0;

    int k = 3;

    cout << Kth_smallest(root, i, k) << endl;

    cout << Kth_largest(root, j, k) << endl;

    cout << LCAinBST(root, 34, 89) << endl;

    return 0;
}
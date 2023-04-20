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

// Function to find LCA in Binary Tree
// Time Complexity : O(n) , Space Complexity : O(n) - worst case
Node *LCA(Node *root, int a, int b)
{
    Node *ptr1 = NULL;
    Node *ptr2 = NULL;

    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == a || root->data == b)
    {
        return root;
    }
    ptr1 = LCA(root->left, a, b);
    ptr2 = LCA(root->right, a, b);
    if (ptr1 == NULL && ptr2 == NULL)
    {
        return NULL;
    }
    if (ptr1 != NULL && ptr2 == NULL)
    {
        return ptr1;
    }
    if (ptr1 == NULL && ptr2 != NULL)
    {
        return ptr2;
    }
    if (ptr1 != NULL && ptr2 != NULL)
    {
        return root;
    }
}

int main()
{
    Node *root = NULL;

    root = createBinaryTree(root);
    // 0 1 3 -1 -1 5 -1 -1 2 4 -1 -1 6 -1 -1

    cout << (LCA(root, 5, 6))->data << endl;

    return 0;
}
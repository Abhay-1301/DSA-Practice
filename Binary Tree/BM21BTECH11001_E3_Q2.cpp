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

// function to get pre order traversal of binary tree
// Time Complexity :     O(n)            Space Complexity : O(n) {recursive stack size of function calls}
void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// function to get post order traversal of binary tree
// Time Complexity :     O(n)            Space Complexity : O(n) {recursive stack size of function calls}
void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
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

    root = createBinaryTree(root);
    // 0 1 3 -1 -1 5 -1 -1 2 4 -1 -1 6 -1 -1 (copy paste this to form tree)

    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    return 0;
}
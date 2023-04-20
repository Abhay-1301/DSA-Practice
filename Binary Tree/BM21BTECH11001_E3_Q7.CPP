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

// function to return index of root-data in inOrder Array
// Time Complexity : O(n) , Space Complexity : O(1)
int indexOfRoot(int inOrderArray[], int rootData, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (inOrderArray[i] == rootData)
            return i;
    }
    return -1;
}

// function to create binary tree from given preOrder and inOrder traversal
// Time Complexity : O(n^2) , Space Complexity : O(n)
Node *createBinaryTreeFromPreAndIn(int inOrderArray[], int preOrderArray[], int &preOrderIndex, int inOrdFirstInd, int inOrdLastInd, int n)
{
    if (preOrderIndex >= n || inOrdFirstInd > inOrdLastInd)
    {
        return NULL;
    }
    int val = preOrderArray[preOrderIndex];
    preOrderIndex++;
    Node *New = new Node(val);
    int rootInd = indexOfRoot(inOrderArray, val, n);
    New->left = createBinaryTreeFromPreAndIn(inOrderArray, preOrderArray, preOrderIndex, inOrdFirstInd, rootInd - 1, n);
    New->right = createBinaryTreeFromPreAndIn(inOrderArray, preOrderArray, preOrderIndex, rootInd + 1, inOrdLastInd, n);
    return New;
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

int main()
{
    int inOrderArray[] = {5, 8, 10, 3, 14, 20, 22, 25};
    int preOrderArray[] = {20, 8, 5, 3, 10, 14, 22, 25};

    int n = sizeof(inOrderArray) / sizeof(inOrderArray[0]);

    int preOrderIndex = 0;

    Node *root = createBinaryTreeFromPreAndIn(inOrderArray, preOrderArray, preOrderIndex, 0, n - 1, n);

    inOrder(root);
    cout << endl;

    preOrder(root);
    cout << endl;

    postOrder(root);
    cout << endl;
    cout << endl;

    levelOrderTraversal(root);
    cout << endl;

    return 0;
}
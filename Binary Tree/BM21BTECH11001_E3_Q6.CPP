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

// function to get inOrder Predecessor of a node in binary search tree
// Time Complexity : O(h) , O(n)-if skewed tree , Space Complexity : O(1)
Node *inOrderPredecessor(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

// function to delete node of binary search tree
// Time Complexity : O(h) ; O(n)->if skewed tree         Space Complexity : O(h) - recursive call stack space
Node *deleteInBST(Node *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == value)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete (root);
            return NULL;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete (root);
            return temp;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete (root);
            return temp;
        }
        else if (root->left != NULL && root->right != NULL)
        {
            Node *inOrdPre = inOrderPredecessor(root);
            root->data = inOrdPre->data;
            root->left = deleteInBST(root->left, inOrdPre->data);
            return root;
        }
    }
    else if (root->data > value)
    {
        root->left = deleteInBST(root->left, value);
        return root;
    }
    else if (root->data < value)
    {
        root->right = deleteInBST(root->right, value);
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

// function to take input for deletion
void inputToDelete(Node *&root)
{
    int data;
    cout << "Enter the data to be deleted. Enter -1 to stop giving input. " << endl;
    cin >> data;
    while (data != -1)
    {
        root = deleteInBST(root, data);
        cout << "Enter the data to be deleted. Enter -1 to stop giving input. " << endl;
        cin >> data;
    }
    return;
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

    inputToDelete(root);
    levelOrderTraversal(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    return 0;
}
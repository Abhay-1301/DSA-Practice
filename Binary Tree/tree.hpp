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

// Function for diameter and height
// pair.first contain diameter. pair.second contain height
// Time Complexity : O(n) , Space Complexity : O(n)
pair<int, int> DiameterAndHeight(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = DiameterAndHeight(root->left);
    pair<int, int> right = DiameterAndHeight(root->right);

    pair<int, int> ans;
    ans.first = max(left.second + right.second + 1, max(left.first, right.first));
    ans.second = max(left.second, right.second) + 1;

    return ans;
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

// function to get height of binary tree
// Time Complexity :     O(n)            Space Complexity : O(n)
// int height(Node *root)
// {
//     if (root == NULL)
//         return 0;
//     int hLeft = height(root->left);
//     int hRight = height(root->right);
//     return (max(hLeft, hRight) + 1);
// }

// function to get diameter of binary tree
// Time Complexity :         O(n^2)        Space Complexity : O(n)
// int diameter(Node *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }
//     else
//     {
//         int lHeight = height(root->left);
//         int rHeight = height(root->right);
//         int lDiam = diameter(root->left);
//         int rDiam = diameter(root->right);
//         return max(lHeight + rHeight + 1, max(lDiam, rDiam));
//     }
// }
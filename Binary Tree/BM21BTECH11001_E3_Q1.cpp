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

int main()
{
    Node *root = NULL;

    root = createBinaryTree(root);

    // 0 1 3 -1 -1 5 -1 -1 2 4 -1 -1 6 -1 -1 (Copy paste this to make tree)
    levelOrderTraversal(root);

    cout << "Diameter is " << DiameterAndHeight(root).first << endl;
    cout << "Height is " << DiameterAndHeight(root).second << endl;

    return 0;
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
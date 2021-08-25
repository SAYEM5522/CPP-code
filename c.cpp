#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left, *right;
};

void printPreorder(node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

node *newNode(int data)
{
    node *newN = new node;
    newN->data = data;
    newN->left = newN->right = NULL;
    return newN;
}

void constructSubBST(node *root, int postorder[], int start, int end)
{
    if (start >= end)
        return;

    int i;
    for (i = start; i < end; ++i)
        if (postorder[i] > root->data)
            break;

    if (i > start)
    {
        root->left = newNode(postorder[i - 1]);
        constructSubBST(root->left, postorder, start, i - 1);
    }

    if (i >= start)
    {
        root->right = newNode(postorder[end - 1]);
        constructSubBST(root->right, postorder, i, end - 1);
    }
}

node *constructTree(int postorder[], int size)
{
    node *root = newNode(postorder[size - 1]);

    constructSubBST(root, postorder, 0, size - 1);

    return root;
}

int main()
{
    cout << "Enter the quantity of nodes: ";
    int n;
    cin >> n;
    int postorder[n];
    cout << "Enter the nodes: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> postorder[i];
    }

    int size = sizeof(postorder) / sizeof(postorder[0]);

    node *root = constructTree(postorder, size);

    cout << "Preorder traversal : " << endl;

    printPreorder(root);

    return 0;
}
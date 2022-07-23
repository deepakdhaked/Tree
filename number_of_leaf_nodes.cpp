#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *createNode(int val)
{
    node *ptr;
    ptr = (node *)malloc(sizeof(node *));

    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

void numberofLeafNodes(node *root, int &count)
{
    if (root == NULL)
    {
        return;
    }
    numberofLeafNodes(root->left, count);
    numberofLeafNodes(root->right, count);
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }
}

int numberofLeafNodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = numberofLeafNodes(root->left);
    int right = numberofLeafNodes(root->right);
    if (root->left == NULL && root->right == NULL)
    {
        return 1 + left + right;
    }
    return left + right;
}

int main()
{
    node *root = createNode(1);
    node *a = createNode(2);
    node *b = createNode(3);
    node *c = createNode(4);
    node *d = createNode(5);
    node *e = createNode(6);
    node *f = createNode(7);
    node *g = createNode(8);

    root->left = a;
    root->right = c;

    a->left = b;
    a->right = d;

    c->right = e;

    e->left = f;
    e->right = g;

    int count = 0;
    numberofLeafNodes(root, count);
    cout << count << '\n';

    int var = numberofLeafNodes(root);
    cout << var;
}

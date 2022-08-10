#include <iostream>
#include <limits.h>
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

node *fun(node *root, int n, int &k)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n)
    {
        return root;
    }

    node *leftAns = fun(root->left, n, k);
    node *rightAns = fun(root->right, n, k);

    if (leftAns != NULL && rightAns == NULL)
    {
        k--;
        if (k == 0)
        {
            return root;
        }
        return leftAns;
    }
    if (leftAns == NULL && rightAns != NULL)
    {
        k--;
        if (k == 0)
        {
            return root;
        }
        return rightAns;
    }
    return NULL;
}

int kthAncestor(node *root, int n, int k)
{
    node *ans = fun(root, n, k);
    if (ans == NULL || ans->data == n)
    {
        return -1;
    }

    return ans->data;
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
    node *h = createNode(9);

    root->left = a;
    root->right = c;

    a->left = b;
    a->right = d;

    c->right = e;
    c->left = h;

    e->left = f;
    e->right = g;

    int n = 7, k = 5;
    cout << kthAncestor(root, n, k);
}

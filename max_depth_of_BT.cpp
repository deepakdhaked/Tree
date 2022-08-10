#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int val)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

int maxDepthRecursive(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = maxDepthRecursive(root->left);
    int rh = maxDepthRecursive(root->right);

    return 1 + max(lh, rh);
}

int main()
{
    struct node *root = createNode(1);
    struct node *a = createNode(2);
    struct node *b = createNode(3);
    struct node *c = createNode(4);
    struct node *d = createNode(5);
    struct node *e = createNode(6);
    struct node *f = createNode(7);
    struct node *g = createNode(8);

    root->left = a;
    root->right = b;

    a->left = c;
    a->right = d;

    b->left = e;
    b->right = f;

    e->left = g;

    cout << "Max depth of the binary tree is : " << maxDepthRecursive(root);
}

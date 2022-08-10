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

bool isBalanced(struct node *root)
{
    if (root == NULL)
    {
        return true;
    }
    int lh = maxDepthRecursive(root->left);
    int rh = maxDepthRecursive(root->right);

    if (abs(rh - lh) > 1)
    {
        return false;
    }
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    if (!left || !right)
    {
        return false;
    }
    return true;
}

int isBalancedOptimized(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = isBalancedOptimized(root->left);
    int rh = isBalancedOptimized(root->right);
    if (abs(rh - lh) > 1)
    {
        return -1;
    }
    if (lh == -1 && rh == -1)
    {
        return -1;
    }
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
    struct node *h = createNode(9);

    root->left = a;
    root->right = b;

    b->left = c;
    b->right = d;

    a->left = e;
    a->right = f;

    e->left = g;

    g->left = h;

    bool result = isBalanced(root);
    if (result)
    {
        cout << "Tree is Balanced\n";
    }
    else
    {
        cout << "Tree is not Balanced\n";
    }

    int res = isBalancedOptimized(root);
    if (res == -1)
    {
        cout << "Tree is not Balanced\n";
    }
    else
    {
        cout << "Tree is Balanced\n";
    }
}

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

int fun(node *root, int &maxi)
{
    if (root == NULL)
    {
        return 0;
    }

    int ls = max(0, fun(root->left, maxi));
    int rs = max(0, fun(root->right, maxi));

    maxi = max(maxi, ls + rs + root->data);

    return root->data + max(ls, rs);
}
int maxPathSum(node *root)
{
    // Time complexity : O(N)
    // Space Complexity : O(Height of Tree) or O(N) in worst case.
    int maxi = INT_MIN;
    fun(root, maxi);
    return maxi;
}

int main()
{
    node *root = createNode(-1);
    node *a = createNode(-2);
    node *b = createNode(-3);
    node *c = createNode(-4);
    node *d = createNode(-5);
    node *e = createNode(6);
    node *f = createNode(-7);
    node *g = createNode(-8);

    root->left = a;
    root->right = c;

    a->left = b;
    a->right = d;

    c->right = e;

    e->left = f;
    e->right = g;

    cout << maxPathSum(root);
}

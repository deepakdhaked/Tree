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

pair<int, int> fun(node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> l = fun(root->left);
    pair<int, int> r = fun(root->right);

    pair<int, int> res;
    res.first = root->data + l.second + r.second;
    res.second = max(l.first, l.second) + max(r.first, r.second);
    return res;
}

int maxSum(node *root)
{
    pair<int, int> ans = fun(root);
    return max(ans.first, ans.second);
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
    cout << maxSum(root);
}

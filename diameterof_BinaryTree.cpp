#include <iostream>
#include <vector>
#include <queue>
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

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return 1 + max(lh, rh);
}

int diameter(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int ld = diameter(root->left);
    int rd = diameter(root->right);
    int h = height(root->left) + 1 + height(root->right);

    return max(ld, max(rd, h));
}

pair<int, int> diameterOptimized(node *root)
{
    if (root == NULL)
    {
        pair<int, int> x = make_pair(0, 0);
        return x;
    }

    pair<int, int> left = diameterOptimized(root->left);
    pair<int, int> right = diameterOptimized(root->right);

    int l = left.first;
    int r = right.first;
    int h = left.second + 1 + right.second;

    pair<int, int> ans;
    ans.first = max(l, max(r, h));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameterOptimized(struct node *root, int *var)
{
    int lh = 0, rh = 0;
    int ld = 0, rd = 0;

    if (root == NULL)
    {
        *var = 0;
        return 0;
    }

    ld = diameterOptimized(root->left, &lh);
    rd = diameterOptimized(root->right, &rh);
    *var = max(lh, rh) + 1;

    return max(lh + rh + 1, max(ld, rd));
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

    cout << height(root) << endl;
    cout << diameter(root) << endl;
    cout << diameterOptimized(root).first << endl;
    int height = 0;
    cout << diameterOptimized(root, &height);
}

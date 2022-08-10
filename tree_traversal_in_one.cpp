#include <iostream>
#include <stack>
#include <vector>
#include <utility>
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

void treeTraversalinOne(struct node *root)
{
    stack<pair<struct node *, int>> s;
    s.push({root, 1});
    vector<int> preorder, inorder, postorder;

    while (!s.empty())
    {
        auto n = s.top();
        s.pop();

        if (n.second == 1)
        {
            preorder.push_back(n.first->data);
            n.second++;
            s.push(n);
        }
        if (n.second == 2)
        {
            inorder.push_back(n.first->data)
        }
    }
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

    root->left = a;
    root->right = b;

    a->left = c;
    a->right = d;

    b->left = e;
    b->right = f;
}

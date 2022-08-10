#include <iostream>
#include <vector>
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

bool preorderCheck(node *t1, node *t2)
{
    if (t1 == NULL || t2 == NULL)
    {
        return (t1 == t2);
    }
    return (t1->data == t2->data && preorderCheck(t1->left, t2->left) && preorderCheck(t1->right, t2->right));
}

int main()
{
    // Tree 1 :
    node *t1 = createNode(1);
    node *a1 = createNode(2);
    node *b1 = createNode(3);
    node *c1 = createNode(4);
    node *d1 = createNode(5);
    node *e1 = createNode(6);
    node *f1 = createNode(7);
    node *g1 = createNode(8);

    t1->left = a1;
    t1->right = c1;

    a1->left = b1;
    a1->right = d1;

    c1->right = e1;

    e1->left = f1;
    e1->right = g1;

    // Tree 2
    node *t2 = createNode(1);
    node *a2 = createNode(2);
    node *b2 = createNode(3);
    node *c2 = createNode(4);
    node *d2 = createNode(5);
    node *e2 = createNode(6);
    node *f2 = createNode(7);
    node *g2 = createNode(8);

    t2->left = a2;
    t2->right = c2;

    a2->left = b2;
    a2->right = d2;

    c2->right = e2;

    e2->left = f2;
    e2->right = g2;

    if (preorderCheck(t1, t2))
    {
        cout << "Trees are Identical";
    }
    else
    {
        cout << "Trees are Different";
    }
}

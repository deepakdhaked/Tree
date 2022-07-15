#include <iostream>
#include <stack>
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

void preorderTraversal(struct node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty";
        return;
    }

    stack<struct node *> s;
    struct node *n = root;
    while (n != NULL || s.empty() == false)
    {
        while (n != NULL)
        {
            s.push(n);
            n = n->left;
        }
        n = s.top();
        s.pop();
        cout << n->data << ' ';
        n = n->right;
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

    preorderTraversal(root);
}

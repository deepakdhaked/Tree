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

// Time complexity : O(n) where n is number of nodes in a binary tree.
// Space complexity : O(2n) because of 2 stack use in it.
void postorderTraversal2Stack(struct node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty";
        return;
    }
    stack<struct node *> s1;
    stack<struct node *> s2;

    struct node *n;
    s1.push(root);
    while (!(s1.empty()))
    {
        n = s1.top();
        s1.pop();
        s2.push(n);

        if (n != NULL)
        {
            if (n->left != NULL)
            {
                s1.push(n->left);
            }
            if (n->right != NULL)
            {
                s1.push(n->right);
            }
        }
    }
    while (!s2.empty())
    {
        struct node *n = s2.top();
        s2.pop();
        cout << n->data << " ";
    }
}

void postorderTraversal1Stack(struct node *root)
{
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

    // postorderTraversal2Stack(root);
    postorderTraversal1Stack(root);
}

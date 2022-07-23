#include <iostream>
#include <queue>
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

vector<int> zigZag(node *root)
{
    vector<int> result;
    if (root == NULL)
    {
        return result;
    }

    queue<node *> q;
    q.push(root);
    bool lefttorigt = true;
    while (q.empty() == false)
    {
        int size = q.size();
        vector<int> v(size);

        for (int i = 0; i < size; i++)
        {
            node *curr = q.front();
            q.pop();

            int index = lefttorigt ? i : size - 1 - i;
            v[index] = curr->data;

            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        lefttorigt = !lefttorigt;

        for (auto i : v)
        {
            result.push_back(i);
        }
    }
    return result;
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

    vector<int> v = zigZag(root);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
    }
}

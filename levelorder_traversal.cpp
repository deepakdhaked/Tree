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

vector<int> levelorder(node *root)
{
    vector<int> v;
    if (root == NULL)
    {
        return v;
    }

    queue<node *> q;
    q.push(root);

    while (q.empty() == false)
    {
        node *curr = q.front();
        q.pop();

        if (curr->left)
        {
            q.push(curr->left);
        }
        if (curr->right)
        {
            q.push(curr->right);
        }
        v.push_back(curr->data);
    }
    return v;
}

vector<vector<int>> levelorder2(node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }

    queue<node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++)
        {
            node *curr = q.front();
            q.pop();
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
            level.push_back(curr->data);
        }
        ans.push_back(level);
    }
    return ans;
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

    vector<int> v = levelorder(root);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    cout << '\n';
    vector<vector<int>> x = levelorder2(root);
    for (int i = 0; i < x.size(); i++)
    {
        cout << "Level " << i << " : ";
        for (int j = 0; j < x[i].size(); j++)
        {
            cout << x[i][j] << ' ';
        }
        cout << '\n';
    }
}

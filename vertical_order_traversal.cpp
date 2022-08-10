#include <iostream>
#include <map>
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
vector<int> vertical(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    map<int, map<int, vector<int>>> m;
    queue<pair<node *, pair<int, int>>> q;

    q.push(make_pair(root, make_pair(0, 0)));
    while (q.empty() == false)
    {
        pair<node *, pair<int, int>> temp;

        temp = q.front();
        q.pop();
        node *curr = temp.first;
        int horizontal = temp.second.first;
        int level = temp.second.second;

        m[horizontal][level].push_back(curr->data);

        if (curr->left)
        {
            q.push(make_pair(curr->left, make_pair(horizontal - 1, level + 1)));
        }
        if (curr->right)
        {
            q.push(make_pair(curr->right, make_pair(horizontal + 1, level + 1)));
        }
    }

    for (auto i : m)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
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

    vector<int> v = vertical(root);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
    }
}

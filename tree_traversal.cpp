#include <iostream>
#include <vector>
#include <queue>
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
    if (root != NULL)
    {
        cout << root->data << ' ';
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void inorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        cout << root->data << ' ';
        inorderTraversal(root->right);
    }
}

void postorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << ' ';
    }
}

vector<vector<int>> leveorderTraversal(struct node *root)
{
    vector<vector<int>> v;
    if (root == NULL)
    {
        return v;
    }
    queue<struct node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            struct node *n = q.front();
            q.pop();
            if (n->left != NULL)
            {
                q.push(n->left);
            }
            if (n->right != NULL)
            {
                q.push(n->right);
            }
            level.push_back(n->data);
        }
        v.push_back(level);
    }
    return v;
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

    cout << "Inorder : ";
    inorderTraversal(root);

    cout << "\nPreorder : ";
    preorderTraversal(root);

    cout << "\nPostorder : ";
    postorderTraversal(root);

    cout << "\nLevelorder : \n";
    vector<vector<int>> v = leveorderTraversal(root);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
}

#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *createNode(int val)
{
    node *ptr = (node *)malloc(sizeof(node *));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}
void findel(vector<int> v, map<int, int> &m, int key)
{
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        m[v[i]] = i;
    }
}

node *fun(vector<int> preorder, vector<int> inorder, int &preindex, int inindxstart, int inindxend, map<int, int> m, int n)
{
    if (preindex > n || inindxstart > inindxend)
    {
        return NULL;
    }

    int element = preorder[preindex++];
    node *root = createNode(element);
    int position = m[element];

    root->left = fun(preorder, inorder, preindex, inindxstart, position - 1,m, n);
    root->right = fun(preorder, inorder, preindex, position + 1, inindxend,m, n);

    return root;
}

node *buildTree(vector<int> preorder, vector<int> inorder, int n)
{
    int preindex = 0;
    map<int, int> m;
    findel(inorder, m, n);
    node *ans = fun(preorder, inorder, preindex, 0, n - 1,m, n);
    return ans;
}

void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << ' ';
}

int main()
{
    vector<int> inorder = {3, 1, 4, 0, 5, 2};
    vector<int> preorder = {0, 1, 3, 4, 2, 5};
    int n = preorder.size();

    node *root = buildTree(preorder, inorder, n);
    postorder(root);
}

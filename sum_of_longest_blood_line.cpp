#include <iostream>
#include <limits.h>
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


void fun(node *root,int sum,int&maxSum,int len,int&maxLen){
    if (root==NULL)
    {
        if (len>maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if (len==maxLen)
        {
            maxSum = max(sum, maxSum);
        }
        return;
    }

    sum = sum + root->data;
    fun(root->left, sum, maxSum, len + 1, maxLen);
    fun(root->right, sum, maxSum, len + 1, maxLen);
}

int sum(node* root){
    // Time Complexity : O(N)
    // Space Complexity : O(heigt) -0> O(N)
    int sum=0, maxSum=INT_MIN, len=0, maxLen=0;
    fun(root, sum, maxSum, len, maxLen);
    return maxSum;
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
    node *h = createNode(9);

    root->left = a;
    root->right = c;

    a->left = b;
    a->right = d;

    c->right = e;
    c->left = h;

    e->left = f;
    e->right = g;

    int n = 7, k = 5;
    cout << sum(root);
}

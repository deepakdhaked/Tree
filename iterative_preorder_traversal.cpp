#include <iostream>
#include <vector>
#include <stack>
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

vector<int> preorder(node *root)
{
    // Time Complexity : O(N)
    // Auxiliary Space : O(H), where H is the height of the tree.
    if (root == NULL)
    {
        vector<int> v;
        return v;
    }
    stack<node *> s;
    s.push(root);
    vector<int> v;
    while (s.empty() == false)
    {
        node *cur = s.top();
        s.pop();

        v.push_back(cur->data);

        if (cur->right)
        {
            s.push(cur->right);
        }
        if (cur->left)
        {
            s.push(cur->left);
        }
    }
    return v;
}

/* Another Solution: In the previous solution we can see that the left child is popped as soon as it is pushed to the stack, therefore it is not required to push it into the stack.

The idea is to start traversing the tree from the root node, and keep printing the left child while exists and simultaneously, push the right child of every node in an auxiliary stack.
Once we reach a null node, pop a right child from the auxiliary stack and repeat the process while the auxiliary stack is not-empty.

This is a micro-optimization over the previous approach, both the solutions use asymptotically similar auxiliary space.

Below is the implementation of the above approach: */

vector<int> preorderMicroOptimized(node *root)
{
    // Time Complexity: O(N)
    // Auxiliary Space : O(H), where H is the height of the tree.

    if (root == NULL)
    {
        vector<int> v;
        return v;
    }
    vector<int> v;
    stack<node *> st;

    // start from root node (set current node to root node)
    node *curr = root;

    // run till stack is not empty or current is
    // not NULL
    while (!st.empty() || curr != NULL)
    {
        // Print left children while exist
        // and keep pushing right into the
        // stack.
        while (curr != NULL)
        {
            v.push_back(curr->data);
            if (curr->right)
                st.push(curr->right);

            curr = curr->left;
        }

        // We reach when curr is NULL, so We
        // take out a right child from stack
        if (st.empty() == false)
        {
            curr = st.top();
            st.pop();
        }
    }
    return v;
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

    vector<int> v = preorder(root);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    cout << '\n';
    vector<int> x = preorderMicroOptimized(root);
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i] << ' ';
    }
}

#include <iostream>
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

int maxLevelSum(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int ans = root->data;
    queue<struct node *> q;
    q.push(root);

    while (q.empty() == false)
    {
        int count = q.size();

        int sum = 0;
        while (count--)
        {
            struct node *temp = q.front();
            q.pop();

            sum = sum + temp->data;

            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
        ans = max(sum, ans);
    }
    return ans;
}

int main()
{

    node *root = createNode(4);
    node *a = createNode(2);
    node *b = createNode(-5);
    node *c = createNode(-1);
    node *d = createNode(3);
    node *e = createNode(-2);
    node *f = createNode(6);

    root->left = a;
    root->right = b;

    a->left = c;
    a->right = d;

    b->left = e;
    b->right = f;

    int ans = maxLevelSum(root);

    cout << "Max Level Sum is : " << ans;
}

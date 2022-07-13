#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int val){
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}


int main(){
    struct node *root = createNode(1);
    struct node *a = createNode(2);
    struct node *b = createNode(3);
    struct node *c = createNode(4);
    struct node *d = createNode(5);

    root->left = a;
    root->right = b;

    a->left = c;
    a->right = d;
}
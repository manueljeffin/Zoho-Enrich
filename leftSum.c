//
//  hex.c


#include <stdio.h>
#include<stdlib.h>

int sum=0;//global value

struct Node
{
    int value;
    struct Node* left,*right;
};

struct Node* newNode(int x)
{
    struct Node* node = (struct Node *)malloc(sizeof(struct Node));
    node->value = x;
    node->left = NULL;
    node->right=NULL;
    return node;
}

int isLeaf(struct Node* head)
{
    if(head!=NULL && head->left == NULL && head->right == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void helper(struct Node* root)
{
    
    if(root == NULL)
    {
        return;
    }
    if(isLeaf(root->left))//most important line,without going to the leaf itself, we stand a node above and check
    {
        sum = sum + root->left->value;
    }
    helper(root->left);
    helper(root->right);
}

int leftSum(struct Node *root)
{
    helper(root);
    return sum;
}

int main()
{
    struct Node *root=NULL;
    root = newNode(10);
    root->left = newNode(1);
    root->right = newNode(10);
    
    root->left->right = newNode(4);
    root->left->left = newNode(3);
    
    root->right->left = newNode(15);
    printf("The sum is %d",leftSum(root));
    
}

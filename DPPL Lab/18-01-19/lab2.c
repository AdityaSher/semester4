//Q1 Create a binary search tree and create its in order traversal
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};

typedef struct node NODE;

NODE* create_bst(NODE *root,int x)
{
    if(root==NULL)
    {
        NODE* root=(NODE*)malloc(sizeof(NODE));
        root->data=x;
        root->left=NULL;
        root->right=NULL;

        return root;
    }
    else if(item>root->data)
    {
        root=create_bst(root->right,x)
    }
    else if(item<root->data)
    {
        root=create_bst(root->left,x)
    }
    else if(item=root->data)
    {
        printf("\n Duplicate item not allowed in bst");
    }
    else
    {
        printf("\nInput data is invalid, please note that it must be a number only!");
    }
    return root;
} //end of create_bst

void inorder(NODE *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}


void main()
{
    NODE* root;
    
    int x;
    int choice=1;
    
    printf("Press 1 to add new node, press 0 to stop ");
    scanf("%d",&choice);

    while(choice!=0)
    {
        printf("Enter value that must be added to the tree ");
        scanf("%d",&x);
        root=create_bst(root,x);
        printf("Press 1 to add new node, press 0 to stop ");
        scanf("%d",&x);
        
    }
    
}
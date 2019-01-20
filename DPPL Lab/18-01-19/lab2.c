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
    else if(x>root->data)
    {
        root=create_bst(root->right,x);
    }
    else if(x<root->data)
    {
        root=create_bst(root->left,x);
    }
    else if(x=root->data)
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

void preorder(NODE *root)
{
    if(root!=NULL)
    {
        printf("%d",root->data);
        preorder(root->left);
        prerder(root->right);
    }
}

void postorder(NODE *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ->",root->data);
    }
}

int exactly_identical(NODE *T1, NODE *T2)
{
    NODE* t1;
    NODE* t2;
    if (t1==NULL && t2==NULL) 
    {
        return 1;
    }
    else if(t1!=NULL && t2!=NULL) 
    {
        return
        (t1->data==t2->data && 
        exactly_identical(t1->left,t2->left) && 
        exactly_identical(t1->right,t2->right) );

    }
    return 0;   
}

int structurally_identical(NODE *T1, NODE *T2)
{
    NODE* t1;
    NODE* t2;
    if (t1==NULL && t2==NULL) 
    {
        return 1;
    }
    else if(t1!=NULL && t2==NULL || t1==NULL && t2!=NULL)
    else 
    {
        structurally_identical(t1->left,t2->left);
        structurally_identical(t1->right,t2->right);

    }
    return 0;   
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
    
    inorder(root);
    preorder(root);
    postorder(root);
}
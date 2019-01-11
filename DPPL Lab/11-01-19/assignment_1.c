#include<stdio.h>
#include<stdlib.h>

/*
STEP 1: Create basic node of a linked list.

 The below code segment is used to create a structure which will contain variables data and a pointer to the same type of node.
*/
struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE; 

NODE* create_set()
{
    NODE* head=NULL;
    
    printf("Your set has been initialized");

    return head;
}

int build(int number_of_elements,int set_elements[],NODE* head)  //Note to self: brackets needed in declaration of function which accepts the array.
{
    NODE* current=NULL;
    
    current=head;

    
    for(int i = 0; i < number_of_elements; i++)
    {   
        NODE* temp=(NODE*) malloc(sizeof(NODE));
        temp->data=set_elements[i];
        temp->next=NULL;
        current->next=temp;
        current=temp;
    }

    printf("\n The set has been created, use enumerate utility to output the set");
    
}

int enumerate(NODE* head)
{
    NODE* current;
    current=head;
    if(head->next==NULL)
    {
        printf("\nThe set is empty please add some elements to it to see the output.");
    }
    else
    {
        while(head->next!=NULL)
        {
            printf("\nThe set is as below\n");
            printf("{ ");
            printf("%d, ",current->data);
            printf(" }");
        }    
    }
    
    

}


int add_element(NODE* head, int element)
{
    NODE* current=NULL;
    

    if(head->next==NULL)
    {
        current=head;
        NODE* temp= (NODE*)malloc(sizeof(NODE));
        temp->data=element;
        temp->next=NULL;
        current=head=temp;
    
    }
    
    else
    {
        NODE* temp= (NODE*)malloc(sizeof(NODE));
        temp->data=element;
        temp->next=NULL;
        current->next=temp;
        current=temp;
    }
    
} //end of add element code


int print_set()
{

}

int main()
{   
    NODE* head=create_set();

    printf("\nEnter number of elements you want to add to the set");
    int number_of_elements;
    scanf("%d",&number_of_elements);
    int set_elements[number_of_elements];
    
    
    for(int i = 0; i < number_of_elements; i++)
    {
        printf("\nEnter element number %d",i+1);
        scanf("%d",&set_elements[i]);
    }

    build(number_of_elements,set_elements,head); //Note to self: no brackets needed while passing array to function.
    

}
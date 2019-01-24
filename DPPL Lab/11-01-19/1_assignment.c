//remember to set head and temp as null once you complete the program

#include <stdio.h>
#include <stdlib.h>

/*
STEP 1: Create basic node of a linked list.
 The below code segment is used to create a structure which will contain variables data and a pointer to the same type of node.
*/
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;

NODE *create_set()
{
    NODE *head = NULL;

    printf("Your set has been initialized");

    return head;
}

int is_element_of(NODE *head, int x)
{
    NODE *travel;
    travel = head;
    
    while (travel!= NULL)
    {
        if (travel->data == x)
        {    
            return 1;
        }
        travel = travel->next;
    }
    return 0;
}

int is_empty(NODE *head)
{
    if (head == NULL)
    {
        return 1;
    }
    return 0;
}

int cardinality(NODE *head) //node->data zero indicates no value
{
    int count=0;
    NODE *travel;
    travel = head;
    while (travel!= NULL)
    {
        if(travel->data!=0)
        {
            count++;
        }
        
        travel = travel->next;
    }
    return count;
}

void enumerate(NODE *head) //incorrect code must be fixed
{
    
    NODE *current;
    current = head;
    if (head == NULL)
    {
        printf("\nThe set is empty please add some elements to it to see the output.");
    }
    else
    {
        
        printf("\nThe set is as below\n");
        printf("{ ");
        while(current->next!=NULL)
        {
            printf("%d", current->data);
            printf(", ");
            current=current->next;
            
        }
        printf("%d ", current->data);
        printf(" }");
        }
    
}

NODE *add_element(NODE *head, int element);

    //Note to self: brackets needed in declaration of function which accepts the array.
NODE *build(int number_of_elements, int set_elements[])
{
    NODE *current = NULL;

    for(int i=0;i<number_of_elements;i++)
    {
        current=add_element(current,set_elements[i]);
    }
    printf("\n The set has been created, use enumerate utility to output the set");

    return current;
}

NODE* add_element(NODE *head, int element)
{
    NODE *current;
    current = head;
    NODE *temp = (NODE *)malloc(sizeof(NODE));

    temp->data = element;

    temp->next = NULL;

    if(!is_element_of(head,element))
    {
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = temp;
        }
    }
    else{
        printf("\nElement already exists in set.");
    }
    
return head;
} //end of add element code


NODE* create()
{
    NODE *head = NULL;
    head->next = NULL;
    return head;
}

void remove_element(NODE *head, int x)
{   /*
    int is_present = is_element_of(head, x);
    if (is_present == 0)
    {
        printf("/nThe element %d is not present in the set", x);
    }
    else if(is_present==1)
    {
        NODE *current = head;
        NODE* previous= NULL;
        NODE* temp= NULL;
        while (current->data!=x)
        {
            previous=current;
            current = current->next;
        }

        previous=previous->next->next;
        free(current);
    }
    */
}

NODE* copy(NODE* old);//copy function must be before find_union

NODE* find_union(NODE *S, NODE *T) //function name union resulted in error, why?
{
    NODE* temp=S;
    NODE* head=NULL;

    while(temp!=NULL)
    {
        NODE *newnode = (NODE *)malloc(sizeof(NODE));
        newnode->data = temp->data;
        newnode->next = NULL;

        if(head==NULL)
            head=newnode;
        else{
            newnode->next=head;
            head=newnode;
        } 
        temp=temp->next;   
    }

    temp=T;
    while(temp!=NULL)
    {
        head=add_element(head,temp->data);
        temp=temp->next;
    }
    
return head;
}



NODE* find_difference(NODE *S, NODE *T)
{
    //NODE *difference_set=NULL;
    NODE *current;
    NODE *first=S;

    current =NULL;

    while (first!= NULL)
    {
        if (!is_element_of(T, first->data))
        {
            NODE *temp = (NODE *)malloc(sizeof(NODE));
            temp->data = first->data;
            temp->next = NULL;
            if(current==NULL)
                current=temp;
            else{
                temp->next=current;
                current=temp;
            }
        }

        first = first->next;
    }
    return current;
}

NODE *find_intersection(NODE *S, NODE *T)
{
    NODE* diff = find_difference(S, T);
    diff = find_difference(S, diff);
    return diff;
}

int is_subset(NODE *S, NODE *T) //returns 1 if S is subset of T
{
    NODE *current=NULL;

    int s_size = cardinality(S);
    int t_size = cardinality(T);

    if(s_size>t_size)
    {
        printf("Set S is larger than T, hence it cannot be subset of T");
    }
    else
    {
        NODE *first = S;
        NODE *second = T;

        while (first->next != NULL)
        {
            int found = is_element_of(second, first->data);
            if (found == 1)
            {
                return 0;
            }
        }
        return 1;
    }
}

NODE* copy(NODE* old)
{
    NODE *new=NULL;
    NODE *current;
    current=old;
    NODE* copier=new;
    while(current->next!=NULL)
    {
        NODE *temp = (NODE *)malloc(sizeof(NODE));
        temp->data=current->data;
        temp->next=NULL;
        copier=temp;
        current=current->next;
    }
    
    return new;
}

int main()
{
    NODE *new_set,*set_n,*S,*T;

    printf("\nBefore we start we must create two sample sets");

    //Create set S
    printf("\nEnter number of elements you want to add to the set S: ");
    int S_n;
    scanf("%d", &S_n);

    int S_elements[S_n];

    for (int i = 0; i < S_n; i++)
    {
        printf("\nEnter element number %d: ", i + 1);
        int temp;
        scanf("%d", &temp);
        S_elements[i]=temp;
    }
    S = build(S_n, S_elements);
    enumerate(S);
    //End of create set S

    //Create set T
    printf("\nEnter number of elements you want to add to the set T: ");
    int T_n;
    scanf("%d", &T_n);

    int T_elements[T_n];

    for (int i = 0; i < T_n; i++)
    {
        printf("\nEnter element number %d: ", i + 1);
        scanf("%d", &T_elements[i]);
    }
    
    T=build(T_n, T_elements);
    enumerate(T);
    //End of create set T

        new_set = create_set();       
            int x;
            int flag=1;
            while(flag!=0)
            {
                printf("\nEnter the number you want to add to the set [Press 0 to exit]");
                scanf("%d",&x);
        
                if(x==0)
                {
                    flag=0;
                }
                else
                {                   
                    new_set=add_element(new_set, x);
                }
                
               
            }
        

        
            enumerate(new_set);



       
            int find;
            printf("\nEnter element x to find whether its a part of the set: ");
            scanf("%d", &find);
            
            if (is_element_of(new_set, find))
            {
                printf("Element %d found",find);
            }
            else{
                printf("Element is not a part of the set");
            }


       
            printf("\nThe Cardinality of set is %d",cardinality(new_set));
           
    int n;

    printf("\nWe will add element x to initial set, Enter x: ");

    scanf("%d", &x);
    new_set = add_element(new_set, x);
    enumerate(new_set);

    printf("\nEnter x we will remove it from the set if its present: ");

    scanf("%d", &x);
    remove_element(new_set, x);
    enumerate(new_set);

    

    NODE *union_set = find_union(S, T);
    printf("\nBelow is Uion of Sets S and T");
    enumerate(union_set);

    
    NODE *intersection_set = find_intersection(S, T);
    printf("\nBelow is Intersection of Sets S and T");
    enumerate(intersection_set);
 
    NODE *difference_set = find_difference(S, T);
    printf("\nBelow is Difference of Sets S and T");
    enumerate(difference_set);
/*
    int subset = is_subset(S, T);
    if (subset == 1)
    {
        printf("\nS is a subset of T");
    }
    else if (subset == 0)
    {
        printf("\nS is NOT a subset of T");
    }
*/       
}
    


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
    int found = 0;
    int end = 0;
    while (found != 1 || travel->next != NULL)
    {
        if (travel->data == x)
        {
            found = 1;
        }
        travel = travel->next;
    }
    if (found == 1)
    {
        return 1;
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
    int count;
    NODE *travel;
    travel = head;
    while (travel->next != NULL)
    {
        if(travel->data!=0)
        {
            count++;
        }
        
        travel = travel->next;
    }
    return count;
}

int enumerate(NODE *head) //incorrect code must be fixed
{
    NODE *current;
    current = head;
    if (head->next == NULL)
    {
        printf("\nThe set is empty please add some elements to it to see the output.");
    }
    else
    {
        while (head->next != NULL)
        {

            printf("\nEnter number of elements you want to add to the set");
            int number_of_elements;
            scanf("%d", &number_of_elements);
            int set_elements[number_of_elements];

            for (int i = 0; i < number_of_elements; i++)
            {
                printf("\nEnter element number %d", i + 1);
                scanf("%d", &set_elements[i]);
            }
        }
        printf("\nThe set is as below\n");
        printf("{ ");

        printf("\nEnter number of elements you want to add to the set");
        int number_of_elements;
        scanf("%d", &number_of_elements);
        int set_elements[number_of_elements];

        for (int i = 0; i < number_of_elements; i++)
        {
            printf("\nEnter element number %d", i + 1);
            scanf("%d", &set_elements[i]);
        }

    }
    printf("%d, ", current->data);
    printf(" }");
}

//Note to self: brackets needed in declaration of function which accepts the array.
 int build( int number_of_elements, int set_elements[], NODE *head)
{
    NODE *current = NULL;

    current = head;

    for (int i = 0; i < number_of_elements; i++)
    {
        NODE *temp = (NODE *)malloc(sizeof(NODE));
        temp->data = set_elements[i];
        temp->next = NULL;
        current->next = temp;
        current = temp;
    }

    printf("\n The set has been created, use enumerate utility to output the set");
}

int add_element(NODE *head, int element)
{
    NODE *current = NULL;

    if (head->next == NULL)
    {
        current = head;
        NODE *temp = (NODE *)malloc(sizeof(NODE));
        printf("\nEnter number of elements you want to add to the set");
        int number_of_elements;
        scanf("%d",&number_of_elements);
        int set_elements[number_of_elements];
    
        for(int i = 0; i < number_of_elements; i++)
        {
            printf("\nEnter element number %d", i + 1);
            scanf("%d", &set_elements[i]);
        }
   
    
        temp=(NODE*)malloc(sizeof(NODE));
        temp->data = element;
        temp->next = NULL;
        current = head = temp;
    }

    else
    {
        NODE *temp = (NODE *)malloc(sizeof(NODE));
        temp->data = element;
        temp->next = NULL;
        current->next = temp;
        current = temp;
    }

} //end of add element code

//void build(number_of_elements, set_elements, head); //Note to self: no brackets needed while passing array to function.

NODE* create()
{
    NODE *head = NULL;
    head->next = NULL;
    return head;
}

NODE* create_with_capacity(int n)
{
    NODE *head=NULL;
    NODE* current=NULL;
    head->next = NULL;
    current=head;
    for(int i=0;i<n;i++)
    {
        NODE* temp=(NODE*)malloc(sizeof(NODE));
        current->next=temp;
        temp->data=0;
        current=temp;
    }
    
    return head;

}

int add(NODE* head, int x)
{
    int is_present=is_element_of(head,x);
    if(is_present==1)
    {
        printf("The element %d is already present in the set",x);
    }
    else
    {   
        NODE* current=head;
        while(current->next!=NULL)
        {
            current=current->next;
        }
        NODE *temp = (NODE *)malloc(sizeof(NODE));
        current->next=temp;
        temp->data=x;
        temp->next=NULL;
    }
}

int remove_element(NODE *head, int x)
{
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
}


int capacity(NODE *head)
{
    int count;
    NODE *travel;
    travel = head;
    while (travel->next != NULL)
    {
        count++;
    
    travel = travel->next;
    }

    return count;
}


NODE* copy(NODE* old);//copy function must be before find_union

NODE* find_union(NODE *S, NODE *T) //function name union resulted in error, why?
{
    NODE *union_set;
    //NODE *scurrent; not needed
    //NODE *tcurrent; not needed
    NODE* current;
    NODE *first;
    NODE *second;
    NODE *end_union;
    int s_size = cardinality(S);
    int t_size=cardinality(T);

    if(s_size<=t_size)
    {
        first= S;
        //second = T; not needed
        current=T;
        
    }
    
    else
    {
        first= T;
        //second = S; not needed
        current=S;
    }

    union_set=copy(first); //add first set to union

    //finding end of union
    end_union=union_set;
    while(end_union!=NULL)
    {
        end_union=end_union->next;
    }    

    while(current->next!=NULL)
    {
        int found = is_element_of(union_set, current->data);
        if(found==0)
        {
            NODE *temp = (NODE *)malloc(sizeof(NODE));
            end_union->next=temp;
            temp->data = current->data;
            temp->next=NULL;
            end_union=temp;
        }

        current=current->next;

    }

return union_set;
}

NODE *find_intersection(NODE *S, NODE *T) 
{
    NODE *intersection_set;
    //NODE *scurrent; not needed
    //NODE *tcurrent; not needed
    NODE *current;
    NODE *first;
    NODE *second;
    int s_size = cardinality(S);
    int t_size = cardinality(T);

    if (s_size <= t_size)
    {
        first = S;
        second = T; 
    }

    else
    {
        first = T;
        second = S; 
    }

    current=intersection_set;
    while (first->next != NULL)
    {
        int found = is_element_of(second, first->data);
        if (found == 1)
        {
            NODE *temp = (NODE *)malloc(sizeof(NODE));
            current->next=temp;
            temp->data = first->data;
            temp->next = NULL;
            current = temp;
        }

        first = first->next;
    }
    return intersection_set;
}

NODE *find_difference(NODE *S, NODE *T)
{
    NODE *difference_set=NULL;
    NODE *current;
    NODE *first=S;
    NODE *second=T;

    current = difference_set;

    while (first->next != NULL)
    {
        int found = is_element_of(second, first->data);
        if (found == 0)
        {
            NODE *temp = (NODE *)malloc(sizeof(NODE));
            current->next = temp;
            temp->data = first->data;
            temp->next = NULL;
            current = temp;
        }

        first = first->next;
    }
    return difference_set;
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
    NODE *head = create_set();

    printf("\nEnter number of elements you want to add to the set");
    int number_of_elements;
    scanf("%d", &number_of_elements);
    int set_elements[number_of_elements];

    for (int i = 0; i < number_of_elements; i++)
    {
        printf("\nEnter element number %d", i + 1);
        scanf("%d", &set_elements[i]);
    }

    build(number_of_elements, set_elements, head); //Note to self: no brackets needed while passing array to function.
    enumerate(head);
}
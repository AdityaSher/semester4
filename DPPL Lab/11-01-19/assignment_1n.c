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

//Note to self: brackets needed in declaration of function which accepts the array.
 NODE *build( int number_of_elements, int set_elements[], NODE *head)
{
    NODE *current = NULL;

    if(head==NULL)
    {
        NODE *temp = (NODE *)malloc(sizeof(NODE));
        temp->data = set_elements[0];
        head=temp;
    }

    current = head;
    for (int i = 1; i < number_of_elements; i++)
    { 
        NODE* temp = (NODE*)malloc(sizeof(NODE));
        
        current->next = temp;     
        temp->data = set_elements[i];
        temp->next = NULL;
        current = temp;
        
    }
    printf("\n The set has been created, use enumerate utility to output the set");

    return head;
}

NODE* add_element(NODE *head, int element)
{
    NODE *current = NULL;
    current = head;
    if(head==NULL)
    {
        printf("test0");
        NODE *temp = (NODE *)malloc(sizeof(NODE));
        printf("test");
        temp->data=element;
        printf("test1");
        temp->next=NULL;
        printf("test2");
        head=temp;            
    }
    else
    {
        while (current->next != NULL)
        {
            current = current->next;
        }
        
        NODE *temp = (NODE *)malloc(sizeof(NODE));
        temp->data = element;
        temp->next = NULL;
        current->next=temp;
        current = temp;
    }
return head;
} //end of add element code


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

    build(S_n, S_elements, S);
  
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
    
    build(T_n, T_elements, T);
    //End of create set T

        new_set = create_set();
        
            int x;
            int flag=1;
            while(flag!=0)
            {
                printf("\nEnter the number you want to add to the set [Press 0 to exit]");
                scanf("%d",&x);
                printf("test11");
                if(x==0)
                {
                    flag=0;
                    printf("test21");
                }
                else
                {
                    printf("test22");
                    add_element(new_set, x);
                }
                
                
            }
        

        
            enumerate(new_set);



       
            int find;
            printf("/nEnter element x to find whether its a part of the set: ");
            scanf("%d", &find);
            is_element_of(new_set, find);



       
            cardinality(new_set);
           


      
            int n;
            printf("\nWe will create an empty set with capacity n, enter n: ");
            set_n = create_with_capacity(n);
        


            printf("We will add element x to initial set, Enter x: ");
        
            scanf("%d", &x);
            new_set = add_element(new_set, x);

            printf("Enter x we will remove it from the set if its present: ");
          
            scanf("%d", &x);
            remove_element(new_set, x);
   

            printf("Find capacity of set, you have two options\n 1.Find capacity of set that we created in option 1 and added values in option 2\nOR\nFind capacity of set we created without elemens in option 6\nEnter your choice: ");
            int option;
            scanf("%d", &option);

            if (option == 1)
            {
                int cap = capacity(new_set);
                printf("\nCapacity of set is %d ", cap);
            }
            else if (option == 2)
            {
                int cap = capacity(set_n);
                printf("\nCapacity of set is %d ", cap);
            }
            else
            {
                printf("Option you entered was incorrect");
            }



        
            NODE *union_set = find_union(S, T);
            printf("/nBelow is Uion of Sets S and T");
            enumerate(union_set);
        

            NODE *intersection_set = find_intersection(S, T);
            printf("/nBelow is Intersection of Sets S and T");
            enumerate(intersection_set);
       

            NODE *difference_set = find_difference(S, T);
            printf("/nBelow is Difference of Sets S and T");
            enumerate(difference_set);
        
       

            int subset = is_subset(S, T);
            if (subset == 1)
            {
                printf("\nS is a subset of T");
            }
            else if (subset == 0)
            {
                printf("\nS is NOT a subset of T");
            }
    
   
        
            
        

        
}
    


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


//create_set function returns head of set after initialization
NODE *create_set()
{
    NODE *head = NULL;

    printf("Your set has been initialized");

    return head;
}


//is_element_of verifies whether entered element is a part of the set
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


//is_empty returns 1 if set is empty
int is_empty(NODE *head)
{
    if (head == NULL)
    {
        return 1;
    }
    return 0;
}


//cardinality returns size of set
int cardinality(NODE *head) 
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

//Enumerate: displays the set
void enumerate(NODE *head)
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

//add_element verifies whether entered element is already a part of the set, if not its added to the set.
NODE *add_element(NODE *head, int element);

NODE *build(int number_of_elements, int set_elements[])
{
    NODE *current = NULL;

    for(int i=0;i<number_of_elements;i++)
    {
        current=add_element(current,set_elements[i]);
    }
    printf("\nThe set has been created, use enumerate utility to output the set");

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

NODE* remove_element(NODE *head, int x)
{   
    NODE* current=head;

    if(head->data==x)
    {
        current=head;
        head=head->next;
        free(head)
    }

	while(current->next!=NULL)
    {
		if(current->next->data==x)
        {
			current->next=current->next->next;
			return;
		}
		current=current->next;
    }
  return head;
}

NODE* copy(NODE* old);//copy function must be before find_union

//Union returns set which is union of two input sets
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
        {
            head=newnode;
        }
            
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


//find_difference returns set which is difference of two entered sets
NODE* find_difference(NODE *S, NODE *T)
{   
    NODE *first;
    NODE *second;
    if(cardinality(S)>cardinality(T))
    {
      first=S;
      second=T;
    }
    else
    {
      first=T;
      second=S;
    }
    
    NODE *current;
    //NODE *first=S;
    //NODE* second=T;
    current=NULL;

    while (first!= NULL)
    {
        //for each element of S find whether it exists in T 
        if (!is_element_of(second, first->data))
        {
            NODE *temp = (NODE *)malloc(sizeof(NODE));
            temp->data = first->data;
            temp->next = NULL;
            if(current==NULL)
                current=temp;
            else
            {
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
    
    if(cardinality(S)>cardinality(T))
    {
      diff = find_difference(S, diff);
    }
    else
    {
      diff = find_difference(T, diff);
    }

    
    return diff;
}

int is_subset(NODE *S, NODE *T) //returns 1 if S is subset of T
{
    NODE *current=NULL;

    int s_size = cardinality(S);
    int t_size = cardinality(T);

    if(s_size>t_size)
    {
        printf("\nSet S is larger than T, hence it cannot be subset of T");
    }
    else
    {
        NODE *first = S;
        NODE *second = T;
        int found;
        while (first!= NULL)
        {
            found = is_element_of(second, first->data);
            first=first->next;
        }
        if(found==1)
        {
          return 1;
        }
        return 0;
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


    printf("\nBefore we start dynamic operations we must create two sample sets");

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
    

    NODE *union_set = find_union(S, T);
    printf("\n\nBelow is Union of Sets S and T");
    enumerate(union_set);

    
    NODE *intersection_set = find_intersection(S, T);
    printf("\n\nBelow is Intersection of Sets S and T");
    enumerate(intersection_set);
 
    NODE *difference_set = find_difference(S, T);
    printf("\n\nBelow is Difference of Sets S and T");
    enumerate(difference_set);

    int subset = is_subset(S, T);
    if (subset == 1)
    {
        printf("\n\nS is a subset of T");
    }
    else if (subset == 0)
    {
        printf("\n\nS is NOT a subset of T");
    }
      
}
  
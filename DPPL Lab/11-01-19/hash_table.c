//In this code I will try to implement hash table implementation.
//Linked List method will be follow
//index of hash table will be from


/*
List of Variables used
hash_node as Node (of table that will store the element)
*/

//Import Dependencies
#include <stdio.h>
#include <stdlib.h>

#define table_size 10

typedef struct hash_node
{
    int data;
    struct hash_node *next;

} Node;

typedef struct hash_table
{
    struct hash_node *h[table_size];
} table;

//Definition of all functions

//Definition of all functions ENDS


table *create_set()
{
    table *set_init=(table *)malloc(sizeof(table));
    for(int i = 0; i < table_size; i++)
    {
        set_init->h[i]=NULL;
    }
    
    printf("\nYour set has been initialized");

return set_init;
}

int hash(int element)
{
    int key_index = element % table_size;
    
    return key_index;
}


int is_element_of(table *key, int element)
{
  
    Node *travel = key->h[hash(element)];
    
    while (travel!= NULL)
    {
    
        if (travel->data == element)
        {   
            return 1;
        }
        travel= travel->next;
    }
    
    return 0;
}


table *add_element(table *key, int element)
{
    
    if (!is_element_of(key,element))
    {
        int key_index=hash(element);
           
        Node *current;
        
        current = key->h[key_index];
        
        if (current==NULL)
        {
            Node *temp=(Node*)malloc(sizeof(Node));            
            temp->data = element;          
            temp->next = NULL;
            key->h[key_index] = temp;
        }

        else
        {        
            current = key->h[key_index];
            while(current->next!=NULL)
            {
                current=current->next;     
            }
    
            Node *temp = (Node *)malloc(sizeof(Node *));

            temp->data = element;
            temp->next = NULL;

            current->next = temp;
        }

        
    }
    else
    {
        printf("\nElement already exists!");
    }
    return key;
}

int is_empty(table *key)
{
    for(int x=0; x<table_size;x++)
    {
        if (key->h[x] != NULL)
        {           
            return 0;
        }
    }
    return 1;
}

int cardinality(table *key)
{
    int count=0;
    Node *travel;
    for (int x=0; x < table_size; x++)
    {
        travel = key->h[x];

        while (travel != NULL)
        {
            if (travel->data != 0)
            {
                count++;
            }

            travel = travel->next;
        }
    }  
    
    return count;
}

void enumerate(table *key)
{
    Node *travel;

    if (is_empty(key))
    {
        printf("\nThe set is empty please add some elements to it to see the output.");
    }
    else
    {

        for (int x=0; x < table_size; x++)
        {
            travel = key->h[x];
            printf("\nKey= %d :", x);
            while (travel!= NULL)
            {
                printf("%d ->", travel->data);
                travel = travel->next;
            }
        }
    }
}

table *build(int number_of_elements, int set_elements[])
{
    table *current = create_set();

    for (int i = 0; i < number_of_elements; i++)
    {
        current= add_element(current, set_elements[i]);
    }

    printf("\nThe set has been created, use enumerate utility to output the set");
    
    return current;
}

table *remove_element(table *key, int element)
{
    
    if (!is_element_of(key,element))
    {
        printf("\nCannot remove element %d as element doesn't exist in the set!",element);
    }
    else
    {
        
        int index_key=hash(element);
        Node *current = key->h[index_key];
        current = key->h[index_key];

        if (key->h[index_key]->data == element)
        {
            //element is stored at first node //working
            key->h[index_key] = key->h[index_key]->next;
            free(current);
        }
        else
        {
            //element is stored at nodes other than first node!

            while (current->next != NULL)
            {
                if (current->next->data == element)
                {
                    current->next = current->next->next;
                    return key;
                }
                current = current->next;
            }
        }
        
    }

    return key;
}

table *copy(table *old)
{   
    
    table *new_table = create_set();

    Node *travel;

    for (int x=0; x < table_size; x++)
    {
        travel = old->h[x];
    
        while (travel != NULL)
        {
            add_element(new_table,travel->data);
            travel=travel->next;
        }
        
    }
    
    return new_table;
}

//In union I have first copied the first set then checked whether element of second exists in first if not then add it to union
// Another approach can be adding element to the list by simply copying it (Writing custom code in find_union itself, which one is better?)

table *find_union(table *S, table *T) 
{
    table *union_set= create_set();  
    Node *travel;
    union_set=copy(S);
    

    for (int x=0; x < table_size; x++)
    {
        travel = T->h[x];
        
        while (travel!= NULL)
        {
            if (!is_element_of(union_set,travel->data))
            {   

                add_element(union_set,travel->data);
            }
            travel=travel->next;  
        }
        
    }

    return union_set;
}

//find_difference returns set which is difference of two entered sets
table *find_difference(table *S, table *T)
{
    int is_s_larger = 0;
    

    if (cardinality(S) > cardinality(T))
    {
        is_s_larger = 1;
    }
    else
    {
        is_s_larger = 0;
    }
    
    table *t1;
    
    t1= create_set();
    

    for (int x = 0; x < table_size; x++)
    {
        table *temp;
        
        if (is_s_larger == 1)
        {
            
            t1->h[x] = S->h[x];
            temp=T;
        }
        else
        {
            
            t1->h[x] = T->h[x];
            temp = S;
        }

        while (t1->h[x] != NULL)
        {
            
            if (!is_element_of(temp, t1->h[x]->data))
            {
                
                table *temp = (table *)malloc(sizeof(Node));
                temp->h[x]->data = t1->h[x]->data;
                temp->h[x]->next = NULL;
                if (t1->h[x] == NULL)
                {
                    t1->h[x] = temp->h[x];
                }

                else
                {
                   
                    temp->h[x]->next = t1->h[x];
                    t1->h[x] = temp->h[x];
                }
            }
            
            t1->h[x] = t1->h[x]->next;
        }
    
    }
    return t1;
}

table *find_intersection(table *S, table *T)
{
    table *diff = create_set();
    printf("\n I entered intersection");
    diff = find_difference(S, T);
    printf("\nSurpassed line 351");
    if (cardinality(S) > cardinality(T))
    {
        diff = find_difference(S, diff);
    }
    else
    {
        diff = find_difference(T, diff);
    }

    return diff;
}

int is_subset(table *S, table *T) //returns 1 if S is subset of T
{
    table *current = NULL;

    int s_size = cardinality(S);
    int t_size = cardinality(T);

    if (s_size > t_size)
    {
        printf("\nSet S is larger than T, hence it cannot be subset of T");
    }
    else
    {
        Node *travel;

        for (int x=0; x < table_size; x++)
        {
            travel = S->h[x];

            while (travel != NULL)
            {
                if (is_element_of(T, travel->data))
                {
                    return 1;
                }
                travel = travel->next;
            }
        }

        

        return 0;
    }
}



int main()
{

    table *set_n = create_set();
    table *S = create_set();
    table *T = create_set();

    table *new_set= create_set();
    
    int x;
    int flag = 1;
    while (flag != 0)
    {
        printf("\nEnter the number you want to add to the set [Press 0 to exit]");
        scanf("%d", &x);

        if (x == 0)
        {
            flag = 0;
        }
        else
        {
            new_set = add_element(new_set, x);
        }

    }

    enumerate(new_set);

    int find;
    printf("\nEnter element x to find whether its a part of the set: ");
    scanf("%d", &find);

    if (is_element_of(new_set, find))
    {
        printf("Element %d found", find);
    }
    else
    {
        printf("Element is not a part of the set");
    }

    printf("\nThe Cardinality of set is %d", cardinality(new_set));

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
        S_elements[i] = temp;
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

    T = build(T_n, T_elements);
    enumerate(T);
    //End of create set T

    table *union_set = find_union(S, T);
    printf("\n\nBelow is Union of Sets S and T");
    enumerate(union_set);

    table *intersection_set = find_intersection(S, T);
    printf("\n\nBelow is Intersection of Sets S and T");
    enumerate(intersection_set);

    table *difference_set = find_difference(S, T);
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



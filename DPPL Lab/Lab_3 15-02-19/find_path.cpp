#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct node
{
    int key;
    node *next;

} NODE;


// define default capacity of the stack
#define SIZE 10

// Class for stack
class stack
{
    int *arr;
    int top;
    int capacity;

  public:
    stack(int size = SIZE); // constructor

    void push(int);
    int pop();
    int peek();

    int size();
    bool isEmpty();
    bool isFull();
};

// Constructor to initialize stack
stack::stack(int size)
{
    arr = new int[size];
    capacity = size;
    top = -1;
}

// Utility function to add an element x in the stack
void stack::push(int x)
{
    if (isFull())
    {
        cout << "OverFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    arr[++top] = x;
}

// Utility function to pop top element from the stack
int stack::pop()
{
    // check for stack underflow
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }


    // decrease stack size by 1 and (optionally) return the popped element
    return arr[top--];
}

// Utility function to return top element in a stack
int stack::peek()
{
    if (!isEmpty())
        return arr[top];
    else
        exit(EXIT_FAILURE);
}

// Utility function to return the size of the stack
int stack::size()
{
    return top + 1;
}

// Utility function to check if the stack is empty or not
bool stack::isEmpty()
{
    return top == -1; // or return size() == 0;
}

// Utility function to check if the stack is full or not
bool stack::isFull()
{
    return top == capacity - 1; // or return size() == capacity;
}

class graphit
{

    //graph accepts node values from 0 to 5 as of now!
    NODE *g[7];
    // add_node returns 1 if node sucessfully added, returns 0 if node already present.

  public:
    graphit()
    {
        for (int i = 0; i < 7; i++)
        {
            g[i] = NULL;
        }
    }
    int add_edge(int source, int destination)
    {
        NODE *vertex = (NODE *)malloc(sizeof(NODE));
        vertex->key = destination;
        vertex->next = NULL;

        NODE *temp = g[source];

        if (g[source] == NULL)
        {

            g[source] = vertex;
        }

        else
        {

            while (temp->next != NULL)
            {

                temp = temp->next;
            }
            temp->next = vertex;
        }
    }


    int find_path_length(int start_node,int destination_node)
    {
        NODE *temp = g[start_node];
        NODE *vertex;
        stack s;
        int count=0;
        int visited[7] = {0};

        s.push(start_node);
        
        while (!s.isEmpty())
        {
            int current_node = s.pop();

            if(current_node==destination_node)
            {
                
                cout<<"\n";
                return count;
            }


            temp = g[current_node];

            while (temp != NULL)
            {
                if (!visited[temp->key])
                {
                    s.push(temp->key);
                    
                    visited[temp->key] = 1;
                }
                temp = temp->next;
            }
            count++;
        }
        return -1;
    }

};

int main()
{

    graphit g;
    g.add_edge(6,0);
    g.add_edge(0, 2);
    g.add_edge(5,2);
    g.add_edge(5,6);
    g.add_edge(0,1);
    g.add_edge(6,4);
    g.add_edge(4,1);
    g.add_edge(1, 3);
 
    cout << "The length of path if exists (-1 means no such paths exists)\n";

    cout << g.find_path_length(5,3);
}
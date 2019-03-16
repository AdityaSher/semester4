#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct node
{
    int key;
    node *next;

} NODE;

class queue
{

    NODE *front = NULL;
    NODE *rear = NULL;
    NODE *temp = NULL;

  public:
    queue()
    {
    }
    int isempty()
    {
        if (front == NULL && rear == NULL)
        {

            return 1;
        }

        return 0;
    }

    void enqueue(int element)
    {
        NODE *add = (NODE *)malloc(sizeof(NODE));
        add->key = element;
        add->next = NULL;

        if (front == NULL && rear == NULL)
        {

            front = rear = add;

            return;
        }

        else
        {
            rear->next = add;
            rear = add;
            return;
        }
    }

    int dequeue()
    {

        if (!isempty())
        {
            temp = front;
            if (front != rear)
            {
                front = front->next;

                int popped_data = temp->key;

                free(temp);

                return popped_data;
            }
            else
            {
                int popped_data = temp->key;
                
                front = rear = NULL;

                free(temp);

                return popped_data;
            }
        }
        /*
        else
        {
            cout << "Queue is empty" << endl;
            retur
        }
        */
        
    }

    int delet()
    {
        temp = front;

        if (front == NULL)
        {
            return 0;
        }

        else if (front->next != NULL)
        {
            int deleted = front->key;
            front = front->next;
            free(temp);
            return deleted;
        }

        else
        {
            int deleted = front->key;
            front = rear = NULL;
            free(temp);
            return deleted;
        }
    }
    void display()
    {
        temp = front;
        if ((front == NULL) && (rear == NULL))
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements are: ";
        while (temp != NULL)
        {
            cout << temp->key << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

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
    NODE *g[6];
    // add_node returns 1 if node sucessfully added, returns 0 if node already present.

  public:
    graphit()
    {
        for (int i = 0; i < 6; i++)
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

    void bfs()
    {
        NODE *temp = g[0];
        NODE *vertex;
        queue q;
        int visited[6] = {0, 0, 0, 0, 0, 0};
       
        q.enqueue(0);
        
        while (!q.isempty())
        {
            int current_node = q.dequeue();
            cout << current_node << " -> ";
            temp = g[current_node];

            while(temp!=NULL)
            {
                if (!visited[temp->key])
                {
                    q.enqueue(temp->key); 
                    visited[temp->key] = 1; 
                }
                temp=temp->next;
            }
        }
    }

    void dfs()
    {
        NODE *temp = g[0];
        NODE *vertex;
        stack s;
        int visited[6] = {0, 0, 0, 0, 0, 0};

        s.push(0);

        while (!s.isEmpty())
        {
            int current_node = s.pop();
            cout << current_node << " -> ";
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
        }
    }
};

int main()
{

    graphit g;
    g.add_edge(0, 3);
    g.add_edge(0, 2);
    g.add_edge(2, 1);
    g.add_edge(3, 1);
    g.add_edge(3, 5);
    g.add_edge(1, 4);

    cout << "BFS\n";
    g.bfs();

    cout << "DFS\n";
    g.dfs();
    cout << "\n";
}
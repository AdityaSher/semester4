// A C++ program to print topological sorting of a DAG
#include <iostream>
#include <list>
#include <stack>
using namespace std;

// Class to represent a graph
class graphit
{
    int vert; // No. of vertices'

    // Pointer to an array containing adjacency lists
    list<int> *adj;

    // Subroutine for topologicalSort
    void topological_sort_subroutine(int v, bool visited[], stack<int> &st);

    public:
    graphit(int vert); // Constructor

    // function to add an edge to graph
    void add_edge(int v, int w);

    // prints a Topological Sort of the complete graph
    void topologicalSort();
};

graphit::graphit(int vert)
{
    this->vert = vert;
    adj = new list<int>[vert];
}

void graphit::add_edge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

// A recursive function used by topologicalSort
void graphit::topological_sort_subroutine(int v, bool visited[],
                                stack<int> &st)
{
    // Mark the current node as visited.
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topological_sort_subroutine(*i, visited, st);

    // Push current vertex to stack which stores result
    st.push(v);
}

// The function to do Topological Sort. It uses recursive
// topological_sort_subroutine()
void graphit::topologicalSort()
{
    stack<int> st;

    // Mark all the vertices as not visited
    bool *visited = new bool[vert];
    for (int i = 0; i < vert; i++)
        visited[i] = false;

    // Call the recursive helper function to store Topological
    // Sort starting from all vertices one by one
    for (int i = 0; i < vert; i++)
        if (visited[i] == false)
            topological_sort_subroutine(i, visited, st);

   
    while (st.empty() == false)
    {
        cout << st.top() << " ";
        st.pop();
    }
}


int main()
{
    
    graphit g(6);
    g.add_edge(1, 3);
    g.add_edge(1, 5);
    g.add_edge(2, 1);
    g.add_edge(0, 3);
    g.add_edge(0, 4);
    g.add_edge(2, 0);

    cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort();

    return 0;
}

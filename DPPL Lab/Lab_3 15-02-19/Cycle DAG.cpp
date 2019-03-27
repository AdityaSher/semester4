#include<iostream>

using namespace std;

class node
{
    public:
    int data;
    node* next;
    node()
    {
        next=NULL;
    }
    node(int d)
    {
        data=d;
        next=NULL;
    }
};




class Graph
{
    public:
    node **relation;
    int vertex_count;
    void initialise(int element[])
    {
        for(int i=0;i<vertex_count;i++)
        {
            node* newnode=new node(element[i]);
            relation[i]=newnode;        ///here all the link list have first node as parent
        }

    }

    ///THESE FUNCTION ARE UTLITY FOR TOPOLOGICAL SORT*************************
    int incoming_edge(int index)
    {
        int count=0;
        int key=relation[index]->data;
        for(int i=0;i<vertex_count;i++)
            {
                if(relation[i]!=NULL &&i!=index)    ///skipping the index that is passed
                {
                    node* temp;
                    temp=relation[i];
                    temp=temp->next;            ///skipping the parent
                    while(temp!=NULL){
                        if(temp->data==key)
                            count++;    ///one incoming edge to the node passed
                        temp=temp->next;
                    }
                }

            }
        return count;
    }
     int find_zero_value_index(int in_degree[])
        {
            for(int i=0;i<vertex_count;i++)
            {
                if(in_degree[i]==0)
                    return i;
            }
            return -1;
        }
        void reduce_indegree(int index,int in_degree[])
        {
            node* temp=relation[index];
            while(temp!=NULL)
            {
             int i=find_index(temp->data);
             in_degree[i]--;
             temp=temp->next;
            }
        }

        ///*******************************************************************
    public:
        Graph(int count,int ele[])
        {
            vertex_count=count;
            relation=new node*[count];
            initialise(ele);
        }
        int find_index(int ele)
        {
            for(int i=0;i<vertex_count;i++)
            {
                if(relation[i]->data==ele)
                    return i;
            }
            return -1;
        }
        bool insert_edge(int parent,int child)
        {
            int p,c;
            p=find_index(parent);
            c=find_index(child);
            if(p==-1 | c==-1)
                return false;
            node* temp=relation[p];
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            node* newnode=new node(child);
            temp->next=newnode;
            return true;
        }


        void Topological_util(int in_degree[],int result[])
        {
            int i=0;
            while(i<vertex_count)
            {
                int index=find_zero_value_index(in_degree);
                if(index==-1)
                    result[i]=INT_MIN;
                else{
                     result[i]=relation[index]->data;
                     reduce_indegree(index,in_degree);
                }
                i++;
            }


        }
        bool DetectCycle()
        {
            int in_degree[vertex_count];
            int result[vertex_count];
            for(int i=0;i<vertex_count;i++)
            {
                in_degree[i]=incoming_edge(i);
            }
            Topological_util(in_degree,result);
            for(int i=0;i<vertex_count;i++)
            {
                if(result[i]==INT_MIN)
                    return true;
            }
            return false;
        }
        void print()
        {
            bool flag=false;
            for(int i=0;i<vertex_count;i++)
            {
                flag=false;
                if(relation[i]!=NULL)
                {
                    node* temp;
                    temp=relation[i];
                    cout<<"Element:-"<<temp->data<<endl;   ///printing the parent
                    temp=temp->next;            ///skipping the parent
                    while(temp!=NULL){
                        flag=true;
                        cout<<"\thas an edge to:- "<<temp->data<<endl;
                        temp=temp->next;
                    }
                    if(!flag)
                        cout<<"\tdoesn't have any edge"<<endl;
                }

            }
            cout<<endl;
        }
};
int main()
{
 int b[]={0,1,2,3,4};    ///the elements in the graph
    int countele=5;         ///total elements in graph

    Graph G(countele,b);
    G.insert_edge(0,1);
    G.insert_edge(0,4);
    G.insert_edge(1,2);
    G.insert_edge(2,3);
    G.insert_edge(2,4);
    G.insert_edge(4,3);
    G.print();

    cout<<"Cycle-:";
    cout<<G.DetectCycle();
}


#include<iostream>
#include<stack>
using namespace std;
struct Arc//EdgeNode
{
    int NodeNo;
    Arc *next;
};
struct Vex
{
    char data;
    Arc *firstfellow;//the first EdgeNode
};

class Graph
{
private:
    int edges;//amount of edges
    int vexs;//amount of Nodes
    Vex *list;//to the Vexlist
public:
    Graph();
    void CreatGraph();
    void DFS(int start);
    void DisplayByLine();
    ~Graph();
};

Graph::Graph()
{
    cout<<"How many edges in this graph? "<<endl;
    cin>>edges;
    cout<<"How many nodes in this graph? "<<endl;
    cin>>vexs;
    list=NULL;
}

Graph::~Graph()
{
}
void Graph::CreatGraph()
{
    list=new Vex[vexs];
    for (int i = 0; i < vexs; i++)
    {
        cout<<"What's No."<<i<<"'s data?"<<endl;
        cin>>list[i].data;
        list[i].firstfellow=NULL;
    }
    for (int i = 0; i < vexs; )
    {
        int temp;
        cout<<"Which one No."<<i<<" link to, end with -1."<<endl;
        cin>>temp;
        if (temp!=-1)
        {
            Arc *p=new Arc;
            p->NodeNo=temp;
            p->next=list[i].firstfellow;
            list[i].firstfellow=p;
        }
        else
        {
            i++;
        }
        
    }
}
void Graph::DisplayByLine()
{
    Arc *p=NULL;
    for (int i = 0; i < vexs; i++)
    {
        cout<<"Line "<<i<<"\t";
        p=list[i].firstfellow;
        while (p!=NULL)
        {
            cout<<"["<<p->NodeNo<<"]\t";
            p=p->next;
        }
        cout<<endl;
    }  
}
void Graph::DFS(int start)
{
    stack <int>s;
    Arc *p=NULL;
    int visited[vexs]={0};

    visited[start]=1;
    s.push(start);
    cout<<list[start].data;
    
    while (!s.empty())
    {
        p=list[start].firstfellow;
        while (p)
        {
            if (visited[p->NodeNo]==0)
            {
                visited[p->NodeNo]=1;
                cout<<list[p->NodeNo].data;
                s.push(p->NodeNo);
                p=list[p->NodeNo].firstfellow;
            }
            else
            {
                p=p->next;
            }
            if (p==NULL)
            {
                s.pop();
            }  
        }  
    }
}


int main()
{
    Graph G;
    G.CreatGraph();
    G.DisplayByLine();
    G.DFS(0);
    return 0;
}
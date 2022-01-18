
#include <iostream>
#define VERTEX 4
using namespace std;
 
typedef struct node
{
	int index;
	struct node *next;
}Node;
 

typedef struct vertex
{
	int data;
	Node *first;
}VertexNode, AdjList[VERTEX];
 

typedef struct
{
	int n, e; 
	AdjList adj;
}AdjGraph;
 

void createAdjGraph(AdjGraph &g)
{
	g.n = VERTEX;
	g.e = VERTEX + 1;
 
	Node *p1, *p2, *p3;
	p1 = new Node;
	p2 = new Node;
	p3 = new Node;
	p1->index = 1;
	p2->index = 2;
	p3->index = 3;
	g.adj[0].first = p1;
	p1->next = p2;
	p2->next = p3;
	p3->next = NULL;
 
	Node *q0, *q2;
	q0 = new Node;
	q2 = new Node;
	q0->index = 0;
	q2->index = 2;
	g.adj[1].first = q0;
	q0->next = q2;
	q2->next = NULL;
 
	Node *r0, *r1, *r3;
	r0 = new Node;
	r1 = new Node;
	r3 = new Node;
	r0->index = 0;
	r1->index = 1;
	r3->index = 3;
	g.adj[2].first = r0;
	r0->next = r1;
	r1->next = r3;
	r3->next = NULL;
 
	Node *s0, *s2;
	s0 = new Node;
	s2 = new Node;
	s0->index = 0;
	s2->index = 2;
	g.adj[3].first = s0;
	s0->next = s2;
	s2->next = NULL;
}
 
void inDegree(AdjGraph g)
{
	Node *p;
	int i, inD;
	for(i = 0; i < g.n; i++)
	{
		inD = 0;
		p = g.adj[i].first;
		while(NULL != p)
		{
			inD++;
			p = p->next;
		}
		cout << "top " << i << "in " << inD << endl; 
	}
}
 
void outDegree(AdjGraph g)
{
	Node *p;
	int i, outD;
	for(i = 0; i < g.n; i++)
	{
		outD = 0;
		p = g.adj[i].first;
		while(NULL != p)
		{
			outD++;
			p = p->next;
		}
		cout << "top" << i << " out" << outD << endl; 
	}
}
 
int main()
{
	AdjGraph g;
	createAdjGraph(g);
	inDegree(g); 
	cout << endl;
	outDegree(g); 
	system("pause");
    return 0;
    
} 
/*
#include<iostream>
#include<stack>
using namespace std;
const int MaxSize=100;
class MGraph{
    public:
        int adj[MaxSize][MaxSize],visited[MaxSize];
        int adjvexNum,arcNum;
        MGraph(int n,int e);
}; 
MGraph::MGraph(int n,int e){
    adjvexNum=n;
    arcNum=e;
    int v1,v2;
    for(int i=0;i<adjvexNum;i++)
    {
        for(int j=0;j<adjvexNum;j++)
        adj[i][j]=0;
    }
    for(int i=0;i<adjvexNum;i++)
        visited[i]=0; 
    for(int i=0;i<arcNum;i++)
    {
        cin>>v1>>v2;
        adj[v1][v2]=1;
        adj[v2][v1]=1;
    }
}
void DFS(int i,MGraph G){
    stack<int> s;
    s.push(i);
    cout<<s.top()<<" ";
    int t=i;
    G.visited[i]=1;//vistied[i]=1
    for(int j=i;;j++){
        if(G.adj[i][j]==1&&G.visited[j]==0){ 
            G.visited[j]=1;
            s.push(j);
            cout<<s.top()<<" ";
            i=j;j=0; 
        }
        if(j==G.adjvexNum){ 
            if(t==s.top()) 
            break;
            s.pop();  
            i=s.top();j=0;
        }
    }
}
int main(){
   int adjvexNum,arcNum;
   cout<<"Please input the top and edge: "<<endl; 
   cin>>adjvexNum>>arcNum;
   MGraph G(adjvexNum,arcNum);
   DFS(0,G);
   return 0;
}
*/
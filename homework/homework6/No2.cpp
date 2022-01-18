#include <iostream>
#define VERTEX 4
using namespace std;
 
// 边表结点
typedef struct node
{
	int index;
	struct node *next;
}Node;
 
// 顶点表结点
typedef struct vertex
{
	int data;
	Node *first;
}VertexNode, AdjList[VERTEX];
 
// 图
typedef struct
{
	int n, e; 
	AdjList adj;
}AdjGraph;
 
// 创建图
void createAdjGraph(AdjGraph &g)
{
	g.n = VERTEX;
	g.e = VERTEX + 1;
 
	// 下面创建AdjGraph的代码很丑陋，仅供示意
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
 
// 求图中顶点的入度
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
		cout << "顶点" << i << "的入度为:" << inD << endl; 
	}
}
 
// 求图中顶点的出度
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
		cout << "顶点" << i << "的出度为:" << outD << endl; 
	}
}
 
int main()
{
	AdjGraph g;
	createAdjGraph(g);
	inDegree(g);  // 打印入度
	cout << endl;
	outDegree(g); // 打印出度
	system("pause");
    return 0;
    
} 
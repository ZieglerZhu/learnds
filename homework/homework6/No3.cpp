#include<iostream>
#include<stack>
using namespace std;
const int MaxSize=100;
class MGraph{//邻接矩阵的构建 
    public:
        int adj[MaxSize][MaxSize],visited[MaxSize];
        int adjvexNum,arcNum;
        MGraph(int n,int e);
}; 
MGraph::MGraph(int n,int e){
    adjvexNum=n;//顶点数 
    arcNum=e;//边数 
    int v1,v2;
    for(int i=0;i<adjvexNum;i++)
    {
        for(int j=0;j<adjvexNum;j++)
        adj[i][j]=0;//初始化，0意味两个顶点没有连接 
    }
    for(int i=0;i<adjvexNum;i++)
        visited[i]=0;//初始化，0意味该顶点没有访问 
    for(int i=0;i<arcNum;i++)
    {
        cin>>v1>>v2;
        adj[v1][v2]=1;//这里因为图是无向的，所以两者都为1 
        adj[v2][v1]=1;//若是有向的，这个不需要为1 
    }
}
void DFS(int i,MGraph G){
    stack<int> s;//定义一个栈 
    s.push(i);//首先把顶点进栈 
    cout<<s.top()<<" ";//输出 
    int t=i;
    G.visited[i]=1;//该顶点已经被访问，vistied[i]=1
    for(int j=i;;j++){
        if(G.adj[i][j]==1&&G.visited[j]==0){//出现于i的邻接点 
            G.visited[j]=1;
            s.push(j);//j入栈 
            cout<<s.top()<<" ";
            i=j;j=0;//为了查找j的邻接点 
        }
        if(j==G.adjvexNum){//意味找不到i的邻接点 
            if(t==s.top())//若栈内的top（）顶点和最开始的i相同，意味遍历结束！ 
            break;
            s.pop();  //该顶点出栈 
            i=s.top();j=0;// 以剩下的栈内top（）为i，查找i的邻接点 
        }
    }
}
int main(){
   int adjvexNum,arcNum;
   cout<<"输入顶点数和边数："<<endl; 
   cin>>adjvexNum>>arcNum;
   MGraph G(adjvexNum,arcNum);//构造图 
   DFS(0,G);
   return 0;
}
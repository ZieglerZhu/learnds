#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

struct ArcNode
{
    int adjvex;//有向边的另一个邻接点的序号
    struct ArcNode *nextarc;//指向下一个边结点的指针
};

struct VNode //顶点
{
    int data;//顶点信息
    struct ArcNode *head1;//出边表的表头指针
    struct ArcNode *head2;//入边表的表头指针
};

struct LGraph //图的邻接表存储结构
{
    struct VNode vertexs[MAX_LENGTH];//顶点数组
    int vexnum,arcnum;//顶点数和边数
};


struct LGraph lg;//图

void CreateLG()
{
    int i = 0;//循环变量
    struct ArcNode *pi;//用来构造边链表的边结点指针
    int v1,v2;//有向边的两个顶点
    for(i = 0; i < lg.vexnum; i++)//初始化表头指针为空
    {
        lg.vertexs[i].head1 = lg.vertexs[i].head2 = NULL;
    }
    
    for(i = 0; i < lg.arcnum; i++)
    {
        printf("请输入一条边的起点和终点\n");
        scanf("%d %d",&v1,&v2);//输入一条边的起点和终点
        v1 --;
        v2 --;
        pi = new ArcNode;
        pi -> adjvex = v2;
        pi -> nextarc = lg.vertexs[v1].head1;//插入链表
        lg.vertexs[v1].head1 = pi;
        pi =  new ArcNode;
        pi -> adjvex = v1;
        pi -> nextarc = lg.vertexs[v2].head2;//插入链表
        lg.vertexs[v2].head2 = pi;
    }
}
//释放图G邻接表各顶点的边链表中的所有边结点所占的存储空间
void DeleteLG()
{
    int i;//循环变量
    struct ArcNode *pi; //用来指向边链表中各边结点的指针
    for(i = 0; i < lg.vexnum; i++)
    {
        pi = lg.vertexs[i].head1;
        //释放第i个顶点出边表各边结点所占的存储空间
        while(pi != NULL)
        {
            lg.vertexs[i].head1 = pi -> nextarc;
            free(pi);
            pi = lg.vertexs[i].head1;
        }
        //释放第i个顶点入边表各边结点所占的存储空间
        pi = lg.vertexs[i].head2;
        while(pi != NULL)
        {
            lg.vertexs[i].head2 = pi -> nextarc;
            free(pi);
            pi = lg.vertexs[i].head2;
        }
    }
}



int main()
{
    int i;//循环变量
    int id,od;//顶点的入度和出度
    struct ArcNode *pi;//用来遍历链表的边结点指针
    while(1)
    {
        lg.vexnum = lg.arcnum = 0;
        //首先输入顶点个数和边数
        printf("请输入顶点数和边数\n");
        scanf("%d %d",&lg.vexnum,&lg.arcnum);
        if(lg.vexnum == 0)
        {
            break;
        }
        CreateLG();//创建图
        //统计顶点的出度
        for(i = 0; i < lg.vexnum; i++)
        {
            od = 0;
            pi = lg.vertexs[i].head1;
            while(pi != NULL)
            {
                od++;
                pi = pi -> nextarc;
            }
            if(i == 0)
            {
                printf("%d ",od);
            }
            else
            {
                printf("%d ",od);
            }
        }
        printf("\n");
        //统计顶点的入度
        for(i = 0; i < lg.vexnum; i++)
        {
            id = 0;
            pi = lg.vertexs[i].head2;
            while(pi != NULL)
            {
                id ++;
                pi = pi -> nextarc;
            }
            if(i == 0)
            {
                printf("%d ",id);
            }
            else
            {
                printf("%d ",id);
            }
        }
        printf("\n");
        DeleteLG();
    }
    return 0;
}
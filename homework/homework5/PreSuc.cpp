#include<iostream>
using namespace std;
struct Node
{
    int ltag,rtag;//tag=0 child,tag=1 thread
    Node *leftchild, *rightchild;
    char data;
};
class ThreadTree
{
private:
    Node *pre=NULL;
    Node *root;
public:
    ThreadTree();
    ~ThreadTree();
    void InputNumber()
    {
        InputNumber(root);
    }
    void InputNumber(Node *&p);
    void PreOrderThread()
    {
        PreOrderThread(root, pre);
    }
    void PreOrderThread(Node *&root, Node *&pre);
    Node PreInNext(Node *&p);
};

ThreadTree::ThreadTree()
{
    root=NULL;
}

ThreadTree::~ThreadTree()
{
}

void ThreadTree::InputNumber(Node *&p)
{
    char temp;
    cout<<"Please input data, end with #. "<<endl;
    cin>>temp;
    if (temp=='#')
    {
        p=NULL;
        return;
    }
    else
    {
        p=new Node;
        p->data=temp;
        p->leftchild=p->rightchild=NULL;
        p->ltag=p->rtag=0;
    }
    InputNumber(p->leftchild);
    InputNumber(p->rightchild); 
}

void ThreadTree::PreOrderThread(Node *&p, Node *&pre)
{
    if(root==NULL)
    {
        cout<<"The Tree is empty!"<<endl;
        return;
    }
    if (p==NULL)
    {
        return;
    }
    if (p->leftchild==NULL)
    {
        p->leftchild=pre;
        p->ltag=1;
    }
    if ((pre!=NULL)&&(pre->rightchild==NULL))
    {
        pre->rightchild=p;
        pre->rtag=1;
    }
    pre=p;
    if (p->ltag==0)
    {
        PreOrderThread(p->leftchild, pre);
    }
    if (p->rtag==0)
    {
        PreOrderThread(p->rightchild,pre);
    }
}

Node ThreadTree::PreInNext(Node *&p)
{
    if (p->ltag==0)
    {
        return *p->leftchild;
    }
    if (p->rtag==1)
    {
        return *p->rightchild;
    }
    if ((p->ltag==1)&&(p->rtag==0))
    {
        p=p->rightchild;
        while (p->leftchild!=NULL)
        {
            p=p->leftchild;
        }
    }
}

int main()
{
    ThreadTree Q;
    Q.InputNumber();
    Q.PreOrderThread();
    return 0;
}
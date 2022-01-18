#include<iostream>
using namespace std;
struct Node
{
    char data;
    Node *LeftChild,*RightChild;
};
class BinaryTree
{
private:
    Node *root;
    int length;
    char *DLR;//PreOrder input
    char *LDR;//InOrder input
public:
    BinaryTree();
    ~BinaryTree();
    void PreOrder()
    {
        PreOrder(root);
    }
    void PreOrder(Node *&root);
    void CreatBiTree()
    {
        CreatBiTree(root, DLR, LDR, length);
    }
    void CreatBiTree(Node *&p, char *ch1, char *ch2, int len);
    void check();
};

BinaryTree::BinaryTree()
{
    root=NULL;
    cout<<"How long is it?"<<endl;
    cin>>length;
    DLR=new char[length];
    LDR=new char[length];
    cout<<"What's the tree PreOrder?"<<endl;
    for (int i = 0; i < length; i++)
    {
        cin>>DLR[i];
    }
    cout<<"What's the tree InOrder?"<<endl;
    for (int i = 0; i < length; i++)
    {
        cin>>LDR[i];
    }
}
void BinaryTree::check()
{
    cout<<"CHECK!!"<<endl;
    cout<<"DLR input is "<<DLR;
    cout<<"LDR input is "<<LDR;
    cout<<"length is "<<length;
}
BinaryTree::~BinaryTree()
{
}


void BinaryTree::PreOrder(Node *&root)
{
    if (root==NULL)
    {
        //cout<<"This tree is empty!"<<endl;
    }
    else
    {
        cout<<"data:"<<root->data<<"\t";
		cout<<"  lchild:";
		if(root->LeftChild!=NULL)
		{
			cout<<root->LeftChild->data<<"\t";
		}
		else
		cout<<"NULL"<<"\t";
		cout<<"rchild:";
		if(root->RightChild!=NULL)
		{
			cout<<root->RightChild->data<<"\t";
		}
		else
		cout<<"NULL"<<"\t";
		cout<<endl;
		PreOrder(root->LeftChild);
		PreOrder(root->RightChild);
    }
}
void BinaryTree::CreatBiTree(Node *&p, char *ch1, char *ch2, int len)
{
    if (len<=0)
    {
        p=NULL;
    }
    else
    {
        p=new Node;
        p->data=*ch1;
        int i;
        for ( i = 0; i < len; i++)
        {
            if (ch2[i]==*ch1)
            {
                break;
            }
        }
        CreatBiTree(p->LeftChild, ch1+1, ch2, i);
        CreatBiTree(p->RightChild, ch1+i+1, ch2+i+1, len-(i+1));
    }
}


int main()
{
    BinaryTree BT;
    //BT.check();
    BT.CreatBiTree();
    cout<<endl;
    BT.PreOrder();
    return 0;
}
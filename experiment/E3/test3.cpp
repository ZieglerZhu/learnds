#include<iostream>
using namespace std;
struct Node
{
    int ltag,rtag;//0=child
    Node *LeftChild, *RightChild;
    char data;
};

class BinaryTree
{
private:
    Node *root;
    Node *pre=NULL;
public:
    BinaryTree();
    void Input()
    {
        Input(root);
    }
    void Input(Node *&proot);
    void PreOrder()
    {
        PreOrder(root);
    }
    void PreOrder(Node *&proot);
    void InOrder()
    {
        InOrder(root);
    }
    void InOrder(Node *&proot);
    void PostOrder()
    {
        PostOrder(root);
    }
    void PostOrder(Node *&proot);
};

BinaryTree::BinaryTree()
{
    root=NULL;
}

void BinaryTree::Input(Node *&proot)
{
    char temp;
    cout<<"Please input data InOrder, # stand for NULL. "<<endl;
    cin>>temp;
    if (temp=='#')
    {
        proot=NULL;
        return;
    }
    else
    {
        proot=new Node;
        proot->data=temp;
        proot->LeftChild=proot->RightChild=NULL;
        proot->ltag=proot->rtag=0;
    }
    Input(proot->LeftChild);
    Input(proot->RightChild); 
}
void BinaryTree::PreOrder(Node *&proot)
{
    if (proot==NULL)
    {
        return;
    }
    cout<<proot->data;
    PreOrder(proot->LeftChild);
    PreOrder(proot->RightChild);
}
void BinaryTree::InOrder(Node *&proot)
{
    if (proot==NULL)
    {
        return;
    }
    PreOrder(proot->LeftChild);
    cout<<proot->data;
    PreOrder(proot->RightChild);
}
void BinaryTree::PostOrder(Node *&proot)
{
    if (proot==NULL)
    {
        return;
    }
    PreOrder(proot->LeftChild);
    PreOrder(proot->RightChild);
    cout<<proot->data;
}
int main()
{
    BinaryTree BT;
    BT.Input();
    BT.PreOrder();
    BT.InOrder();
    BT.PostOrder();
    return 0;
}
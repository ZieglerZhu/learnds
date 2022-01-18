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
    void PrintTreeHeight()
    {
        cout<<"The height of this tree is "<<TreeHeight(root)<<endl;
    }
    int TreeHeight(Node *&proot);
    void PrintTotalNode()
    {
        cout<<"The total node of this tree is "<<TotalNode(root)<<endl;
    }
    int TotalNode(Node *&proot);
    void PrintTotalLeafNode()
    {
        cout<<"Total leaf node of this tree is "<<TotalLeafNode(root)<<endl;
    }
    int TotalLeafNode(Node *&proot);
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
int BinaryTree::TreeHeight(Node *&proot)
{
    if (proot == NULL)
    {
        return 0;
    }
    int LeftHeight = TreeHeight(proot->LeftChild) + 1;
    int RightHeight = TreeHeight(proot->RightChild) + 1;
    return (LeftHeight > RightHeight ? LeftHeight : RightHeight);
}
int BinaryTree::TotalNode(Node *&proot)
{
    if (proot == NULL)
    {
        return 0;
    }
    else
    {
        return (TotalNode(proot->LeftChild) + TotalNode(proot->RightChild) + 1);
    }
}
int BinaryTree::TotalLeafNode(Node *&proot)
{
    if (proot == NULL)
    {
        return 0;
    }
    else if ((proot->LeftChild == NULL) && (proot->RightChild == NULL))
    {
        return 1;
    }
    else
    {
        return (TotalLeafNode(proot->LeftChild) + TotalLeafNode(proot->RightChild));
    }
}
int main()
{
    BinaryTree BT;
    BT.Input();
    BT.PrintTotalLeafNode();
    BT.PrintTotalNode();
    BT.PrintTreeHeight();
    return 0;
}
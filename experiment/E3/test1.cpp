#include<iostream>
using namespace std;
struct HFNODE
{
    char element;
    double weight;
    int parent;
    int left;
    int right;
    string code;
};
class HuffmanTree
{
private:
    int length;
    double *ToWeights;
    char *ToElements;
    HFNODE *ToNode;
    //HuffmanTree *ToTree;
public:
    void Input();
    void IniHFTree();
    void GetMin(int pnow,int &first,int &second);
    void BuildTree();
    void CreatHFCode();
    void PrintInput();
    void PrintTree();
    void PrintHFCode();
};
void HuffmanTree::Input()
{
    cout<<"How long is it?"<<endl;
    cin>>length;
    ToElements=new char[length];
    ToWeights=new double[length];
    for (int i = 0; i < length; i++)
    {
        cout<<"What's elements["<<i+1<<"] "<<endl;
        cin>>ToElements[i];
        cout<<"What's weight["<<i+1<<"] "<<endl;
        cin>>ToWeights[i];
    }
}
void HuffmanTree::IniHFTree()
{
    ToNode=new HFNODE[2*length-1];
    for (int i = 0; i < (2*length-1); i++)
    {
        if (i<length)
        {
            ToNode[i].element=ToElements[i];
            ToNode[i].weight=ToWeights[i];
        }
        else
        {
            ToNode[i].element=0;
            ToNode[i].weight=0;
        }
        ToNode[i].left=ToNode[i].right=ToNode[i].parent=-1;
        ToNode[i].code="";
    }
}
void HuffmanTree::GetMin(int pnow,int &first, int &second)
{
    int i,j;
    for (i = 0; i < pnow; i++)
    {
        if (ToNode[i].parent==-1)
        {
            first=i;
            break;
        }
    }//the first that no parent
    for ( j = i+1; j < pnow; j++)
    {
        if (ToNode[j].parent==-1)
        {
            second=j;
            break;
        }
    }//the second that no parent
    for ( i = 0; i < pnow; i++)
    {
        if ((ToNode[first].weight>ToNode[i].weight)&&(ToNode[i].parent==-1)&&(second!=i))  
        {
            first=i;
        }
    }//first min no parent
    for ( j = 0; j < pnow; j++)
    {
        if ((ToNode[second].weight>ToNode[j].weight)&&(ToNode[j].parent==-1)&&(first!=j))  
        {
            second=j;
        }
    }//second min no parent
    if (ToNode[second].weight<ToNode[first].weight)
    {
        int temp;
        temp=first;
        first=second;
        second=temp;
    }
}
void HuffmanTree::BuildTree()
{
    int i,p1,p2;
    for ( i = length; i < (2*length-1); i++)
    {
        GetMin(i,p1,p2);
        ToNode[p1].parent=ToNode[p2].parent=i;
        ToNode[i].left=p1;
        ToNode[i].right=p2;
        ToNode[i].weight=ToNode[p1].weight+ToNode[p2].weight;
    }
}
void HuffmanTree::CreatHFCode()
{
    string code;
    int i,j,k,parent;
    for ( i = 0; i < length; i++)
    {
        j=i;
        code="";
        while (ToNode[j].parent!=-1)
        {
            parent=ToNode[j].parent;
            if (j==ToNode[parent].left)
            {
                code+="0";
            }
            else
            {
                code+="1";
            }
            j=parent;
        }
        for ( k = (code.size()-1); k >= 0; k--)
        {
            ToNode[i].code += code[k];
        }
    }
}


void HuffmanTree::PrintInput()
{
    for (int i = 0; i < length; i++)
    {
        cout<<"elements["<<i+1<<"] is ";
        cout<<ToElements[i]<<endl;
        cout<<"weight["<<i+1<<"] is ";
        cout<<ToWeights[i]<<endl;
    }
}
void HuffmanTree::PrintTree()
{
    cout<<"Element\t"<<"Weight\t"<<"LeftChild\t"<<"RightChild\t"<<"Parent"<<endl;
    for (int i = 0; i < (2*length-1); i++)
    {
        cout<<ToNode[i].element<<"\t"<<ToNode[i].weight<<"\t"<<ToNode[i].left<<"\t\t"<<ToNode[i].right<<"\t\t"<<ToNode[i].parent<<"\t\t"<<endl;
    }
}
void HuffmanTree::PrintHFCode()
{
    cout<<"Element\t"<<"Code\t"<<endl;
    for (int i = 0; i < length; i++)
    {
        cout<<ToNode[i].element<<" : \t"<<ToNode[i].code<<endl;
    }
    
}

int main()
{
    HuffmanTree HF;
    HF.Input();
    HF.PrintInput();
    HF.IniHFTree();
    HF.BuildTree();
    HF.PrintTree();
    cout<<endl;
    cout<<endl;
    HF.CreatHFCode();
    HF.PrintHFCode();
    return 0;
}
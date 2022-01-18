#include<iostream>
#include<string>
using namespace std;
struct StackNode
{
    int data;
    string unit;
    StackNode *next;
};
class Stack
{
private:
    StackNode *top;
public:
    void Creat();
    bool isEmpty();
    void push(int dataIN,string unitIN);
    void pop();
    void change(int in);
    void PrintAll();
};
void Stack::Creat()
{
    top=new StackNode;
    top->data=-1;
    top->unit="top";
    top->next=NULL;
}
bool Stack::isEmpty()
{
    if (top->next==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Stack::push(int dataIN, string unitIN)
{
    StackNode *p;
    p=new StackNode;
    p->data=dataIN;
    p->unit=unitIN;
    p->next=top->next;
    top->next=p;
}
void Stack::pop()
{
    if (isEmpty())
    {
        cout<<"The stack is empty! "<<endl;
    }
    else
    {
        StackNode *p;
        p=top->next;
        top->next=p->next;
        cout<<p->data<<' '<<p->unit<<' ';
        free(p);
    }
}
void Stack::change(int in)
{
    int tempN;
    string tempS;
    tempN=in%60;
    tempS="sec";
    push(tempN, tempS);
    in=in/60;
    tempN=in%60;
    tempS="min";
    push(tempN, tempS);
    in=in/60;
    tempN=in%24;
    tempS="hour";
    push(tempN, tempS);
    in=in/24;
    tempN=in;
    tempS="day";
    push(tempN, tempS);
}
void Stack::PrintAll()
{
    while (top->next!=NULL)
    {
        pop();
    }
}

int main()
{
    Stack A;
    A.Creat();
    //A.Input();
    int sec;
    cout<<"sec? "<<endl;
    cin>>sec;
    A.change(sec);
    A.PrintAll();
    return 0;
}
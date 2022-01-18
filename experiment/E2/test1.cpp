#include<iostream>
#define STACKMAX 100
using namespace std;
class Stack
{
private:
    int elements[STACKMAX];
    int top;
    int n;
    int d;
    int result;
public:
    void Creat();
    bool isEmpty();
    void Push(int e);
    int Pop();
    void Input();
    void Change();
    void PrintAll();
};

void Stack::Creat()
{
    top=-1;
}
bool Stack::isEmpty()
{
    if (top==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Stack::Push(int e)
{
    if (top==(STACKMAX-1))
    {
        cout<<"ERROR, the stack is full! "<<endl;
    }
    else
    {
        top++;
        elements[top]=e;
    }
}
int Stack::Pop()
{
    if (isEmpty())
    {
        cout<<"The stack is empty! "<<endl;
    }
    else
    {
        int temp=elements[top];
        top--;
        return temp;
    }
}
void Stack::Input()
{
    cout<<"Please input a decimal number. "<<endl;
    cin>>n;
    cout<<"Please input the target base.(2~16) "<<endl;
    cin>>d;
    while ((d<2)||(d>16))
    {
        cout<<"ERROR, Please input the base again. "<<endl;
        cin>>d;
    }
}
void Stack::Change()
{
    int temp;
    do
    {
        temp=n%d;
        Push(temp);
        n=n/d;
    } while (n>0);
}
void Stack::PrintAll()
{
    //result=0;
    cout<<"The result is ";
    while (top>-1)
    {
        int temp=Pop();
        if ((temp>=0)&&(temp<=9))
        {
            cout<<temp;
        }
        else if ((temp>=10)&&(temp<=16))
        {
            switch (temp)
            {
            case 10:
                cout<<'A';
                break;
            case 11:
                cout<<'B';
                break;
            case 12:
                cout<<'C';
                break;
            case 13:
                cout<<'D';
                break;
            case 14:
                cout<<'E';
                break;
            case 15:
                cout<<'F';
                break;
            }
        }
        else
        {
            cout<<endl;
            cout<<"ERROR";
            cout<<endl;
        }   
    }
    //cout<<"The result is "<<result<<endl;
}

int main()
{
    Stack A;
    A.Creat();
    A.Input();
    A.Change();
    A.PrintAll();
    return 0;
}
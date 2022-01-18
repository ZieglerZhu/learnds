#include<iostream>
#define maxlength 100
using namespace std;
class LIST
{
private:
    int elements[maxlength];
    int length;
public:
    void Creat();
    void Input();
    void Input2();
    void Delete(int p);
    void PrintNumber();
    bool isEmpty();
    void DeleteTheSame();
    void Split(LIST &LA,LIST &LB);
};
void LIST::Creat()
{
    length=0;
}
void LIST::Input()
{
    int temp;
    for (int p = 1; p <= maxlength; p++)
    {
        cout<<"Please input some number, end with 0. ";
        cin>>temp;
        if(temp==0)
            break;
        else
        {
            elements[p]=temp;
            length++;
        }
    }
}
void LIST::Input2()
{
    int temp;
    cout<<"Please input the length of the list."<<endl;
    cin>>length;
    for (int p = 1; p <= length; p++)
    {
        cout<<"Please input some number. "<<endl;
        cin>>temp;
        elements[p]=temp;
    }
}
bool LIST::isEmpty()
{
    if (length==0)
    {
        return true;
    }
    else if (length>0)
    {
        return false;
    }
} 
void LIST::Delete(int p)
{
    if(!isEmpty())
    {
        if((p>length)||(p<1))
            cout<<"Position does not exist!"<<endl;
        else
        {
            length=length-1;
            for(int q=p;q<=length;q++)
                elements[q]=elements[q+1];
        }
    }
    else
    {
        cout<<"The list is empty!"<<endl;
    }
}
void LIST::PrintNumber()
{
    if (!isEmpty())
    {
            for (int p = 1; p <= length; p++)
            {
                cout<<"["<<elements[p]<<"]"<<' ';
            }
    }
    else
    {
        cout<<"The list is empty!"<<endl;
    }
}
void LIST::DeleteTheSame()
{
    for (int i = 1; i <= maxlength; i++)
    {
        for (int p = i+1; p < maxlength; p++)
        {
            if (elements[p]==elements[i])
            {
                Delete(p);
            }
        }
    }
}
void LIST::Split(LIST &LA,LIST &LB)
{
    for (int p = 1; p <= length; p++)
    {
        if (elements[p] > 0)
        {
            LA.length++;
            LA.elements[LA.length]=elements[p]; 
        }
        else
        {
            LB.length++;
            LB.elements[LB.length]=elements[p];
        }
    }
}

int main()
{
    LIST Q,A,B;
    Q.Creat();    
    A.Creat();
    B.Creat();
    //Q.Input();
    Q.Input2();
    //Q.Delete(3);
    //Q.DeleteTheSame();
    Q.Split(A,B);
    cout<<"A is ";
    A.PrintNumber();
    cout<<endl;
    cout<<"B is ";
    B.PrintNumber();
    cout<<endl;
}
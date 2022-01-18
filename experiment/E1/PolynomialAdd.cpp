#include<iostream>
using namespace std;
struct NODE
{
    int coef;
    int exp;
    NODE *next;
};
class Poly
{
private:
    NODE *head;
    int length;
public:
    void Creat();
    bool isEmpty();
    void Input();
    void PolyLink(Poly &A,Poly &B);
    void Delete(NODE *P);
    void PolyAdd();
    void Exchange(NODE *p, NODE *q);
    void Order();
    void PrintNumber();
};
void Poly::Creat()
{
    head=new NODE;
    head->next=NULL;
    head->coef=head->exp=0;
    length=0;
}
bool Poly::isEmpty()
{
    if (head->next==NULL)
    {
        return true;
    }
    else if (head->next!=NULL)
    {
        return false;
    }
    return true;
}
void Poly::Input()
{
    cout<<"How long is the Polynomial? "<<endl;
    cin>>length;
    NODE *temp;
    for (int i = 1; i <= length; i++)
    {
        temp=new NODE;
        cout<<"Coef"<<i<<"? "<<endl;
        cin>>temp->coef;
        cout<<"Exp"<<i<<"? "<<endl;
        cin>>temp->exp;
        temp->next=NULL;
        if(head->next==NULL)
        {
            head->next=temp;
        }
        else
        {
            NODE *p=head->next;
            while (p->next!=NULL)
            {
                p=p->next;
            }
            p->next=temp;
        }
    }
}
void Poly::PolyLink(Poly &A,Poly &B)
{
    if (!A.isEmpty())
    {
        if (!B.isEmpty())
        {
            NODE *p=A.head->next;
            NODE *pr;
            while (p!=NULL)
            {
                pr=new NODE;
                pr->coef=p->coef;
                pr->exp=p->exp;
                pr->next=NULL;
                if (head->next==NULL)
                {
                    head->next=pr;
                }
                else
                {
                    NODE *p1=head->next;
                    while (p1->next!=NULL)
                    {
                        p1=p1->next;
                    }
                    p1->next=pr;
                }
                p=p->next;
            }
            pr->next=B.head->next;
            length=A.length+B.length;
        }
    }
}
void Poly::Delete(NODE *P)
{
    if (P->next!=NULL)
    {
        NODE *temp=P->next;
        P->exp=temp->exp;
        P->coef=temp->coef;
        P->next=temp->next;
        //delete temp;
    }
    else
    {
        NODE *pre=head;
        while (pre->next!=P)
        {
            pre=pre->next;
        }
        pre->next=NULL;
        //delete P;
        P=pre;
    }
    length--;
}
void Poly::PolyAdd()
{
    if (!isEmpty())
    {
        NODE *p=head->next;
        while (p->next!=NULL)
        {
            NODE *flag2=p->next;
            while (flag2!=NULL)
            {
                if (p->exp==flag2->exp)
                {
                    if (flag2->next!=NULL)
                    {
                        p->coef=p->coef+flag2->coef;
                        Delete(flag2);
                    }
                    else
                    {
                        p->coef=p->coef+flag2->coef;
                        Delete(flag2);
                        break;
                    }   
                }
                else
                {
                    flag2=flag2->next;
                }
            }  
            p=p->next;         
        }
    }
    else
    {
        cout<<"The list is empty!"<<endl;
    }    
}
void Poly::Exchange (NODE *p, NODE*q)
{
    int tempexp,tempceof;
    tempexp=p->exp;
    tempceof=p->coef;
    p->coef=q->coef;
    p->exp=q->exp;
    q->coef=tempceof;
    q->exp=tempexp;
}
void Poly::Order()
{
    NODE *p=head->next;
    while (p->next!=NULL)
    {
        NODE *q=p->next;
        while (q!=NULL)
        {
            if (p->exp>q->exp)
            {
                Exchange(p,q);
            }
            else
            {
                q=q->next;
            }
        }
        p=p->next;
    }
}

void Poly::PrintNumber()
{
    NODE *p=head->next;
    while(p!=NULL)
    {

        if (p->coef!=0)
        {
            if (p->exp!=0)
            {
                if (p->exp==1)
                {
                    cout<<p->coef<<'x';
                }
                else
                {
                    cout<<p->coef<<'x'<<'^'<<p->exp;
                }    
            }
            else
            {
                cout<<p->coef;
            } 
        }
        if ((p->next!=NULL)&&(p->next->coef>0))
        {
            cout<<'+';
        }
        p=p->next;
    }
}

int main()
{
    Poly A,B,result;
    A.Creat();
    B.Creat();
    result.Creat();
    cout<<"Please input a."<<endl;
    A.Input();
    cout<<"Please input b."<<endl;
    B.Input();
    result.PolyLink(A,B);
    result.PolyAdd();
    //result.PrintNumber();
    //cout<<endl;
    //A.PrintNumber();
    //B.PrintNumber();
    result.Order();
    result.PrintNumber();
    return 0;
}
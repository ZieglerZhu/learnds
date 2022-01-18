#include<iostream>
using namespace std;
struct NODE
{
    int element;
    NODE *next;
};
class LIST2
{
private:
    NODE *head;
public:
    void Creat();
    bool isEmpty();
    void Input();
    void Delete(NODE *p);
    void DeleteTheSame();
    void PrintNumber();
};
void LIST2::Creat()
{
    head=new NODE;
    head->next=NULL;
    head->element=0;
}
bool LIST2::isEmpty()
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
void LIST2::Input()
{
    NODE *temp;
    int num;
    cout<<"Please input some number, end with 0. ";
    cin>>num;
    while(num!=0)
    {
        temp=new NODE;
        temp->element=num;
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
        cout<<"Please input some number, end with 0. ";
        cin>>num;
    }
}
void LIST2::Delete(NODE *P)
{
    if (P->next!=NULL)
    {
        NODE *temp=P->next;
        P->element=temp->element;
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
}
void LIST2::DeleteTheSame()
{
    if (!isEmpty())
    {
        NODE *p=head->next;
        while (p->next!=NULL)
        {
            NODE *flag2=p->next;
            while (flag2!=NULL)
            {
                if (p->element==flag2->element)
                {
                    if (flag2->next!=NULL)
                    {
                        Delete(flag2);
                    }
                    else
                    {
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
}//there is something wrong when list is 123123
void LIST2::PrintNumber()
{
    NODE *p=head->next;
    while(p!=NULL)
    {
        cout<<"["<<p->element<<"] ";
        p=p->next;
    }
}

int main()
{
    LIST2 Q;
    Q.Creat();
    Q.Input();
    Q.DeleteTheSame();
    Q.PrintNumber();
    return 0;
}
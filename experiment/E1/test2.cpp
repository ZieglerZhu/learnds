#include<iostream>
using namespace std;
struct NODE
{
    int element;
    NODE *next;
};
class Josephus
{
private:
    NODE *head;
    int num;
    int Start;
    int Out;
public:
    void Creat();
    void Input();
    void JOut();
};
void Josephus::Creat()
{
    head=new NODE;
    head->next=NULL;
    head->element=0;
}
void Josephus::Input()
{
    NODE *temp;
    NODE *p=head;
    cout<<"How many people? ";
    cin>>num;
    while (num<=0)
    {
        cout<<"ERROR, Please input again. "<<endl;
        cin>>num;
    }
    for (int i = 1; i <= num; i++)
    {
        temp = new NODE;
        temp->element = i;
        temp->next = NULL;
        if (head->next == NULL)
        {
            head->next = temp;
        }
        else
        {
            p->next=temp;  
        }
        p = temp;
    }
    p->next=head->next;
    head=head->next;

    cout<<"Where to start"<<endl;
	cin>>Start;
	while ((Start>num)||(Start<1))
	{
		cout<<"ERROR, Please input the number again."<<endl;
		cin>>Start;
	}

	cout<<"Which one need get out? "<<endl;
	cin>>Out;

}
void Josephus::JOut()
{
    int flag=1;
    NODE *p=head;
    for (int i = 1; i < Start; i++)
    {
        p=p->next;
    }
    while (num>1)
    {
        if (flag==Out-1)
        {
            NODE *temp=p->next;
            p->next=temp->next;
            cout<<'n'<<temp->element<<endl;
            flag=0;
            num--;
        }
        p=p->next; 
        flag++;
    }
    cout<<'n'<<p->element<<endl;
}
int main()
{
    Josephus Q;
    Q.Creat();
    Q.Input();
    Q.JOut();
    return 0;
}
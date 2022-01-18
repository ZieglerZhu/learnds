#include <iostream>
#define QueueSize 50
using namespace std;
class Queue
{
private:
    int rear;
    int front;
    int elements[QueueSize]; // can deal with 50 people at the same time
    int finish[500];         // can deal with 500 people a day
    int FinishRear;
    int counter;

public:
    void Creat();
    bool isEmpty();
    void EnQueue();
    int DeQueue();
    void GetNumber();
    void Deal();
    void PrintQueue();
    void EndWork();
};

void Queue::Creat()
{
    front = 0;
    rear = 0;
    counter = 0;
    FinishRear = 0;
}
bool Queue::isEmpty()
{
    if (rear == front)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Queue::EnQueue()
{
    if ((rear + 1) % QueueSize == front)
    {
        cout << "The queue is full! Please wait for a few minutes. " << endl;
    }
    else
    {
        counter++;
        elements[rear] = counter;
        rear = (rear + 1) % QueueSize;
    }
}
int Queue::DeQueue()
{
    if (isEmpty())
    {
        cout << "The queue is empty! " << endl;
        return -1;
    }
    else
    {
        int temp = elements[front];
        front = (front + 1) % QueueSize;
        return temp;
    }
}
void Queue::GetNumber()
{
    if (counter<500)
    {
        EnQueue();
        cout<<"Your Number is "<<counter<<endl;
        cout<<"There are "<<(rear-front+QueueSize-1)%QueueSize<<" people before you. "<<endl;
    }
    else
    {
        cout<<"We can not deal with more people today. "<<endl;
    }
}
void Queue::Deal()
{
    if (isEmpty())
    {
        cout<<"There is no poeple in queue. "<<endl;
    }
    else
    {
        int temp=DeQueue();
        cout<<"Is you turn now, "<<"No."<<temp<<endl;
        finish[FinishRear]=temp;
        FinishRear++;
    }
}
void Queue::PrintQueue()
{
    int pos;
    pos=front;
    if (!isEmpty())
    {
        while (pos != rear)
        {
            cout<<elements[pos]<<endl;
            pos=(pos+1)%QueueSize;
        }
    }
    else
    {
        cout<<"The queue is empty now! "<<endl;
    } 
}
void Queue::EndWork()
{
    if (!isEmpty())
    {
        cout<<"There are "<<endl;
        PrintQueue();
        cout<<"still in queue. "<<endl;
    }
    else
    {
        cout<<"There is no more people in queue"<<endl;
    }
    if (FinishRear>0)
    {
        cout<<"There are "<<endl;
        for (int i = 0; i < FinishRear; i++)
        {
            cout<<finish[i]<<endl;
        }
        cout<<"finished. "<<endl;
    }
    else
    {
        cout<<"There is no people finished today. "<<endl;
    }
}

int main()
{
    Queue Q;
    Q.Creat();
    int temp;
    cout<<"Please input a number. 1 means getting number. 2 means dealing. 3 means printing the queue. 4 means end the work."<<endl;
    cin>>temp;
    while (temp!=4)
    {
        switch (temp)
        {
        case 1:
            Q.GetNumber();
            break;
        case 2:
            Q.Deal();
            break;
        case 3:
            Q.PrintQueue();
            break;
        default:
            cout<<"ERROR, please input a number between 1~4. "<<endl;
            break;
        }
        cout<<"Please input a number. 1 means getting number. 2 means dealing. 3 means printing the queue. 4 means end the work."<<endl;
        cin>>temp;
    }
    Q.EndWork();
    return 0;
}
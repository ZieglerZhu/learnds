#include <iostream>
#include <string>
#define QueueSize 100
using namespace std;
class Queue
{
private:
    char elements[QueueSize];
    int rear;
    int front;

public:
    void Creat();
    bool isEmpty();
    void EnQueue();
    // void DeQueue();
    bool test();
    void Result();
};

void Queue::Creat()
{
    front = 0;
    rear = 0;
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
    if (rear == (QueueSize - 1))
    {
        cout << "The queue is full! " << endl;
    }
    else
    {
        cout << "Please input ther string, end with Enter. " << endl;
        gets(elements);
        while (elements[rear])
        {
            rear++;
        }
    }
}
bool Queue::test()
{
    bool flag = true;
    if ((rear % 2) != 0)
    {
        int i = 0, j = rear - 1;
        while (i != j)
        {
            if (elements[i] != elements[j])
            {
                flag = false;
                break;
            }
            i++, j--;
        }
    }
    else
    {
        int i = 0, j = rear - 1;
        while ((i - 1) != j)
        {
            if (elements[i] != elements[j])
            {
                flag = false;
                break;
            }
            i++, j--;
        }
    }
    return flag;
}
void Queue::Result()
{
    if (test())
    {
        cout << "Yes. " << endl;
    }
    else
    {
        cout << "No. " << endl;
    }
}

int main()
{
    Queue Q;
    Q.Creat();
    Q.EnQueue();
    Q.Result();
    return 0;
}
#include<iostream>
using namespace std;
struct Student
{
    int ID;
    float score;
};
class TestScore
{
private:
    Student *p;
    int amount;
public:
    TestScore();
    void Print(int length);
    void Print();
  
    void QuickSort(int start, int end);
    void QuickSort();
    void InsertSort();
    void SelectSort();

};

TestScore::TestScore()
{
    cout<<"How many student?"<<endl;
    cin>>amount;
    p=new Student[amount];
    for (int i = amount-1; i >= 0; i--)
    {
        p[amount-1-i].score=i;
        p[amount-1-i].ID=i*100;
    }
    
}
void TestScore::Print()
{
    Print(amount);
}
void TestScore::Print(int length)
{
    cout<<"ID\t\t"<<"Score\t\t"<<"Position"<<endl;
    for (int i = 0; i < length; i++)
    {
        cout<<p[i].ID<<"\t\t"<<p[i].score<<"\t\t"<<i+1<<endl;
    }
    cout<<endl;
}
void TestScore::QuickSort()
{
    QuickSort(0,amount-1);
}
void TestScore::QuickSort(int start,int end)
{
    if (start<end)
    {
        Student key=p[start];
        int s=start;
        int e=end;
        while (s<e)
        {
            while ((p[e].score>key.score)&&(e>s))
            {
                e--;
            }
            p[s]=p[e];
            while ((p[s].score<=key.score)&&(s<e))
            {
                s++;
            }
            p[e]=p[s];
        } 
        p[s]=key;
        QuickSort(start,s-1);
        QuickSort(s+1,end);
    }
    else
    {
        return;
    }
}
void TestScore::InsertSort()
{
    for (int j = 1; j < amount; j++)
    {
        Student key=p[j];
        int i = j-1;
        while (i>=0&&p[i].score>key.score)
        {
            p[i+1]=p[i];
            i--;
        }
        p[i+1]=key;
    }
}
void TestScore::SelectSort()
{
    int i,j,min;
    Student temp;
    for ( i = 0; i < amount-1; i++)
    {
        min=i;
        for ( j = i+1; j < amount; j++)
        {
            if (p[j].score<p[min].score)
            {
                min=j;
            }
        }
        if (min!=i)
        {
            temp=p[i];
            p[i]=p[min];
            p[min]=temp;
        }
    }
}


int main()
{
    TestScore T;
    T.Print();
    //T.QuickSort();
    //T.InsertSort();
    T.SelectSort();
    T.Print();
    return 0;
}
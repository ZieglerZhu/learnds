#include<iostream>
using namespace std;
int main()
{
    cout<<"Please input the grade"<<endl;
    int grade;
    cin>>grade;
    if (grade>=70)
    {
        if (grade>=80)
        {
            if (grade>=90)
            {
                cout<<"The grade is A"<<endl; 
            }
            else
            {
                cout<<"The grade is B"<<endl;
            }
        }
        else
        {
            cout<<"The grade is C"<<endl;
        }
    }
    else
    {
        if (grade<60)
        {
            cout<<"The grade is E"<<endl;
        }
        else
        {
            cout<<"The grade is D"<<endl;
        }
    }
}
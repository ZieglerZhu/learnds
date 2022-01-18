#include<iostream>
using namespace std;
int main()
{
    int grade;
    cout<<"please input the grade. "<<endl;
    cin>>grade;
    if ((grade>=80)&&(grade<=89))
    {
        cout<<"the level is B"<<endl;
    }
    else
    {
        if ((grade>=70)&&(grade<=79))
        {
            cout<<"the level is C"<<endl;
        }   
        else
        {
            if ((grade>=90)&&(grade<=100))
            {
                cout<<"the level is A"<<endl;
            }
            else
            {
                if ((grade>=60)&&(grade<=69))
                {
                    cout<<"the level is D"<<endl;
                }
                else
                {
                    cout<<"the level is E"<<endl;
                } 
            }   
        } 
    }
    return 0;
}
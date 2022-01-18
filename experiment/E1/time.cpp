#include<iostream>
#include<time.h>
using namespace std;
int main()
{
    clock_t start, stop;
    int i,N=100000,j;

    start=clock();
    int Sum = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            Sum++;
    }
    stop=clock();
    cout<<"time of program1 is "<<((stop-start)/CLK_TCK)<<'s'<<endl;

    start=clock();
    Sum = 0;
    for (i = 0; i < N; i++)
        Sum += i;
    stop=clock();
    cout<<"time of program2 is "<<((stop-start)/CLK_TCK)<<'s'<<endl;

    start=clock();
    Sum = 0;
    for (i = 0; i < N; i++)
        Sum++;
    stop=clock();
    cout<<"time of program3 is "<<((stop-start)/CLK_TCK)<<'s'<<endl;

    return 0;
}
#include<iostream>
using namespace std;
int count=0;
void Print(int a[],int length)
{
    for (int i = 0; i < length; i++)
    {
        cout<<"a["<<i<<"] is "<<a[i]<<endl;
    }
    cout<<endl;
}
int FindLarge(int A[],int key,int start,int end)
{
    int keyNo=0;
    for (int i = start; i <= end; i++)
        {
            if (A[i]>key)
            {
                keyNo=i;
                key=A[i];
            }
        }
        return keyNo;
}
void QuickSort(int A[], int start, int end)
{
    if (start<end)
    {
        int key=A[start];
        int s=start;
        int e=end;
        
        s=FindLarge(A,key,s,e);
        key=A[s];
        while (s<e)
        {
            while ((A[e]>key)&&(e>s))
            {
                e--;
            }
            A[s]=A[e];
            while ((A[s]<=key)&&(s<e))
            {
                s++;
            }
            A[e]=A[s];
        } 
        A[s]=key;
        count++;
        cout<<"This is No."<<count<<" Sort"<<endl;
        Print(A,8);
        QuickSort(A,start,s-1);
        QuickSort(A,s+1,end);
    }
    else
    {
        return;
    }   
}
void InsertSort(int A[],int length)
{
    
    for (int j = 1; j < length; j++)
    {
        int key=A[j];
        int i = j-1;
        while (i>=0&&A[i]>key)
        {
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=key;
    }
}
void SelectSort(int A[], int length)
{
    int i,j,min;
    int temp;
    for ( i = 0; i < length-1; i++)
    {
        min=i;
        for ( j = i+1; j < length; j++)
        {
            if (A[j]<A[min])
            {
                min=j;
            }
        }
        if (min!=i)
        {
            temp=A[i];
            A[i]=A[min];
            A[min]=temp;
        }
    }
}


void Merge(int data[],int start,int end,int result[]) 
{
    int LeftLength = (end - start + 1) / 2 + 1;    
    int LeftIndex = start;
    int RightIndex = start + LeftLength;
    int ResultIndex = start;
    while(LeftIndex<start + LeftLength && RightIndex <end + 1)  //store data into new array
    {
        if(data[LeftIndex] <= data[RightIndex])
            result[ResultIndex++] = data[LeftIndex++];
        else
            result[ResultIndex++] = data[RightIndex++];
    }
    while(LeftIndex < start + LeftLength)//left not finished
        result[ResultIndex++] = data[LeftIndex++];
    while(RightIndex <end+1)//right not finish
        result[ResultIndex++] = data[RightIndex++];
}
 
void MergeSort(int data[],int start,int end,int result[])
{
    if(1 == end - start)   //last only two elements
    {
        if(data[start] > data[end])
        {
            int temp = data[start];
            data[start] = data[end];
            data[end] = temp;
        }
        return;
    }
    else if (end == start)
        return; //last one element then there is no need to sort;
    else{
        //continue to divide the interval
        MergeSort(data, start, (end - start + 1) / 2 + start, result);
        MergeSort(data, (end - start + 1) / 2 + start + 1, end, result);
        //start to merge sorted data
        Merge(data, start, end, result);
        for (int i = start; i <= end;++i)
        {
            data[i] = result[i];
        }
    }
}

int main()
{
    int d[]={10,80,45,3,65,23,98,8};
    int c[]={3,8,10,23,45,65,80,98};
    int b[]={98,80,65,45,23,10,3,8};
    QuickSort(d,0,7);
    //InsertSort(d,8);
    //SelectSort(d,8);
    //int result[8];
    //MergeSort(d,0,7,result);
    cout<<"This is final result"<<endl;
    Print(d,8);
    return 0;
}
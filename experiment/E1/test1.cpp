#include<iostream>
#define maxlength 100
using namespace std;
class Josephus{
	private:
		int length;
		int *data;
		int Start;
		int Out;
	public:
		void Creat();
		void Input();
		bool isEmpty();
		void JOut();
		void PrintNumber();
};
void Josephus::Creat()
{
	data=new int[maxlength];
	length=0;
	data[0]=-1;
}
void Josephus::Input()
{	
	cout<<"How many people? "<<endl;
	cin>>length;
	while(length<0)
	{
		cout<<"ERROR, Please input the number again."<<endl;
		cin>>length;
	}
	for(int i=1;i<=length;i++)
	{
		//data[i+1]=data[i];
		data[i]=i;
	}
	cout<<"Where to start"<<endl;
	cin>>Start;
	while ((Start>length)||(Start<1))
	{
		cout<<"ERROR, Please input the number again."<<endl;
		cin>>Start;
	}
	cout<<"Which one need get out? "<<endl;
	cin>>Out;
}
bool Josephus::isEmpty()
{
	if (length==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Josephus::JOut()
{
	if (!isEmpty())
	{
		int flag=Start-1;
		while(length>=1)
		for (int i = length; i > 0; i--)
		{
			flag=(flag+Out)%i;
			if (flag==0)
			{
				flag=i;
			}
			
			cout<<'n'<<data[flag]<<endl;
			for (int j = flag; j < i; j++)
			{
				data[j]=data[j+1];
			}
			length--;
			flag--;
		}
		
	}
}
void Josephus::PrintNumber()
{
	for(int i=1;i<=length;i++)
	{
		cout<<"["<<data[i]<<"] "<<endl;
	}
}
int main()
{
	Josephus Q;
	Q.Creat();
	Q.Input();
	//Q.Delete(8);
	Q.JOut();
	Q.PrintNumber();
	return 0;
}
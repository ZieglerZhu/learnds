#include<iostream>
#include<string>
#include<cmath>
#include<string.h>
#include <iomanip>
#define noEdge 9999
#define sn 30
using namespace std;


//BusChain
struct BusNode
{
    string StationName;
    int dx;
    int dy;
    BusNode *next;
};

class BusChain
{
friend class BusRoute;
private:
    BusNode *FirstNode;
    int ListSize;//=num
public:
    BusChain()
    {
        FirstNode=NULL;
        ListSize=0;
    }
    ~BusChain();

    bool isEmpty(){return (ListSize == 0);}
    int GetSize(){return ListSize;}
    BusNode *GetFirstNode(){return FirstNode;}
    string GetFirstNodeName(){return FirstNode->StationName;}
    void Insert(string StationName,int x,int y);
    //void GetDistance();
    //void OutPut();
};

BusChain::~BusChain()
{  

}

void BusChain::Insert(string StationName,int x,int y)
{
    if (FirstNode==NULL)
    {
        FirstNode=new BusNode;
        FirstNode->StationName=StationName;
        FirstNode->next=NULL;
        FirstNode->dx=x;
        FirstNode->dy=y;
    }
    else
    {
        BusNode *p=FirstNode;
        while (p->next!=NULL)
        {
            p=p->next;
        }
        BusNode *pp=new BusNode;
        pp->StationName=StationName;
        pp->dx=x;
        pp->dy=y;
        pp->next=NULL;
        p->next=pp;
    }
    ListSize++;
}


//BusRoute (Only the information
class BusRoute
{
private:
    int num;//num of this BusRoute
    int sum;//how many station of this BusRoute
    int speed;
    int price;
    int time;//
    BusChain Link;
public:
    BusRoute();
    ~BusRoute();
    void InitRoute();
    int GetPrice() { return price; }
	int GetSpeed() { return speed; }
	int GetNum() { return num; }
	int GetSum() { return sum; }
	int GetTime_() { return time; }
	BusChain GetLink() { return Link; }
    void DispRoute(){cout<<"Price: "<<price<<" Time: "<<time<<" Speed: "<<speed<<endl;}
};

BusRoute::BusRoute()
{
    num=0;
    sum=0;
    speed=0;
    price=0;
    time=0;   
}

BusRoute::~BusRoute()
{
    cout<<"Destory BusRoute."<<endl;
    num=0;
    sum=0;
    speed=0;
    price=0;
    time=0;
}

void BusRoute::InitRoute()
{
    string name;
    int x,y;
    cout<<"What's the num of this route."<<endl;
    cin>>num;
    cout<<"How many stations in this route."<<endl;
    cin>>sum;
    for (int i = 1; i <= sum; i++)
    {
        cout<<"\tstation"<<i<<":";
        cout<<"\t\tWhat's the name of this station :";
        cin>>name;
        cout<<"\t\tWhat's the x of this station :";
        cin>>x;
        cout<<"\t\tWhat's the y of this station :";
        cin>>y;
        Link.Insert(name,x,y);
    }
    cout<<"What's the price of this route."<<endl;
    cin>>price;
    cout<<"How often the bus starts."<<endl;
    cin>>time;
    cout<<"How fast of this bus."<<endl;
    cin>>speed;
}

struct RouteInfo
{
    int Info;//num of route
    double data;//weight
};

struct var//there may be many busroute between two station
{
    RouteInfo ri[sn];//max route is 30
};

class AdjMatrix
{
private:
    var **theMatrix;
    int n;//node
    int m;//edge 
public:
    AdjMatrix(int Capacity);
    ~AdjMatrix();
    void insert(int i, int j, int nth, RouteInfo rt);
	void erase(int i, int j, int nth);
	int getElement(int i, int j, int nth);
	int getM() { return m; }
	void init();
	int search(int i, int j, int su);
	int search2(int i, int j, int su, BusRoute *bus);
	void Dijkstra(int *dis, int *pre, int da, int su);
	void outputPath(int pa, int pb, string *in, int *pre, int su);
	void Dijkstra2(int *dis, int *pre, int da, int su, BusRoute *bus);
	int find_(int Infomation, int su, BusRoute *bus);
};

AdjMatrix::AdjMatrix(int theCapacity)
{
    n = theCapacity - 1;
	theMatrix = new var *[theCapacity];
	for (int i = 0; i<theCapacity; i++) {
		theMatrix[i] = new var[theCapacity];
	}//30*30
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= sn; k++) {
				theMatrix[i][j].ri[k].data = noEdge;
                theMatrix[i][j].ri[k].Info = 0;
			}
		}
	}//(0,0)?
	m = 0;
}
AdjMatrix::~AdjMatrix() 
{
    cout<<"Destroy the AdjMatrix."<<endl;
	for (int i = 0; i<n; i++) 
    {
		delete[] theMatrix[i];
	}
	delete[] theMatrix;
	m = 0;
	n = 0;
}

void AdjMatrix::init() 
{
	for (int i = 1; i <= n; i++) 
    {
		for (int j = 1; j <= n; j++) 
        {
			for (int k = 1; k <= sn; k++) 
            {
				theMatrix[i][j].ri[k].data = noEdge;
				theMatrix[i][j].ri[k].Info = 0;
			}
		}
	}
}

void AdjMatrix::insert(int i, int j, int nth, RouteInfo rt) {
	if (theMatrix[i][j].ri[nth].data == noEdge) {
		theMatrix[i][j].ri[nth] = rt;
		m++;
	}
	else {
		theMatrix[i][j].ri[nth] = rt;
	}
 
}
 
void AdjMatrix::erase(int i, int j, int nth) {
	if (theMatrix[i][j].ri[nth].data == noEdge) {
		cout << "Error!There is noedge here." << endl;
	}
	else {
		theMatrix[i][j].ri[nth].data = noEdge;
		m--;
	}
}
 
int AdjMatrix::getElement(int i, int j, int nth) 
{
	return theMatrix[i][j].ri[nth].data;
}
 
void AdjMatrix::Dijkstra(int *dis, int *pre, int da,int su)
{
    int *visited=new int[30];
    for (int i = 0; i <= n; i++)
    {
        visited[i]=0;
    }
    for (int i = 1; i <= 26; i++)
    {
        dis[i]=theMatrix[da][i].ri[search(da,i,su)].data;
        if (dis[i]==noEdge)
        {
            pre[i]=0;
        }
        else
        {
            pre[i]=da;
        }        
    }
    dis[da]=0;
    visited[da]=1;
    for (int i = 1; i <= 25; i++)
    {
        int temp=noEdge;
        int v=0;
        for (int j = 1; j <= 26; j++) 
        { 
			if (visited[j]==0 && dis[j]<temp) 
            {
				v = j;
				temp = dis[j];
			}
		}
        visited[v]=1;
        for (int j = 1; j <= 26; j++) 
        {
			if (visited[j] == 0 && theMatrix[v][j].ri[search(v, j, su)].data<noEdge) 
            {
				int dd = dis[v] + theMatrix[v][j].ri[search(v, j, su)].data;
				if (dd<dis[j]) 
                {
					dis[j] = dd;
					pre[j] = v;
				}
			}
		}
    }
}
void AdjMatrix::Dijkstra2(int *dis, int *pre, int da, int su, BusRoute *bus) {
	int *visited = new int[30];
	for (int i = 1; i <= n; i++) 
    {
		visited[i] = 0;
	}
	for (int i = 1; i <= 26; i++) 
    {
		dis[i] = theMatrix[da][i].ri[search(da, i, su)].data;
		if (dis[i] == noEdge)
			pre[i] = 0;
		else
			pre[i] = da;
	}
	dis[da] = 0;
	visited[da] = 1;
	int tt = 1;
	for (int i = 1; i <= 26; i++) 
    {
		int temp = noEdge;
		int v = 0;
		for (int j = 1; j <= 26; j++) 
        {
			if (visited[j] == 0 && dis[j]<temp) 
            {
				v = j;
				temp = dis[j];
			}
		}
		visited[v] = 1;
		int oldInfo;
		if (tt == 1) {
			oldInfo = theMatrix[da][v].ri[search(da, v, su)].Info;
		}
		tt = 2;
		for (int j = 1; j <= 26; j++) {
			if (oldInfo == theMatrix[v][j].ri[search2(v, j, su, bus)].Info) 
            {
				if (visited[j] == 0 && theMatrix[v][j].ri[search2(v, j, su, bus)].data < noEdge) 
                { 
					int dd = dis[v] + theMatrix[v][j].ri[search2(v, j, su, bus)].data;
					if (dd < dis[j]) 
                    {
						dis[j] = dd;
						pre[j] = v;
					}
				}
			}
			else {
				if (visited[j] == 0 && (theMatrix[v][j].ri[search2(v, j, su,bus)].data+find_(theMatrix[v][j].ri[search2(v, j, su, bus)].Info,su,bus))<noEdge) 
                {
					int dd = dis[v] + theMatrix[v][j].ri[search2(v, j, su,bus)].data+find_(theMatrix[v][j].ri[search2(v, j, su, bus)].Info, su, bus);
					if (dd<dis[j]) 
                    {
						dis[j] = dd;
						pre[j] = v;
					}
					oldInfo = theMatrix[v][j].ri[search2(v, j, su, bus)].Info;
				}
			}
		}
	}
}

int AdjMatrix::search(int i, int j, int su) 
{
	int qq = theMatrix[i][j].ri[1].data;
	int uu = 1;
	for (int k = 2; k <= su; k++) 
    {
		if (theMatrix[i][j].ri[k].data<qq) 
        {
			qq = theMatrix[i][j].ri[k].data;
			uu = k;
		}
	}
	return uu;
}
int AdjMatrix::search2(int i, int j, int su,BusRoute *bus) 
{
	int qq = theMatrix[i][j].ri[1].data+find_(theMatrix[i][j].ri[1].Info,su,bus);
	int uu = 1;
	for (int k = 2; k <= su; k++) 
    {
		if (theMatrix[i][j].ri[k].data + find_(theMatrix[i][j].ri[k].Info, su, bus)<qq) 
        {
			qq = theMatrix[i][j].ri[k].data+find_(theMatrix[i][j].ri[k].Info,su,bus);
			uu = k;
		}
	}
	return uu;
}

int AdjMatrix::find_(int Information, int su, BusRoute *bus) 
{ 
	if (Information == 0)
		return 0;
	for (int i = 1; i<=su; i++) {
		if (bus[i].GetNum() == Information)
			return bus[i].GetTime_();
	}
}
void AdjMatrix::outputPath(int pa, int pb, string *in, int *pre, int su) {
	if (pa == pb)
		return;
	int temp[sn];
	int co = 1;
	temp[co] = pb;
	co++;
	int te = pre[pb];
	while (te != pa) 
    {
		temp[co] = te;
		co++;
		te = pre[te];
	}
	temp[co] = pa;
	int info = theMatrix[temp[co]][temp[co - 1]].ri[search(temp[co], temp[co - 1], su)].Info;
	cout << "Route" << info << ":";
 
	for (int i = co; i >= 1; i--) 
    {
		if (i != 1) 
        {
			if (theMatrix[temp[i]][temp[i - 1]].ri[search(temp[i], temp[i - 1], su)].Info != info) {
				cout << "Station" << in[temp[i]] << ". ";
				cout << "Change Route " << theMatrix[temp[i]][temp[i - 1]].ri[search(temp[i], temp[i - 1], su)].Info << ":";
				cout << " Station" << in[temp[i]] << ", ";
			}
			else 
            {
				cout << " Station" << in[temp[i]] << ", ";
			}
			info = theMatrix[temp[i]][temp[i - 1]].ri[search(temp[i], temp[i - 1], su)].Info;			
		}
		else 
        {
			cout << " Station " << in[temp[i]] << ". " << endl;
		}
	}
}


void Welcome();
void Input();
void Menu();
void GetRoutes();
int choose();
void Function();
void findMinCost();
void findMinTime1();
void findMinTime2();
int getIndex(string bs);


int option;
char flag = 'y';
BusRoute *bus = new BusRoute[10];
int BUS_SUM;
string in[sn] = { " ","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"," "," "," " };
int vis[sn];
int	pre[sn];
int dis[sn];
AdjMatrix matrix(30);

int main() 
{
	Welcome();
	Input();
	GetRoutes();
	return 0;
}

void Welcome() {
	cout << "\n\n";
	cout << "\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\t\n";
	cout << "\t*\t\t\t\t\t\t\t\t*\n";
	cout << "\t*\t\tWelcome to the bus research system\t\t*\n";
	cout << "\t*\t\t\t\t\t\t\t\t*\n";
	cout << "\t*\t\t(There are station A-Z)\t\t\t\t*\n";
	cout << "\t*\t\t\t\t\t\t\t\t*\n";
	cout << "\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\t\n";
	cout << endl << endl;
	cout << "=------------------------------------------------------------------------------=\n";
}

void Input() {
	cout << "How many bus route:";
	cin >> BUS_SUM;
	for (int i = 1; i <= BUS_SUM; i++) 
    {
		bus[i].InitRoute();
	}
}

void GetRoutes() {
	cout << endl;
	cout << "=------------------------------------------------------------------------------=\n";
	cout << "The bus route created:" << endl;
	for (int i = 1; i <= BUS_SUM; i++) {
		bus[i].DispRoute();
	}
	cout << "=------------------------------------------------------------------------------=\n";
	cout << "Is there anything wrong? (y/n)";
	char aaa;
	cin >> aaa;
	cout << endl;
	if (aaa == 'y') {
		Menu();
		return;
	}
	else {
		cout << "Please input the bus route again." << endl;
		for (int i = 1; i <= BUS_SUM; i++) {
			cout << "cpp " << i << endl;
			bus[i].GetLink().~BusChain();
		}
		cout << "=------------------------------------------------------------------------------=\n";
		Input();
		GetRoutes();
	}
}

void Menu() 
{
	while (flag == 'y') 
	{
		cout << "\n\n";
		cout << "\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\t\n";
		cout << "\t*\t\t\t\t\t\t\t\t*\n";
		cout << "\t*\t\tMenu\t\t\t*\n";
		cout << "\t* _____________________________________________________________ *\t\n";
		cout << "\t* ------------------------------------------------------------- *\t\n";
		cout << "\t*\t\t\t\t\t\t\t\t*\n";
		cout << "\t*\t\t\t\t\t\t\t\t*\n";
		cout << "\t* \tInput a number below\t*\n";
		cout << "\t* ------------------------------------------------------------- *\t\n";
		cout << "\t*\t\t\t\t\t\t\t\t*\n";
		cout << "\t*\t\t 1-less cost\t\t\t*\t\n";
		cout << "\t*\t\t\t\t\t\t\t\t*\n";
		cout << "\t*\t\t 2-less time without waiting\t*\t\n";
		cout << "\t*\t\t\t\t\t\t\t\t*\n";
		cout << "\t*\t\t 3-less time with waiting\t*\t\n";
		cout << "\t*\t\t\t\t\t\t\t\t*\n";
		cout << "\t*\t\t 4-out\t\t\t\t\t*\t\n";
		cout << "\t*\t\t\t\t\t\t\t\t*\n";
		cout << "\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\t\n";
		cout << endl << endl;
		Function();//选择功能 
	} 
}

void Function() {
	cout << "=------------------------------------------------------------------------------=\n";
	cout << "\tyour choose?";
	cin >> option;
	cout << "=------------------------------------------------------------------------------=\n";
 
	if (option == 1)
		findMinCost();//查找最少花费 
	else if (option == 2)
		findMinTime1();//查找最少时间（不考虑等待时间） 
	else if(option==3)
		findMinTime2();//查找最少时间（考虑等待时间）
	else if(option==4) {
		cout<<"\thave out"<<endl;
		flag='n';
		return;//返回，结束
	}
	else {
		cout << "\twrong order\n\n\n";
		cout << "___________________________________________________________________________________\n";
		cout << "-----------------------------------------------------------------------------------\n\n";
		Menu(); 
	}//错误情况-容错性？
 
}
 
//查找最少花费 
void findMinCost() {
	cout << "Function1" << endl;
	cout << "=------------------------------------------------------------------------------=\n";
	matrix.init();
	RouteInfo rI;
	//建立票价邻接矩阵 
	for (int i = 1; i <= BUS_SUM; i++) {
		rI.Info = bus[i].GetNum();
		rI.data = bus[i].GetPrice();
		BusNode *p = bus[i].GetLink().GetFirstNode();
		for (p; p != NULL; p = p->next) {
			BusNode *pp = p->next;
			int ta = getIndex(p->StationName);
			for (pp; pp != NULL; pp = pp->next) {
				int tb = getIndex(pp->StationName);
				matrix.insert(ta, tb, i, rI);
				matrix.insert(tb, ta, i, rI);
			}
		}
	}
 
	string sa, sb;
	cout << "start?";
	cin >> sa ;
	cout<<endl;
	cout<<"end? ";
	cin>>sb;
	cout<<endl;
	matrix.Dijkstra(dis, pre, getIndex(sa), BUS_SUM);
	if (dis[getIndex(sb)] == noEdge) {
		cout << "can't go frome" << sa << "to" << sb  << endl;
		cout << "=------------------------------------------------------------------------------=\n";
	}
	else {
		matrix.outputPath(getIndex(sa), getIndex(sb), in, pre, BUS_SUM);
		cout << "total cost " << setiosflags(ios::fixed) << setprecision(0) << dis[getIndex(sb)] << " yuan. " << endl << endl;
	}
	cout << "=------------------------------------------------------------------------------=\n";
 
	return;
}
 
void findMinTime1() {
	cout << "Function2" << endl;
	cout << "=------------------------------------------------------------------------------=\n";
	matrix.init();
	RouteInfo rI;
	for (int i = 1; i<=BUS_SUM; i++) {
		rI.Info = bus[i].GetNum();
		BusNode *p = bus[i].GetLink().GetFirstNode();
		for (p; p != NULL; p = p->next) {
			BusNode *pp = p->next;
			int ta = getIndex(p->StationName);
			if (pp != NULL) {
				int ddis = p->dx;
				rI.data = ddis / bus[i].GetSpeed();//时间 
				int tb = getIndex(pp->StationName);
				matrix.insert(ta, tb, i, rI);
				matrix.insert(tb, ta, i, rI);
			}
		}
	}
 
	string sa, sb;
	cout << "start?";
	cin >> sa ;
	cout<<endl;
	cout<<"end? ";
	cin>>sb;
	cout<<endl;
 
	matrix.Dijkstra(dis, pre,getIndex(sa), BUS_SUM);
	if (dis[getIndex(sb)] == noEdge) {
		cout << "can't go from" << sa << "to" << sb << endl;
		cout << "=------------------------------------------------------------------------------=\n";
	}
	else {
		matrix.outputPath(getIndex(sa), getIndex(sb), in, pre, BUS_SUM);
		//outputPath(getIndex(sa),getIndex(sb));
		cout << "total cost" << setiosflags(ios::fixed) << setprecision(2) << dis[getIndex(sb)] << "mins. " << endl << endl;
	}
	cout << "=------------------------------------------------------------------------------=\n";
	return;
}
 
//查找最少时间（考虑等待时间）
void findMinTime2() {
	cout<<"Function3"<<endl;
	cout<<"=------------------------------------------------------------------------------=\n";
	matrix.init();//初始化
	RouteInfo rI;
	for(int i=1;i<=BUS_SUM;i++) {
		rI.Info=bus[i].GetNum();
		BusNode *p=bus[i].GetLink().GetFirstNode();
		for(p;p!=NULL;p=p->next) {
			BusNode *pp=p->next;
			int ta=getIndex(p->StationName);
			if(pp!=NULL) {
				int ddis=p->dx;
				rI.data=ddis/bus[i].GetSpeed();
				int tb=getIndex(pp->StationName);
				matrix.insert(ta, tb, i, rI);
				matrix.insert(tb, ta, i, rI);
			}
		}
	}
 
	string sa,sb;
	cout << "start?";
	cin >> sa ;
	cout<<endl;
	cout<<"end? ";
	cin>>sb;
	cout<<endl;
 
	matrix.Dijkstra2(dis,pre,getIndex(sa),BUS_SUM,bus);
	if(dis[getIndex(sb)]==noEdge) {
		cout<<"can't go from"<<sa<<"to"<<sb<<"！"<<endl;
		cout<<"=------------------------------------------------------------------------------=\n";
	} else {
		matrix.outputPath(getIndex(sa),getIndex(sb),in,pre,BUS_SUM);
		cout<<"total cost"<<setiosflags(ios::fixed)<<setprecision(2)<<dis[getIndex(sb)]<<"mins. "<<endl<<endl;
	}
	cout<<"=------------------------------------------------------------------------------=\n";
	return;
}
 
//得到各站点索引 
int getIndex(string bs) {
	for (int i = 1; i <= 26; i++) {
		if (in[i] == bs)
			return i;
	}
	return -1;
}
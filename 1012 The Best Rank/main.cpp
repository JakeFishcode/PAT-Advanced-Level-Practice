#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool myfunction(int i,int j) {return (i>j);}
char NO[4]={'C','M','E','A'};
struct Student
{
    long ID;
    int grade[4];
    int rank[4];
};
int find_min(int arr[])//优先级的调整问题
{
	int num=0;
	for(int i=0;i<4;i++)
	{
		if(arr[num]>arr[i])
			num=i;
	}
	if(num==0&&arr[0]==arr[3])
	{
		num=3;
	}
	return num;
}
Student M[2000];
Student N[2000];

int sort_give_rank(int num[],int N,int rank[])
{

    vector<int> myvector(num,num+N);

    sort(myvector.begin(),myvector.end(),myfunction);

    for(int j=0;j<N;j++) 
        for(int i=0;i<N;i++)
        	{
        		if(myvector[j]==myvector[j-1]) break;
				else
				{
					if(myvector[j]==num[i])
						rank[i]=j+1;
				}
			}			
}
int Date_change(int n,int num)
{
    int temp[n],rank[n];

    for(int i=0;i<n;i++)
        temp[i]=N[i].grade[num];
    sort_give_rank(temp,n,rank);

    for(int i=0;i<n;i++)
		N[i].rank[num]=rank[i];

}
int give_avg(int n)
{
	for(int i=0;i<n;i++)
	{
		N[i].grade[3]=(N[i].grade[0]+N[i].grade[1]+N[i].grade[2])/4;
	}
}
int find_i(int n,int j)
{
	int i=0;
	for(i=0;i<n;i++)
		if(M[j].ID==N[i].ID)
			return i;
	return n+1;
}
int main()
{
    int n,m,k,e;
    cin >> n >> m;
    for(int i=0;i<n;i++)
	   	cin >> N[i].ID >> N[i].grade[0] >> N[i].grade[1] >> N[i].grade[2];
	for(int i=0;i<m;i++) 
	   	cin >> M[i].ID;
	give_avg(n);
    Date_change(n,0);
    Date_change(n,1);
    Date_change(n,2);
    Date_change(n,3);
    for(int j=0;j<m;j++)
    {
    	e=find_i(n,j);

		if(e!=n+1)
    	{
			k=find_min(N[e].rank);
			cout << N[e].rank[k] <<" "<<NO[k]<<endl;
		}
		else
			cout <<"N/A"<<endl;
	}
    return 0;
}

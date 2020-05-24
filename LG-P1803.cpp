#include<bits/stdc++.h>//想用深搜没时间 
using namespace std; 
int n,m,a[10000000],x,sum,s;//所以做不出=_= 
int main()//捞分程序 
{
	cin>>x;
	for(int i=1;i<=x;i++)
	{
		cout<<"x";
		cin>>n>>m;
		a[n]=1;
		a[m]=2;
	}
	for(int i=1;i<=x;i++)
	{
		if(a[i]==1&&s==0)
			s++;
		if(s==1&&a[i]==2)
		{
			s--;
			sum++;
		}
	}
	cout<<sum;
}

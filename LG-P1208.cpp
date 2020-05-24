#include<bits/stdc++.h> 
using namespace std;
int x[10000000],y[10000000];
int n,m,a;
int main()
{
	int i,j,t,sum=0;
	double sum1=0;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>x[i]>>y[i];
	}
	cout<<"a";
	for(i=1;i<=m;i++)
		for(j=i+1;j<=m;j++)
			if((x[i]/y[i])>(x[j]/y[j]))
			{
				t=x[i];
				x[i]=x[j];
				x[j]=t;
				t=y[i];
				y[i]=y[j];
				y[j]=t;
			}
	cout<<"c";
	for(i=1;i<=m;i++)
	{
		a=y[i];cout<<"x";
		for(j=1;j<=a;j++)
		{
			if(sum==n)
			{
				cout<<sum1;
				return 0;
			}
			sum+=1;
			sum1+=x[i]/y[i];
		}
	}
}

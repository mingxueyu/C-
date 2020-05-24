#include<bits/stdc++.h>
using namespace std;
int x[100000],y[100000];
int b[10];
int main()
{
	int i,j,n,m,s=0,s1=0;
	int k1;
	while(cin>>b[i])
	{
		if(b[i]%2==0)
		{
			s++;
			x[s]=b[i];
		}
		if(b[i]%2!=0)
		{
			s1++;
			y[s1]=b[i];
		}	
	}	
	for(i=1;i<=s;i++)
	{
		for(j=i+1;j<=s;j++)
		{	
		//	cout<<"x[j]"<<x[j]<<"x[i]"<<x[i]<<endl;
			if(x[j]<x[i])
			{
				k1=x[i];
				x[i]=x[j];
				x[j]=k1;
			}	
		}
	}	
	for(i=1;i<=s1;i++)
		for(j=i+1;j<=s1;j++)
		{
			//cout<<"y[j]"<<y[j]<<"y[i]"<<y[i]<<endl;
			if(y[j]>y[i])
			{
				k1=y[i];
				y[i]=y[j];
				y[j]=k1;
			}	
		}
	for(i=1;i<=s1;i++)
	{
		cout<<y[i]<<" "<<endl;
	}
	for(i=1;i<=s;i++)
		cout<<x[i]<<" "<<endl;
} 

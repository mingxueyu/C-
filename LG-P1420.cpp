#include<bits/stdc++.h>
using namespace std;
int a[50000],x[50000];
int main()
{
	long long i,j,n,m=0,k=0,s=1,m1=0;
	cin>>n;
	if(n==0)
	{
		cout<<"0";
		return 0;
	}
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
	{
		if(a[i]-1==a[i-1])
		{
			s++;
		}	
		else
		{
			if(s>m)
				m1=s;
			else
				m1=m;
			s=1;
		}
	}
	cout<<m1;
}

#include<bits/stdc++.h>
using namespace std;
int a[1000000],sum,n,m,x;
int main()
{
	int i;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=2;i<n;i++)
	{
		if(a[i+1]-a[i-1]<=m&&a[i+1]!=-1&&a[i-1]!=-1)
		{
			a[i]=-1;
			x++;
		}
	}
	cout<<x;
} 

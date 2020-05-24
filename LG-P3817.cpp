#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000],sum;
int main()
{
	int i;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
	{
		if(a[i]+a[i+1]>=m)
		{
			sum+=a[i+1]-m+a[i];;
			a[i+1]=m-a[i];	
		}	
	}	
	cout<<sum;
} 

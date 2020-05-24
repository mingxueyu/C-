#include<bits/stdc++.h>
using namespace std;
int a[1500];
int main()
{
	int n,i,x,s=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		a[x]++;
	}
	if(n%2!=0)
	{
		n=n/2+1;
	}
	for(i=1;i<=1500;i++)
	{
		if(a[i]>=n)
		{
			cout<<i;
			return 0;
		}	
		
	}
}
 

#include<bits/stdc++.h>
using namespace std;
int a[15];
int main()
{
	int i,j,n,m,k,x;
	cin>>n>>m;
	for(i=n;i<=m;i++)
	{
		k=i;
		while(k!=0)
		{
			x=k%10;
			k/=10;
			a[x]++; 
		}
	}
	for(i=0;i<=9;i++)
	{
		cout<<a[i]<<" ";
	}
}

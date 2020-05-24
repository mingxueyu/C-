#include<bits/stdc++.h>
using namespace std;
int a[1000000],sum;
int main()
{
	long long i,n,m,x=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}	
	for(i=1;i<=n;i++)
	{
		if(a[i]+a[i-1]<=m)
		{
			a[i]+=a[i-1];
		}
		else if(a[i]+a[i-1]>m)
			 {
			//cout<<ai<<endl;
				x++;		
		   	 }
	}
 	cout<<x+1;
} 

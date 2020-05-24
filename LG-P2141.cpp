#include<bits/stdc++.h>
using namespace std;
int n,m,ans,sum;
int a[1000000],t[1000000];
int main()
{   
	int i,j,k;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		t[a[i]]=-1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(t[a[i]+a[j]]==-1)
			{
				t[a[i]+a[j]]=1;
				ans++;	
			}	
		}	
	}	
	cout<<ans;
}

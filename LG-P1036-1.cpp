#include<bits/stdc++.h>
using namespace std;
int k,n,ans;
int a[10000000],t[10000000];
int zs(int x)
{
	int i; 
	for(i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return 0;
	return 1;
}
void dfs(int k1,int sum,int k2)
{
	if(k1==k)
	{
		if(zs(sum)==1)
		{
			ans++;
			cout<<sum<<endl;
		}			
		return;
	}
	for(int i=k2;i<=n;i++)
		if(t[i]==0)
		{
			t[i]=1;
			dfs(k1+1,sum+a[i],k2+1);
			t[i]=0;
		}
	return;
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(0,0,1);
	cout<<ans;
}


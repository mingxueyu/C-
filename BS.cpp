#include<bits/stdc++.h>
using namespace std;
int minn=2147483647;
int a[1000000];
void dfs(int s,int x)
{
	if(s<minn)
	{
		minn=s;
		s=0;
		return;
	}
	if(a[x+1]>=a[x]+1)
	{
		s+=a[x+1];
		x++;
		dfs(s,x);
		x--;
		s-=a[x+1];
	}
	if((a[x+1]-a[x])==(a[x]-a[x-1]))
	{
		s+=a[x-1];
		x--;
		dfs(s,x);
		x++;
		s-=a[x-1];
	}
}
int main()
{
	int n,i,s=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		s+=a[i];
	}
	 dfs(s,1);
	 cout<<minn;
}


#include<bits/stdc++.h>
using namespace std;
//pirority_queue<int,vector<int>,greater<int> >w;
int t[100000];
int a[100000];
int s,n,m;
int zs(int x)
{
    for(int i=2;i<=sqrt(x);i++)
        if(x%i==0)
            return 0;
    return 1;	
}
void dfs(int len,int ans,int k)
{
	int i,j;
	if(len==m)
	{
		if(zs(ans)==1)
			s++;
		return;
	}
	for(i=k;i<=n;i++)
	{
		if(t[i]==0)
		{
			cout<<i<<" ";
			t[i]=1;
			dfs(len+1,ans+a[i],i+1);
			t[i]=0;
		}
	}
	cout<<endl;
	return;
}
int main()
{
	int i;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	dfs(0,0,1);
	cout<<s;
}

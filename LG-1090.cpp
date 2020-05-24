#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> >x;
int n,m,ans,a,t;
int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		x.push(a);
	}
	for(i=1;i<n;i++)
	{
		t=x.top();
		x.pop();
		ans+=t+x.top();
		t+=x.top();
		x.pop();
		x.push(t);
	}
	cout<<ans;
}

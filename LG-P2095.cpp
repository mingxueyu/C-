#include<bits/stdc++.h>
using namespace std;
struct zrk
{
	int a,b;//脂肪,类别 
};
zrk x[100000];
int e[100000];//第i种可以吃几份 
int n,m,t,sum; 
bool cmp(zrk k1,zrk k2)
{
	return k1.a>k2.a;
}
int main()
{
	int i,j;
	cin>>n>>m>>t;
	for(i=1;i<=t;i++)
		cin>>e[i];
	for(i=1;i<=n;i++)
		cin>>x[i].a>>x[i].b;
	sort(x+1,x+n+1,cmp);
	for(i=1;i<=n;i++)
	{
		if(e[x[i].b]>0&&m>0)
		{
			e[x[i].b]--;
			m--;
			sum+=x[i].a;
		}
	}
	cout<<sum;
}

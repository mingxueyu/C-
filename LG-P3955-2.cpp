#include<bits/stdc++.h>
using namespace std;
int n,m;
int x[10000005];
int len;
int a;
bool cmp(int k1,int k2)
{
	if(k1>k2)
		return k1<k2;
}
int main()
{
	int i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>x[i];
	sort(x+1,x+n+1,cmp);
	for(i=1;i<=m;i++)
	{
		int s=1,k=0;
		cin>>len>>a;
		for(j=1;j<=len;j++)
			s*=10;
		for(j=1;j<=n;j++)
			if(x[j]%s==a%s)
			{
				k=1;
				cout<<x[j]<<endl;
				break;
			}
		if(k==0)
			cout<<"-1"<<endl;
	}
}

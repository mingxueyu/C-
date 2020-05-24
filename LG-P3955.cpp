#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int n,m,x,y,l,t=1;
bool cmp(int k1,int k2)
{
	return k1<k2;
}
int main()
{
	int i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		l=0;
		t=1;
		for(j=1;j<=x;j++)
			t*=10;
		for(k=1;k<=n;k++)
		{
			if((a[k]%t)==(y%t))
			{
				l=1;
				cout<<a[k]<<endl;
				break;
			}
		}
		if(l==0)
			cout<<"-1"<<endl;
	}
}

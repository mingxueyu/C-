#include<bits/stdc++.h>
using namespace std;
int t[1500][1500];
int sum,s,x,y,xx,yy,n,m,v;
int main()
{
	int i,j,k;
	cin>>n>>m>>v;
	for(i=1;i<=v;i++)
	{
		cin>>x>>y>>xx>>yy;
		for(j=x;j<=xx;j++)
			for(k=y;k<=yy;k++)
			{
				if(t[j][k]==0)
				{
					sum++;
					t[j][k]=-1;
				}
			}
	}
	cout<<sum;
}

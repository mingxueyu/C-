#include<bits/stdc++.h> 
using namespace std;
int s[10000000],a[10000000];
int sum,n,m,j,i,x,y;
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		s[i]=1;
	}
	for(i=1;i<=m;i++)
	{
		int t,x,y;
		cin>>t>>x>>y;
		for(j=x;j<=y;j++)
		{
			if(t==0)
			{
				if(s[j]==1)
				{
					s[j]=0;
//					cout<<"x"<<endl;
					if(a[j]==1)
					{
						a[j]++;
					}
				}
			}
			if(t==1)
			{
//				cout<<"s[j]="<<s[j]<<endl;
				if(s[j]==0)
				{
//					cout<<"y";
					s[j]=1;
					a[j]++;
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]==2)
			x++;
		if(a[i]==1)
			y++;
	}
	cout<<y<<endl<<x;
}

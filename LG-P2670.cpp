#include<bits/stdc++.h>
using namespace std;
char x[2500][2500];
int n,m;
int main()
{
	int i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>x[i][j];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(x[i][j]=='?')
			{
				x[i][j]='0';
				if(x[i+1][j]=='*')
					x[i][j]++;
				if(x[i][j+1]=='*')
					x[i][j]++;
				if(x[i-1][j]=='*')
					x[i][j]++;
				if(x[i][j-1]=='*')
					x[i][j]++;
				if(x[i+1][j+1]=='*')
					x[i][j]++;
				if(x[i-1][j-1]=='*')
					x[i][j]++;
				if(x[i+1][j-1]=='*')
					x[i][j]++;
				if(x[i-1][j+1]=='*')
					x[i][j]++;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			cout<<x[i][j];
		cout<<endl;
	}
}

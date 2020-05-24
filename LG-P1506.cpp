#include<bits/stdc++.h>
using namespace std;
char a[7000][7000];
int n,m,sum=0;
char o;
void zrk(int x,int y)
{
	if(x<0||y<0||x>n+1||y>m+1||a[x][y]!=0)
		return;
	a[x][y]=2;
	zrk(x-1,y);
	zrk(x,y-1);
	zrk(x+1,y);
	zrk(x,y+1);	
}
int main()
{
	int i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>o;
			if(o=='0')
				a[i][j]=0;
			else
				a[i][j]=1;
		}		
	}
	zrk(0,0);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j]==0)
			{
				sum++;
			}
		}		
	}
	cout<<sum;
}

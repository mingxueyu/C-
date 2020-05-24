#include<bits/stdc++.h>
using namespace std;
char m[100]={'h','e','h','r'},a[500][500];
int xx[100]={-1,1,0,0};
int yy[100]={0,0,-1,1};
int x1[600][600];
int n,sum1=0;
int zrk(int x,int y,int k,int s)
{
	if(k==7)
	{
		sum1++;
		return 0;
	}
	if(a[x][y]!=m[k])
		return 0;
	if(zrk(x+xx[s],y+yy[s],k+1,s)==1)
	{
		sum1++;
		return 0;
	}
	else
		return 0;
}
int main()
{
	int i,j,k;
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>a[i][j];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a[i][j]==m[0])
			{
				for(int k=0;k<=3;k++)
				{
					zrk(i+xx[k],j+yy[k],1,k);
				}				
			}
		}		
	}
	cout<<sum1;
}

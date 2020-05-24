#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];
int main()
{
	int s=1,n=0,x=1,y=0,xx=0,yy=0,i,j;
	cin>>n;
	y=n/2+1;
	a[x][y]=s;
	while(s<n*n)
	{
		xx=x-1;
		yy=y+1;
		if(xx<1)
			xx=n;
		if(yy>n)
			yy=1;
		if(a[xx][yy]!=0)
		{
			xx=x+1;
			yy=y;
		} 
		x=xx;
		y=yy;
		s++;  
		a[x][y]=s;
		
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<a[i][j]<<"  ";
		}
		cout<<endl;
	}
}

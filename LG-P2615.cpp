#include<bits/stdc++.h>
using namespace std;
int x,y,n,m;
int a[1500][1500];
int main()
{
	int i,j,k;
	cin>>n;
	x=1;
	y=(n-1)/2+1;
	a[x][y]=1;
	for(i=2;i<=n*n;i++)
	{
		if(x==1&&y!=n)
		{
			x=n;
			y++;
			a[x][y]=i;
		}
		else if(x!=1&&y==n)
		{
			 	x--;
		 		y=1;
			 	a[x][y]=i;
		}
			 else if(x==1&&y==n)
			 {
				 x++;
				 a[x][y]=i;
			 }
				  else if(x!=1&&y!=n&&a[x-1][y+1]==0)
				  {
				  	  x--;
					  y++;
					  a[x][y]=i;
				  }
					   else if(x!=1&&y!=n&&a[x-1][y+1]!=0)
					   {
			 		    	x++;
			 				a[x][y]=i;
			 		   }
	}	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}

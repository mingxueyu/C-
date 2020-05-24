#include<bits/stdc++.h>
using namespace std;
char a[100][100];
int b[100][100];
int main()
{
	int i=0,s=0,m=0,j=0,n=0,sum=0,x=0,y=0,k=0,v=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
		if(a[i+1][j]=='+')
			b[i][j]++;
		if(a[i-1][j]=='+')
			b[i][j]++;
		if(a[i][j+1]=='+')
			b[i][j]++;
		if(a[i][j-1]=='+')
			b[i][j]++;
		if(a[i-1][j+1]=='+')
			b[i][j]++;
		if(a[i+1][j-1]=='+')
			b[i][j]++;
		if(a[i+1][j+1]=='+')
			b[i][j]++;
		if(a[i-1][j-1]=='+')
			b[i][j]++;			
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(b[i][j]>=m) 
			{
					m=b[i][j];
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(b[i][j]==m)
				cout<<i<<" "<<j<<endl;
		}
	}
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
	/*
	5
	0 0 0 + 0
	0 + 0 0 0
	0 0 0 + 0
	0 0 0 0 0
	0 0 + 0 0
	*/
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
char a[108][108];
int b[108][108];
int main()
{      
	int sum=0,s=0,n=0,i=0,x=0,m=0,y=0,k=0,o=0,j=0,t=48;
	cout<<"输入棋盘大小"<<enld; 
 	cin>>n;
 	cout<<"输入魔法师数量"<<endl;
	cin>>k;
 	for(i=1;i<=n;i++)
 	{
 		for(j=1;j<=n;j++)
		{
			a[i][j]='0';	
		}	
	}
	for(o=1;o<=k;o++)
	{
		cout<<"输入魔法师方位"<<endl; 
		cin>>x>>y;
		a[x][y]='+';
		if(a[x+1][y]!='+')
			a[x+1][y]++;
		if(a[x-1][y]!='+')
			a[x-1][y]++;
		if(a[x][y+1]!='+')
			a[x][y+1]++;
		if(a[x][y-1]!='+')
			a[x][y-1]++;
		if(a[x-1][y+1]!='+')
			a[x-1][y+1]++;
		if(a[x+1][y-1]!='+')
			a[x+1][y-1]++;
		if(a[x+1][y+1]!='+')
			a[x+1][y+1]++;
		if(a[x-1][y-1]!='+')
			a[x-1][y-1]++;			
	}
	cout<<"战略初步图正在打印中........"<<endl;
	cout<<"打印成功!"<<endl;
	cout<<"-----------------------------------------"<<endl;
 	for(i=1;i<=n;i++)
 	{
 		for(j=1;j<=n;j++)
		{
			cout<<a[i][j]<<" ";	
		}
		cout<<endl;	
	}		
	return 0;
}


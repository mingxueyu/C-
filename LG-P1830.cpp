#include<bits/stdc++.h>
using namespace std;
int x,y,n,m,a,b,t[1500][1500],tx[1500][1500],a1,b1,ty[1500][1500];//if(t=1)±»Õ¨ 
int main()
{
	int i,j,k;
	cin>>n>>m>>x>>y;
	for(i=1;i<=x;i++)
	{
		cin>>a>>a1>>b>>b1;
		for(j=a;j<=b;j++)
			for(k=a1;k<=b1;k++)
			{
				t[j][k]=1;
				tx[j][k]+=1;
				ty[j][k]=i;
			}			
	}	
	for(i=1;i<=y;i++)
	{
		cin>>a>>b;
		if(t[a][b]==1)
		{
			cout<<"Y "<<tx[a][b]<<" "<<ty[a][b]<<endl;
		}
		else
			cout<<"N"<<endl;
	}
} 

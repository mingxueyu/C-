#include<bits/stdc++.h>
using namespace std;
int x[1000000],y[1000000],t,s,mx;
void zrk(int i,int j)
{
	int m;
	m=x[i];
	x[i]=x[j];
	x[j]=m;
	m=y[i];
	y[i]=y[j];
	y[j]=m;
}
int main()
{
	double m;
	int n,i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>x[i]>>y[i];
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
		{
			if(y[i]<y[j])
			{
				zrk(i,j);
			}
			else if(y[i]==y[j]&&x[i]>x[j])
				 {
				 	zrk(i,j);
				 }
		}
		
	int mx=m*1.5;
	int ans=0;
	for(i=1;i<=n;i++)
	{
		if(y[i]>=y[mx])
			ans++;
	}
	cout<<y[mx]<<" "<<ans<<endl;
	for(i=1;i<=ans;i++)
	{
		if(y[i]>=y[mx])
			cout<<x[i]<<" "<<y[i]<<endl;
		else
			break;
	}
}

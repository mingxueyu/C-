#include<bits/stdc++.h> 
using namespace std;
int x[10000000],y[10000000];
int n,m,a;
int main()
{
	double sum;
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x[i];
		y[i]=i;
	}
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
		{
			if(x[i]>x[j])
			{
				m=x[i];
				x[i]=x[j];
				x[j]=m;
				m=y[i];
				y[i]=y[j];
				y[j]=m;
			}
		}
	for(i=1;i<=n;i++)
	{
		cout<<y[i]<<" ";
			sum+=a;
		a+=x[i];
	}
	printf("%.2lf",sum/(n*1.0));
}

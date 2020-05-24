#include<bits/stdc++.h>
using namespace std;
double a[10000];
int b[10000];
int main()
{
	int i,j,n,m;int k;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
			if(a[j]>a[i])
			{
				k=a[i];
				a[i]=a[j];
				a[j]=k;
				k=b[i];
				b[i]=b[j];
				b[j]=k;
			}
	}	
	b[m]-=1;
	cout<<b[m]<<" "<<a[m];
} 

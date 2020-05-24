#include<bits/stdc++.h>
using namespace std;
int a[100000]={0,990,1010,1970,2030,2940,3060,3930,4060,4970,5030,5990,6010,7000},t[100000],b[10000];
int n,m,sum1=0;
void zrk(int x)
{
	for(int i=1;i<=n+13;i++)
	{
		cout<<sum1<<"------------------"<<endl;
		cout<<x<<"<<<<<<<<<<<<"<<endl;
		if(a[i]>=n&&a[i]<=m)
		{
			if(t[i]==0)
			{
				cout<<"X"<<endl;
					if(a[i]>=7000)
						sum1++;
					return;					
			}
			t[i]=1;
			zrk(a[i]);//a[i]目前长度;
			t[i]=0;	
		}
		else
		{
			if(x+n>=7000)
				sum1++;
			return;	
		}	
	}
}
int main()
{
	int i,j,n,m,k;
	cin>>n>>m>>k;
	for(i=1;i<=k;i++)
	{
		cin>>a[i];
//		sum++;
	}
	zrk(0);
	cout<<sum1;
}

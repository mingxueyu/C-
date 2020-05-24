#include<bits/stdc++.h>
using namespace std;
int a[10000],t[10000],x[10000],sum[10000],tt[10000];
int n,m,s;
int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=7;i++)
	{
		cin>>a[i];
		t[a[i]]=1;
	}
	for(i=1;i<=n;i++)
	{
		s=0;
		for(j=1;j<=7;j++)
		{
			x[j]=0;
		}
		for(j=1;j<=35;j++)
		{
				tt[j]=0;
		}
		for(j=1;j<=7;j++)
		{
			cin>>x[j];
			if(t[x[j]]==1)
				tt[x[j]]=-1;
		}		
		for(j=1;j<=40;j++)
			if(tt[j]==-1)
			{
//				cout<<"X"<<endl;
				s++;
			}
//		cout<<s<<endl;
		if(s==7)
			sum[7]++;	
		if(s==6)
			sum[6]++;
		if(s==5)
			sum[5]++;
		if(s==4)
			sum[4]++;
		if(s==3)
			sum[3]++;
		if(s==2)
			sum[2]++;
		if(s==1)
			sum[1]++; 
	}
	for(i=7;i>=1;i--)
	{
		cout<<sum[i]<<" ";
	}
	cout<<endl;

}

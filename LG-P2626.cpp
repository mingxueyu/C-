#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int f[10000000];
int main()
{
	int i,j,k;
	cin>>n;
	f[1]=f[2]=1;
	for(i=3;i<=n;i++)
		f[i]=f[i-1]+f[i-2];
	m=f[n];
	cout<<m<<"=";
	for(i=2;m>1;)
	{
		if(m%i==0)
		{
			if(x==0)
				cout<<i;
			else
				cout<<"*"<<i;
			x=1;
			m/=i;
		}
		else
			i++;
			cout<<m<<endl;		
	}

} 

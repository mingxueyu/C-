#include<bits/stdc++.h>
using namespace std;
int t[10000000];
int zhishu(int n)
{
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
			return 0;
	}
	int o=n,s=0;
	while(o!=0)
	{
		s=s*10+o%10;
		o/=10;
	}
	if(s==n)
	{
		for(int i=2;i<=sqrt(s);i++)
		{
			if(s%i==0)
				return 0;
		}		
	}
	else
		return 0;
	return 1;
}//CHM-12-ZSPD-º¯ÊýÄ£°å-G
int main()
{
	int i,j,n,m;
	cin>>n>>m;
	for(i=4;i<=m;i+=2)
		t[i]=1;
	for(i=n;i<=m;i++)
	{
		if(t[i]==0)
			if(zhishu(i)==1)
				cout<<i<<endl;
	}
} 

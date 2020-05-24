#include<bits/stdc++.h>
using namespace std;
int s10=1;
int t[10000000];
int k;
int zhishu(int n)
{
		for(int i=2;i<=sqrt(n);i++)
		{
			if(n%i==0)
				return 0;
		}
		return 1;
}//CHM-12-ZSPD-º¯ÊýÄ£°å 
int main()
{
	int n,i,j;
	cin>>n;
	for(i=1;i<=n;i++)
		s10*=10; 
	for(i=s10;i<=s10*10;i++)
	{
		if(zhishu(i)==1)
		{
			t[k]=i;
			k++;
		}
	}
	for(i=1;i<=k;i++)
	{
		for(j=1;j<=n;j++)
			cout<<t[j];
		cout<<endl;
	}
} 

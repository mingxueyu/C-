#include<bits/stdc++.h>
using namespace std;
char a;
int x,ans,k;
int main()
{
	while(cin>>a)
	{
		k++;
		if(a<='9'&&a>='0')
			x[i]=a-'0';
		else
		{
			if(a=='+')
				f[i]=1;
			if(a=='*')
				f[i]=2;
		}
	}
	for(i=1;i<=k;i++)
	{
		if(f[i]==2)
		{
			f[i-1]*f[i+1];
		}
	}
	cout<<ans%10000;
}

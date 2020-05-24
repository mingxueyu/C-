#include<bits/stdc++.h>
using namespace std;
int n,m,x,ans;
int main()
{
	int i,j;
	cin>>n>>m;
	for(i=n;i<=m;i++)
	{
		x=i;
		while(x!=0)
		{
			if(x%10==2)
				ans++;	
			x/=10;
		}	
	}	
	cout<<ans;
}

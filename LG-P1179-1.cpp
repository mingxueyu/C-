#include<bits/stdc++.h>
using namespace std;
int RP;
int n,m;
int main()
{
	int i,j,k;
	cin>>n>>m;
	for(i=n;i<=m;i++)
	{
		k=i;
		while(k!=0)
		{
			if(k%10==2)
				RP++;
			k/=10;
		}
	}
	cout<<RP;
}


#include <bits/stdc++.h>
using namespace std;
int main()
{
	int s=0,n,m,i,a,b,c,d,e,x;
	cin>>n>>m>>x;
	for(i=n;i<=m;i++)
	{
		while(n!=0)
		{
			n=i;
			if(n%10==x)
				s++;
		}
	}
	cout<<s;
}


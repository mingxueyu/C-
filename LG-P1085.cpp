#include<bits/stdc++.h>
using namespace std;
int n,m=8,x,y;
int main()
{
	int i;
	for(i=1;i<=7;i++)
	{
		cin>>x>>y;
		if(x+y>m&&x+y>8)
		{
			n=i;
			m=x+y;	
		}	
	}
	if(m!=-214748)
		cout<<n;
	else
		cout<<"0";	
} 

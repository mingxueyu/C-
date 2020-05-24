#include<bits/stdc++.h>
using namespace std;
int t[1000000];
int main()
{
	int n,i,x,m=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		if(t[x]!=1)
			m++;
		t[x]=1;
	}
	cout<<m<<endl;
	for(i=1;i<=10500;i++)
	{
		if(t[i]==1)
			cout<<i<<" ";
	}
	return 0;
}

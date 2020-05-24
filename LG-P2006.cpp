#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,w;
int a[10000];
int main()
{
	int i,j=0,k;
	cin>>k>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>x>>y;
		if(x==0&&y>=1)
		{
			j++;
			a[j]=i;
			w=1;
		}
		else if(k/x*y>=m)
		{
			j++;
			a[j]=i;
			w=1;
		}
	}
	if(w==0)
		cout<<"-1";
	else
	{
		cout<<a[1];
		for(i=2;i<=j;i++)
			cout<<" "<<a[i];		
	}

}

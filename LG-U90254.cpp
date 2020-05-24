#include<bits/stdc++.h>
using namespace std;
int b[1000000],a[1000000];
int n,m,ans;
int main()
{
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=m;i++)
		cin>>b[i];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]>b[j])
				ans++;
	cout<<ans;
}

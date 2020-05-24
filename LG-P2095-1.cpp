#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int x[1000000],a[1000000],t[1000000],ans;
bool cmp(int k1,int k2)
{
	return k1>k2;
}
int main()
{
	int i,j,k;
	cin>>n>>m>>k;
	for(i=1;i<=k;i++)
		cin>>x[i];
	for(i=1;i<=n;i++)
		cin>>a[i]>>t[i];
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++)
	{
		if(m!=0&&x[t[i]]!=0)
		{
			x[t[i]]--;
			m--;
			ans+=a[i];
		}
		if(m==0)
			break;
//		cout<<i<<" "<<ans<<endl;
	} 
	cout<<ans;
	return 0;
}

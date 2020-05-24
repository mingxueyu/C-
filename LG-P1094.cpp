#include<bits/stdc++.h>
using namespace std;
int w,n,ans;
int a[10000000];
bool cmp(int k1,int k2)
{
	return k1<k2;
}
int main()
{
	int i,j,k;
	cin>>w>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(i=1,j=n;i<=j;)
	{
//		cout<<i<<" "<<j<<" "<<endl;
		if(a[i]+a[j]<=w)
		{
			i++;
			j--;
			ans++;
		}
		else
			if(a[i]+a[j]>w)
			{
				j--;
				ans++;
			}
	}
	cout<<ans;
}

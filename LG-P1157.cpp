#include<bits/stdc++.h>
using namespace std;
int a[100000];
int t[100000];
int n,r;
void zrk(int k,int k1)
{
	if(k1==r+1)
	{
		for(int i=1;i<=r;i++)sd
		{
			printf("%3d",a[i]);
		}
		cout<<endl;
		return;
	}
	for(a[k]=1;a[k]<=n;a[k]++)
	{
		if(t[a[k]]==0)
		{
			t[a[k]]=1;
			zrk(k+1,k1+1);
			t[a[k]]=0;
		}		
	}
}
int main()
{
	cin>>n>>r;
	zrk(1,1);
}

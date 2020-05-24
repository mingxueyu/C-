#include<bits/stdc++.h>
using namespace std;
int n,a[10000000],t[10000000];
int main()
{
	int i,j,k;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
	{
		t[i]=abs(a[i]-a[i-1]);
	}
//	for(i=1;i<n;i++)
//		cout<<t[i]<<" ";
//	cout<<endl;
	sort(t,t+n);
//	for(i=0;i<=10;i++)
//		cout<<t[i]<<" ";
//	cout<<endl;
	for(i=1;i<n;i++)
	{
//		cout<<i<<" "<<t[i]<<endl;
		if(t[i]!=i)
		{
			cout<<"Not jolly";
			return 0;
		}
	}
	cout<<"Jolly";
} 

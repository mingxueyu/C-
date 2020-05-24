#include<bits/stdc++.h>
using namespace std;
int a[100000],b[100000];
int n,m=2147483647,ans;
int main()
{
	int i,j,k;
	cin>>n;
	for(i=2;i<sqrt(n);i++)
		if(n%i==0)
		{
			cout<<n/i;
			return 0;
		}
} 

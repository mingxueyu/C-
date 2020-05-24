#include<bits/stdc++.h>
using namespace std;
char x[10000];
int a[10000];
int main()	
{
	int i=1,j,m=-100,n;
	cin>>x;
	n=strlen(x);
	for(i=1;i<n;i++)
		a[x[i]]++;
	for(i=97;i<=122;i++)
	{
		if(a[i]>m)
		{
			m=a[i];
			j=i;
		}
	}
	cout<<char(j)<<" "<<m;
}

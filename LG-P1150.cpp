#include<bits/stdc++.h>
using namespace std;
int a[50000];
int main()
{
	int n,m,i,j,k,k1=0,x=0;
	cin>>n>>k;
	while(n!=0)
	{
		n--;
		k1++;
		if(k1==k)
		{
			k1=0;
			n++;	
		}	
		x++;
	}
	cout<<x;	
}

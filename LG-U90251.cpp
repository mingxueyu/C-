#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long x,n,s=1;
	long long i=0,j,k;
	cin>>n;
	while(x<n)
	{
		i++;
		x+=s;
		s*=2;
	}
	cout<<i;
}
//11111
//22222
//33333
//33333
//44444
//44444


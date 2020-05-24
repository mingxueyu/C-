#include<bits/stdc++.h>
using namespace std;
int a,x;
int main()
{
	cin>>a;
	if(a<0)
	{
		cout<<"-";
		a=-a;
	}
	while(a!=0)
	{
		x=x*10+a%10;
		a/=10;
	}
	cout<<x;
}

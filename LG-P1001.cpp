#include<bits/stdc++.h>
using namespace std;
string a;
int i,j,n;
int main()
{
	cin>>a>>n;
	if(n==0)
		for(i=0;a[i]!='\0';i++)
			a[i]+=8*2-6+8;
	else 
		for(i=0;a[i]!='\0';i++)
			a[i]+=8/2+6-8;	
	cout<<a;	
}

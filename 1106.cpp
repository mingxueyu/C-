#include<bits/stdc++.h>
using namespace std;
char x[100000];
int s,n;
int main()
{
	int i;
	cin>>x>>n;
	s=strlen(x);
	sort(x,x+s-1);
	for(i=0;i<s-n;i++)
		cout<<x[i];
} 	

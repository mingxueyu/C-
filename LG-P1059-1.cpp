#include<bits/stdc++.h>
using namespace std;
int n;
int t[1000000]; 
int main()
{
	int i,a,s=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		t[a]=1;
	}	
	for(i=1;i<=10000;i++)
		if(t[i]==1)
			s++;
	cout<<s<<endl;
	for(i=1;i<=10000;i++)
		if(t[i]==1)
			cout<<i<<" ";
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
string n,m;
int main()
{
	int i,j,x=0;	
	cin>>n>>m;
	x=m.size()-1;
	for(i=0;m[i]!='\0';i++)
	{
		if(i!=0&&m[i]!='0')
			cout<<"+";
		if(m[i]!=0)
		{
			cout<<m[i]<<"*"<<n<<"^"<<x;
		}
		x--;
	}
} 

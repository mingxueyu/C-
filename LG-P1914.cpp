#include<bits/stdc++.h>
using namespace std;
int n,m;
string x;
int main()
{
	int i,j,k;
	cin>>n>>x;
	for(i=0;x[i]!='\0';i++)
	{
		for(j=1;j<=n;j++)
		{
			x[i]++;
			if(x[i]>'z')
			{
				x[i]='a';
			}
		}
	}
	cout<<x;
}

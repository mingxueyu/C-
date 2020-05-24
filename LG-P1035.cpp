#include<bits/stdc++.h>
using namespace std;
double ans,k,RP;
int main()
{
	cin>>k;
	while(ans<=k)
	{
		RP++;
		ans+=1/RP;
	}
	cout<<RP;
}

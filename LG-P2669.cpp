#include<bits/stdc++.h>
using namespace std;
int s,ans,k;
int main()
{
	int i=1;
	cin>>k;
	while(k!=0)
	{
		if(s==i)
		{
			i++;
			s=0;
		}
		ans+=i;
		k--;
		s++;
	}
	cout<<ans;
}

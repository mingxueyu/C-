#include<bits/stdc++.h>
using namespace std;
int n,sum,s;
int t[1000000];
int main()
{
	int i,j,k;
	cin>>n;
	
	for(i=n;;i++)
	{
		sum=0;
		s=0;
		
		for(j=1;j<i;j++)
		{
			if(i%j==0)
			{
				sum+=j;
			}
		}//B
		for(j=1;j<sum;j++)	
		{
			if(sum%j==0)
			{
				s+=j;
			}
		}//A
		if(s==i&&s!=sum)
		{
			cout<<s<<" "<<sum;
			return 0;
		}
	}
}

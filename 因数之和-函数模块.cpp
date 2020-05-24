#include<bits/stdc++.h>
using namespace std;
int main()
{
	int j,k,sum=0;
		for(k=1;k<=4;k++)
		{
			if(4%k==0)
			{
				sum+=k;
			}
		}
		cout<<sum;
}

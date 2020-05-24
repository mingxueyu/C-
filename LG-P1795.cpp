#include<bits/stdc++.h>//¾ø¶ÔTLE//10^9.... 
using namespace std;
//int t[1000000]={1101001000100001000001000000100000001000000001000000000100000000001000000000001000000000000100000000000001};
int n,m=2147483647,ans;
int zrk(int x)
{
	int i=1,s=1;
	while(1)
	{
		if(i==x)
			return 1;
		if(i>x)
			return 0;
		i+=s;
		s++;
//		cout<<i<<endl;
	}
}
int main()
{
	int i,j,k,x;
	scanf("%d",&n); 
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(zrk(x)==1)
			cout<<"1"<<endl;
		else
			cout<<"0"<<endl;
	}
} 

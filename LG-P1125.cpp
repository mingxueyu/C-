#include<bits/stdc++.h>
using namespace std;
int ans,ma,mn=2147483647;
int t[1000000],tx[1000000];
string x;
int zrk(int ans)
{
	if(ans==0||ans==1)
		return 0;
	if(ans==2)
		return 1;
	for(int i=2;i<=sqrt(ans);i++)
	{
		if(ans%i==0)
			return 0;
	}
	return 1;
}
int main()
{
	int i,j;
	cin>>x;
	for(i=1;x[i]!='\0';i++)
	{
		t[x[i]]++;
		if(t[x[i]]==1)
			tx[x[i]]=1;
	}
	for(i='a';i<='z'+1;i++)
	{
		if(t[i]>ma&&tx[i]==1)
			ma=t[i];
		if(t[i]<mn&&tx[i]==1)
			mn=t[i];
	}
	ans=ma-mn;
	if(zrk(ans)==0)
	{
		cout<<"No Answer"<<endl;
		cout<<"0";
	}
	else
	{
		cout<<"Lucky Word"<<endl;
		cout<<ans;
	}
}

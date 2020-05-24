#include<bits/stdc++.h>
using namespace std;
int t[1000000],a[1000000];
int main()
{
	int x,y,z,i,j,k,ans=0;
	cin>>x>>y>>z;
	for(i=1;i<=9;i++)
	{
		t[i]=1;
		for(j=1;j<=9;j++)
		{
			t[j]=1;
			for(k=1;k<=9;k++)
			{
				if(t[k]==0)
				{
					ans++;
					a[ans]=i*100+j*10+k;		
				}	
			}
			t[j]=0;
		}
		t[i]=0;
	}
	for(i=1;i<=ans;i++)
		cout<<a[i]<<" ";
}

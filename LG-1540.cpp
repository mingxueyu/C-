#include<bits/stdc++.h>
using namespace std;
int n,m=8,x,y,t=1,ans;
int q[1000000];
int main()
{
	int i,j,k;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		k=0;
		cin>>x;
		for(j=1;j<=n;j++)
			if(q[j]==x)
				k=1;
		if(t==4)
			t=1;
		if(k==0)
		{
			ans++;
			q[t]=x;
			t++;
		}
////		if(k==1)
////		{
////			s++;
////			q[s]=x;
////		}
//		for(k=1;k<=5;k++)
//			cout<<q[k]<<" ";
//		cout<<endl;
	}	
//	for(i=1;i<=5;i++)
//		cout<<q[i]<<" ";
	cout<<ans;
	return 0;
} 

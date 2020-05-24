#include<bits/stdc++.h> 
using namespace std;
int t[1000000],x,y,z,mx,mxx;
int main()
{
	int i,j,k;
	cin>>x>>y>>z;
	for(i=1;i<=x;i++)
		for(j=1;j<=y;j++)
			for(k=1;k<=z;k++)
			{
				t[i+j+k]++;
			}
	for(i=1;i<=100;i++)
	{
		if(t[i]>mx)
		{
			mx=t[i];
			mxx=i;
		}
	}
	cout<<mxx;
}

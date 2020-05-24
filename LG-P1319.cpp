#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,n,x,m=1,t=0,sum=0;
	cin>>n;
	for(i=1;;i++)
	{
		if(sum>=n*n)
			break;
		cin>>x;
//		cout<<i<<endl;
		for(j=x;j>=1;j--)
		{
			if(t==n)
			{
				cout<<endl;
				t=0;
			}	
			if(i%2==0)
				cout<<"1";
			else
				cout<<"0";
			t++;
			sum++;
		}
	}
}

#include<bits/stdc++.h>
using namespace std;
int t[1000000],x[10000];
int n,m=2147483647,ans;
void zrk(int n)
{
	if(n>9)
	{
		if((2*(x[1]*100+x[2]*10+x[3])==(x[4]*100+x[5]*10+x[6]))&&(3*(x[1]*100+x[2]*10+x[3])==(x[7]*100+x[8]*10+x[9])))
		{
			for(int i=1;i<=9;i++)
			{
				cout<<x[i];
				if(i%3==0)
					cout<<" ";
			}
			cout<<endl;
		}
//			for(int i=1;i<=9;i++)
//			{
//				cout<<x[i];
//				if(i%3==0)
//					cout<<" ";
//			}
//			cout<<endl;
		return;
	}
	for(int i=1;i<=9;i++)
	{
		if(t[i]==0)
		{
			x[n]=i;
			t[i]=1;
			zrk(n+1);
			t[i]=0;
			x[n]=0;	
		}	
	}	
}
int main()
{
	int i,j,k;
	zrk(1);
} 

#include<bits/stdc++.h>
using namespace std;
int zrk(int x,int y)
{
    if(x%y==0)
        return y;
    zrk(y,x%y);
}
int main()
{
	int a,b,l,x,y,mn=2147483647;
	int i,j;
	cin>>a>>b>>l;
	x=2147483647;
	y=1;
	for(i=1;i<=l;i++)
	{
		for(j=1;j<=l;j++)
		{
			if(zrk(i,j)==1&&i*b>=j*a&&i*y<j*x)
			{
//				cout<<i<<" "<<j<<endl;
				x=i;
				y=j;
			}
		}
	}
	cout<<x<<" "<<y;
} 

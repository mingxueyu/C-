#include<bits/stdc++.h>
using namespace std;
bool a[100];
int h[100];
int main()
{
	int m,n,x,s=0,v=0,v1=0;//m=顺时针数第m个人出圈，n=有几人，x=一回合，到第几人了,s=存活人数，v=计数器，判断是不是它出局 ，v1=第x人的密码 
	cin>>n>>m;
	for(i=1;i<=n;i++)
		a[i]=1;
	s=n;
	while(s>0)
	{
		if(x>n)
		x=1;
		if(a[x]==1)
		{
			v1=h[x] 
			v++;
			if(v==m)
			{
				a[x]=0;
				cout<<v1<<" ";
				s--;
				x=0;
			}
	 
		}	
	}
	cout<<"||-游戏结束---幸存者全死了-||"<<endl;
	cout<<"||-Game over---the survivors are all dead-||"<<endl;
	cout<<"||-你失败了-||"<<endl;
	cout<<"||-You have failed!-||"<<endl;
}

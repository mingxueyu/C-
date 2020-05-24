#include<bits/stdc++.h>
using namespace std;
bool a[100];
int main()
{
	int n,m,s=0,x=0,i=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		a[i]=1;
	s=n;
	i=0;
	while(s>0)
	{
		i+=1;
		if(i>n)
			i=1;
		if(a[i]==1)
		{
			x++;
			if(x==m)
			{
				a[i]=0;
				cout<<"第"<<i<<"号人被X杀死了 "<<endl;;
				s--;
				x=0;
			}			
		}
	}
	cout<<"游戏结束---幸存者全死了-----EEEE"<<endl;
	return 0;
}

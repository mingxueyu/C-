#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k=0,i,j,m,ans=0;
	cin>>n;
	for(i=1;i<=n;i++,k++)
	{
		if(k==m)
		{
			k=0;//������������ 
			m++;//ÿ��Ҫ�ӵĽ�� 
		}
		ans+=m;
	}
	cout<<ans;
}

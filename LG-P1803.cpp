#include<bits/stdc++.h>//��������ûʱ�� 
using namespace std; 
int n,m,a[10000000],x,sum,s;//����������=_= 
int main()//�̷ֳ��� 
{
	cin>>x;
	for(int i=1;i<=x;i++)
	{
		cout<<"x";
		cin>>n>>m;
		a[n]=1;
		a[m]=2;
	}
	for(int i=1;i<=x;i++)
	{
		if(a[i]==1&&s==0)
			s++;
		if(s==1&&a[i]==2)
		{
			s--;
			sum++;
		}
	}
	cout<<sum;
}

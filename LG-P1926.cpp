#include<bits/stdc++.h>
using namespace std;
int a[10000],b[10000],c[10000],t[10000];//a[i]=题时间,b[i]=作业时间,c[i]=作业分值 
int sum=0;
int mi=21474836;
int n,m,r,k;//r=总时间 
void zrk(int x,int y)//y=时间 
{
//	cout<<"X"<<endl;
	if(x>k)
	{
//		cout<<"Y"<<endl;
		if(y<mi)
			mi=y;
		return;
	}
//	cout<<x<<"-------"<<y<<endl;
	for(int i=1;i<=m;i++)
	{
		if(t[i]==0)
		{
			t[i]=1;
			zrk(x+c[i],y+b[i]);
			t[i]=0;
		}
	}
}
int main()
{
	int i;
	cin>>n>>m>>k>>r;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=m;i++)
		cin>>b[i];
	for(i=1;i<=m;i++)
		cin>>c[i];	
	zrk(0,0);
//	cout<<r<<" "<<mi;
	r=r-mi;//还剩,不是总时间了 
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)//做题
	{
		r-=a[i];
		if(r>0)
		{
			sum++;
		} 
	} 
	cout<<sum;
} 

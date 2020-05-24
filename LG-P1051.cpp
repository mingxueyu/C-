#include<bits/stdc++.h>
using namespace std;
int n,ans;
struct ynt
{
	string x,x_3,x_4;
	int x_1,x_2,x_5,x_z,x_n;//x_2=°à¼¶ÆÀÒé;
};
ynt a[10000],v;
void k(int i,int j)
{
	v=a[i];
	a[i]=a[j];
	a[j]=v;	
}
int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].x_1>>a[i].x_2>>a[i].x_3>>a[i].x_4>>a[i].x_5;
		a[i].x_n=i;
		if(a[i].x_1>80&&a[i].x_5>=1)
			a[i].x_z+=8000;
		if(a[i].x_1>85&&a[i].x_2>80)
			a[i].x_z+=4000;
		if(a[i].x_1>90)
			a[i].x_z+=2000;
		if(a[i].x_1>85&&a[i].x_4=="Y")
			a[i].x_z+=1000;
		if(a[i].x_2>80&&a[i].x_3=="Y")
			a[i].x_z+=850;
		ans+=a[i].x_z;
	}
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			if(a[i].x_z<a[j].x_z)
				k(i,j);
			else if(a[i].x_z==a[j].x_z&&a[i].x_n>a[j].x_n)
				 	k(i,j);
	cout<<a[1].x<<endl<<a[1].x_z<<endl<<ans;
}

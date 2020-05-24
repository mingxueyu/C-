#include<bits/stdc++.h>
using namespace std;
struct zrk
{
	int a,b;//序号,w[i]权值 
};
zrk x[100000];
int e[100000];
int n,m,t; 
bool cmp(zrk k1,zrk k2)
{
	if(k1.b==k2.b)//如果权值相等 
		return k1.a<k2.a;//那么就序号小的在前 
	else
		return k1.b>k2.b;
}
int main()
{
	int i,j,k;
	cin>>n>>m;
	for(i=1;i<=10;i++)
	{
		cin>>e[i];
	}
	for(i=1;i<=n;i++)
	{
		x[i].a=i;
		cin>>x[i].b;
	} 
	sort(x+1,x+n+1,cmp);//从大到小m
	for(i=1;i<=n;i++)
	{
		t=i-1;
		x[i].b+=e[(t%10)+1];
	}
	sort(x+1,x+n+1,cmp);//从大到小m	
	for(i=1;i<=m;i++)
	{
		cout<<x[i].a<<" ";
	}
		
}

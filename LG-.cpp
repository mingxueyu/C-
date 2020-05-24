#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int x[1000000],a[1000000],t[1000000],ans;
bool cmp_1(w k1,w k2)
{
	return k1.cion>k2.cion;
}
struct w;
{
	int tim,cion;
};
w x[100000];
int main()
{
	cin>>m>>n;
	for(i=1;i<=n;i++)
		cin>>x[i].tim;
	for(i=1;i<=n;i++)
		cin>>x[i].cion;
	sort(x+1,x+n+1,cmp_1);
	
}

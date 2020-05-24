#include<bits/stdc++.h>
using namespace std;
int q[2000000],t=0,w=1,f[1500],k[20000000];
int n,m,x,y,a,b,o,x_1,y_1;
void bfs()
{
	w=1;
	t=0;
	q[t]=x;
	f[x]=1;
	while(t<w)
	{
		cout<<t<<" "<<w<<endl;
		cout<<"---f[t]="<<f[t]<<endl;
		if(f[y]!=0)
		{
			cout<<f[y];
			return;
		}
		t++;
		a=q[t]+k[t];
		b=q[t]-k[t];
		if(a<=n&&a>=1&&f[a]==0)	
		{				
			w++;                                                                   
			q[w]=a;
			f[a]=f[q[t]]+1;
		}
		t++;
		if(b<=n&&b>=1&&f[b]==0)	
		{				
			w++;                                                                   
			q[w]=b;
			f[b]=f[q[t]]+1;
		}
		cout<<"---f[t]="<<f[t]<<endl;
	}	
}
int main()
{
	int i,j;
	cin>>n>>x>>y;
	for(i=1;i<=n;i++)
	{
		cin>>k[i];
	}
	bfs();
}

#include<bits/stdc++.h>
using namespace std;
int q[2000000][4],f[1500][1500];
int x,y,n,lx[1000000];
int xx[10000],tt[100000];
int yy[10000];
int xxx[10]={-1,1,0,0},yyy[10]={0,0,-1,1};
void bfs()
{
	int t=0,w=1;
	w=1;
	q[w][0]=1;
	q[w][1]=1;
	q[w][2]=1;
	f[1][1]=1;	
	while(t<w)
	{
		int a,b;
		int cb,cb1,cb2;
		t++;
		cb=q[t][0];
		cb1=q[t][1];
		cb2=q[t][2];
		f[xx[cb2]][yy[cb2]]=-1;	
		f[xx[cb2]+1][yy[cb2]]=-1;
		f[xx[cb2]][yy[cb2]+1]=-1;
		f[xx[cb2]][yy[cb2]-1]=-1;
		f[xx[cb2]-1][yy[cb2]]=-1;
		for(int i=0;i<=3;i++)
		{
			a=cb+xxx[i];
			b=cb1+yyy[i];		
			if(lx[a][b]==-10)
			{
				cout<<cb2+1;
				return;
			}
			if(a>=1&&a<=n&&b>=1&&b<=n&&f[a][b]==0&&cb2<lx[a][b])
			{
				w++;
				q[w][0]=a;
				q[w][1]=b;
				q[w][2]=cb2+1;
				f[a][b]=cb2+1;
			}
		}
	}
	cout<<"No"<<endl;
}
int main()
{
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>xx[i]>>yy[i]>>tt[i];
	}
	for(i=1;i<=n;i++)
	{
		lx[xx[i]][yy[i]]=tt[i];
	}
	for(i=1;i<=n;i++)
	{
		if(lx[xx[i]][yy[i]]==0)
			lx[[xx[i]][yy[i]]]=-10;
	}
	bfs();
}

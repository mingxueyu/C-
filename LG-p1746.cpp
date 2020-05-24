#include<bits/stdc++.h>
using namespace std;
int q[200000][2],t=0,w=1,x1[1500][1500],f[1500][1500];
int xx[10]={-1,1,0,0},sum=0;
int yy[10]={0,0,-1,1};
char s[1000][1000];
int n,m,x,y,a,b,o;
int main()
{
	int i,j;
	cin>>o;
	for(i=1;i<=o;i++)
	{
		for(j=1;j<=o;j++)
		{
			cin>>s[i][j];
			x1[i][j]=s[i][j]-'0';
		}
	}
	cin>>n>>m>>x>>y;
	q[w][0]=n;
	q[w][1]=m;
	while(t<w)
	{
//		cout<<"----";
		if(q[t][0]==x&&q[t][1]==y)
		{
			cout<<sum-1;
			return 0; 
		}
		t++;
		for(i=0;i<=3;i++)
		{
		
//			cout<<q[t][1]<<"<<<<"<<endl;
//			cout<<q[t][0]<<"_____"<<endl;				cout<<x1[q[t][0]+xx[i]][q[t][1]+yy[i]]<<endl;
			a=q[t][0]+xx[i];
			b=q[t][1]+yy[i];
			if(a>=1&&a<=o&&b>=1&&b<=o&&x1[q[t][0]+xx[i]][q[t][1]+yy[i]]==0&&f[a][b]==0)
			{
//				cout<<"JQL"<<endl;
				a=q[t][0]+xx[i];
				b=q[t][1]+yy[i];
				f[a][b]=1;					
				s[a][b]='X';
				sum++;
				w++;
				q[w][0]=a;
				q[w][1]=b;
			}
		}
	} 
	cout<<sum<<"-----------------------------------------------------------";
	for(i=0;i<=o+1;i++)
	{
		for(j=0;j<=o+1;j++)
			cout<<f[i][j];
		cout<<endl;		
	}
	cout<<"-1";
}
//00000
//0x010
//01010
//010x0
//00000


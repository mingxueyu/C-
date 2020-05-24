#include<bits/stdc++.h>
using namespace std;
int n,s;
int t[1000000],t_1[1000000];
string x,y,z,a,b,c;
int main()
{
	int i,j,k;
	cin>>x>>y>>z;//x=加密;y=x的原信息;z=要破译的 
	n=x.size();
	if(n<25)
	{
		cout<<"Failed1";
		return 0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(x[i]==x[j]&&y[i]!=y[j]||x[i]!=x[j]&&y[i]==y[j])
			{
				cout<<"Failed2";
				return 0;
			}
		}	
	}
	for(i=0;x[i]!='\0';i++)
	{
		t[x[i]-'A']=1;
	}
	for(i=0;y[i]!='\0';i++)
	{
		t_1[y[i]-'A']=1;
	}
	for(i=0;i<25;i++)
	{
		if(t[i]==0||t_1[i]==0)
		{
			cout<<"Failed3";
			return 0;
		}
	}
	for(i=0;z[i]!='\0';i++)
	{
		for(j=0;x[j]!='\0';j++)
		{
			if(z[i]==x[j])
			{
				s++;
				cout<<y[j];
				break;
			}
		}
	}
}

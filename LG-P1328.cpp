#include<bits/stdc++.h>
using namespace std;
int x[1000000],y[1000000],n,na,nb;
int a,b;//小A分数;小B分数 
int main()
{
	int i,j,k;
	cin>>n>>na>>nb;
	for(i=1;i<=na;i++)
		cin>>x[i];
	for(i=1;i<=nb;i++)
		cin>>y[i];
	for(i=na+1;i<=n;)//小A的周期 
	{
		j=1;
		while(j<=na)
		{
			x[i]=x[j];
			i++;
			j++;
		}
	}
	for(i=nb+1;i<=n;)//小B 
	{
		j=1;
		while(j<=nb)
		{
			y[i]=y[j];
			i++;
			j++;
		}
	}
	for(i=1;i<=n;i++)//a=小A分数;b=小B分数 
	{
            if(x[i]==0&&(y[i]==3||y[i]==2))//0
				a++;
            if(x[i]==0&&(y[i]==1||y[i]==4))
				b++;				
            if(x[i]==1&&(y[i]==0||y[i]==3))//1
				a++;				
            if(x[i]==1&&(y[i]==2||y[i]==4))
				b++;
            if(x[i]==2&&(y[i]==1||y[i]==4))//2
				a++;								
            if(x[i]==2&&(y[i]==0||y[i]==3))
				b++;
            if(x[i]==3&&(y[i]==2||y[i]==4))//3
				a++;							
            if(x[i]==3&&(y[i]==0||y[i]==1))
				b++;
            if(x[i]==4&&(y[i]==0||y[i]==1))//4
				a++;
            if(x[i]==4&&(y[i]==2||y[i]==3))
				b++;
						
	}
//	for(i=1;i<=n;i++)
//		cout<<x[i]<<" ";
//	cout<<endl;
//	for(i=1;i<=n;i++)
//		cout<<y[i]<<" ";
//	cout<<endl;
	cout<<a<<" "<<b;
	return 0;
} 

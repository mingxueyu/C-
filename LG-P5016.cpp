#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int n,m,p1,s1,s2,x,y,ans,qsc;
int main()
{
	int i,j,k;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	cin>>m>>p1>>s1>>s2;
	a[p1]+=s1;
	for(i=1;i<m;i++)
		x+=a[i]*(m-i);
	for(i=n;i>m;i--)
		y+=a[i]*(i-m);
	if(x>y)//ÐùÐùÆøÊÆ>¿­¿­
	{
		qsc=x-y;
		for(i=m+1;i<=n;i++)
		{
			if(abs(s2*(i-m)+y-x)<qsc)
			{
//?				qsc=abs(s2*(i-m)+y-x);
				ans=i; 
			}
		}
		if(ans==0)
			cout<<m;
		else	
			cout<<ans;
	}
	else if(x==y)
		 	cout<<m;
		 else if(x<y)
		 	  {
		 	  	qsc=y-x;
				for(i=1;i<m;i++)
				{
					if(abs(s2*(m-i)+x-y)<qsc)
					{
//						cout<<"f";
						qsc=abs(s2*(m-i)+x-y);
						ans=i; 
					}
				}	
				if(ans==0)
					cout<<m;
				else	
					cout<<ans;
			  }	
	return 0;
}

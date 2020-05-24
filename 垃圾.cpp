#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int main()
{
	int i,j;//i=F,j=Fang true false
	bool m=0;
	for(j=1;j<=100;j++)
	{
		a[j]=1;
	}
	for(i=2;i<=100;i++)
		for(j=1;j<=n;j++)
		{
			if(j%i==0)
				if(a[j]!=1)
					a[j]++;
			else 
				a[j]--;
		}
	for(j=1;j<=100;j++)
		cout<<a[j];
}

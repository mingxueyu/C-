#include<bits/stdc++.h>
using namespace std;
int x[10];
char y[10];
int main()
{
	cin>>x[1]>>x[2]>>x[3];
	cin>>y[1]>>y[2]>>y[3];
	sort(x+1,x+4);
	for(int i=1;i<=3;i++)
	{
		cout<<x[y[i]-64]<<" ";
	}
	return 0;
}


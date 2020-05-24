#include<bits/stdc++.h>
using namespace std;

string n;
void zrk(int x)//x=长度 
{
	cout<<"x="<<x<<endl;
	int a,i,j;//a=砍半长度 
	if(x%2==0)
		a=x/2;
	else if(x%2!=0)
	{
		cout<<"-------------------------"<<endl;
		cout<<x;
		return;
	}
	for(i=0,j=x-1;i<=j;i++,j--)
	{
		if(n[i]!=n[j])
		{
			cout<<"======================"<<endl;
			cout<<x;
			return;
		}	
	}
	zrk(a);
}
int main()
{int s=0;
	cin>>n;
	s=n.size();
	zrk(s);
}

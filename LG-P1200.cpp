#include<bits/stdc++.h> 
using namespace std;
char a[100000],b[100000];
int x[1000000],x1[1000000];
int sum=1,sum1=1;
int main()
{
	int i;
	cin>>a>>b;
	for(i=0;a[i]!='\0';i++)
	{
		sum*=a[i]-64;
	}
	for(i=0;b[i]!='\0';i++)
	{
			sum1*=b[i]-64;
	}	
	if(sum%47==sum1%47)
	{
		cout<<sum%47<<endl;
		cout<<sum1%47<<endl;
		cout<<"GO";
	}
		
	else
		cout<<"STAY";
}

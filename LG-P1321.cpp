#include<bits/stdc++.h>
using namespace std;
string a;
int b,g;
int main()
{
	int i;
	cin>>a;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]=='b')
			b++;
		if(a[i]=='o'&&a[i-1]!='b')
			b++; 
		if(a[i]=='y'&&a[i-1]!='o')
			b++; 
		if(a[i]=='g')
			g++;
		if(a[i]=='i'&&a[i-1]!='g')
			g++;
		if(a[i]=='r'&&a[i-1]!='i')
			g++;
		if(a[i]=='l'&&a[i-1]!='r')
			g++;
	}
	cout<<b<<endl<<g;
}

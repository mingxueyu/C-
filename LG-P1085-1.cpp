#include<bits/stdc++.h>
using namespace std;
string a;
int ans;
int main()
{
	getline(cin,a);
	for(int i=1;a[i]!='\0';i++)
	{
		if(a[i]!=' ')
			ans++;
	}
	cout<<ans;
}

#include<bits/stdc++.h>
using namespace std;
string a;
int t;
int main()
{
	int j=1,i;
	cin>>a;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]!='-'&&i!=12)
		{
			t+=(a[i]-'0')*j;//0-670-82162-4
			j++;
		}
	}
	if(((t%11)<10)&&((t%11+'0')!=a[12]))
	{
		a[12]=(t%11)+'0';
		cout<<a;
	}
	else if((t%11==10)&&(a[12]!='X'))
		 {
		 	 a[12]='X';
			 cout<<a;
		 }
		 else 
		 	 cout<<"Right";
}

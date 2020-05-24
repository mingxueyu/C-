#include<bits/stdc++.h>
using namespace std;
char a;
int s,kh;
int main()
{
	while(cin>>a)
	{
		cout<<kh<<endl;
		if(a=='(')
			s++;
		else if(s>0)
			 {
			 	kh+=2;
			 	s--;
			 }
	}
	cout<<kh;
}

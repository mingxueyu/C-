#include<bits/stdc++.h>//已超时后交 
using namespace std;
int t[100][100];
int n,m,k,s=1,s1,s2,len;
string a;
int main()
{
	int i,j;
	cin>>a;
	len=a.size();
	for(i=0;i<len;i++)
	{
		if(s>2)
			s=1;
		if((a[i]-'0')%3==0)
		{
			k=(a[i]-'0')/3;
			t[k][3]=s;
		}
		if((a[i]-'0')%3!=0)
		  	 {
		 		k=(a[i]-'0')%3;
		 		if((a[i]-'0')>=1&&(a[i]-'0')<=3)
		 			t[1][k]=s;
		 		if((a[i]-'0')>=4&&(a[i]-'0')<=6)
		 			t[2][k]=s;
		 		if((a[i]-'0')>=7&&(a[i]-'0')<=9)
		 			t[3][k]=s;
			 }
		s++;
	}
//	for(i=1;i<=3;i++)
//	{
//		for(j=1;j<=3;j++)
//			cout<<t[i][j];
//		cout<<endl;		
//	}
	if(t[1][1]==1&&t[1][2]==1&&t[1][3]==1)//1
	{
		cout<<"xiaoa wins.";
		return 0;
	}
	if(t[2][1]==1&&t[2][2]==1&&t[2][3]==1)//2
	{
		cout<<"xiaoa wins.";
		return 0;
	}
	if(t[3][1]==1&&t[3][2]==1&&t[3][3]==1)//3
	{
		cout<<"xiaoa wins.";
		return 0;
	}
	if(t[1][1]==1&&t[2][1]==1&&t[3][1]==1)//4
	{
		cout<<"xiaoa wins.";
		return 0;
	}
	if(t[1][2]==1&&t[2][2]==1&&t[3][2]==1)//5
	{
		cout<<"xiaoa wins.";
		return 0;
	}
	if(t[1][3]==1&&t[2][3]==1&&t[3][3]==1)//6
	{
		cout<<"xiaoa wins.";
		return 0;
	}
	if(t[1][1]==1&&t[2][2]==1&&t[3][3]==1)//7
	{
		cout<<"xiaoa wins.";
		return 0;
	}
	if(t[1][3]==1&&t[2][2]==1&&t[3][1]==1)//8
	{
		cout<<"xiaoa wins.";
		return 0;
	}
	//以上为小a的所有可能 
	if(t[1][1]==2&&t[1][2]==2&&t[1][3]==2)
	{
		cout<<"uim wins.";
		return 0;
	}
	if(t[2][1]==2&&t[2][2]==2&&t[2][3]==2)
	{
		cout<<"uim wins.";
		return 0;
	}
	if(t[3][1]==2&&t[3][2]==2&&t[3][3]==2)
	{
		cout<<"uim wins.";
		return 0;
	}
	if(t[1][1]==2&&t[2][1]==2&&t[3][1]==2)
	{
		cout<<"uim wins.";
		return 0;
	}
	if(t[1][2]==2&&t[2][2]==2&&t[3][2]==2)
	{
		cout<<"uim wins.";
		return 0;
	}
	if(t[1][3]==2&&t[2][3]==2&&t[3][3]==2)
	{
		cout<<"uim wins.";
		return 0;
	}
	if(t[1][1]==2&&t[2][2]==2&&t[3][3]==2)
	{
		cout<<"uim wins.";
		return 0;
	}
	if(t[1][3]==2&&t[1][2]==2&&t[1][1]==2)
	{
		cout<<"uim wins.";
		return 0;
	}	
	cout<<"drew.";
	return 0; 
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
			cout<<t[i][j];
		cout<<endl;		
	}

}

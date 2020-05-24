#include<bits/stdc++.h>
using namespace std;
int t[10];
int x=6,n;
int main()
{
	int i,j,k;
	cin>>n;
	for(i=1900;i<=1900+n-1;i++)//Äê 
	{
		cout<<t[1]<<" "<<t[2]<<" "<<t[3]<<" "<<t[4]<<" "<<t[5]<<" "<<t[6]<<" "<<t[7]<<endl;

		for(j=1;j<=12;j++)//ÔÂ
		{
			t[x]++;
			if(j==2&&i%4==0&&(i%100!=0||i%400==0))
			{
				x=x%7+1;
			}
			else if(j==1||j==3||j==5||j==7||j==8||j==10||j==12)
					x=(x+31-1)%7+1;
				 else if(j==4||j==6||j==9||j==11)
				 {
				 	x=(x+30-1)%7+1;
				 }
		} 
	}
	cout<<t[6]<<" "<<t[7];
	for(i=1;i<=5;i++)
		cout<<" "<<t[i]; 
}


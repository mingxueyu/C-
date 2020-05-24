#include<bits/stdc++.h>
using namespace std;
int n,a;
int main()
{
//	clock_t time_begin = clock();
	int i,j,k;
	cin>>n;
	for(i=n;i>=0;i--)
	{
		cin>>a;
		if(a!=0)
		{
			if(i!=n&&a>=1)//是否为正 
				cout<<"+";
			if(i!=0&&a==-1)//是否不为常数且a为-1 
				cout<<"-";			
			if(a!=1&&a!=-1||i==0)//是否不为1,-1,和最后的常数 
				cout<<a;								
			if(i>1)//是否为常数 
				cout<<"x^"<<i;
			if(i==1)//是否指数为一;x^1=x; 
				cout<<"x";
		}//1,与,-1不要写出来!!!!!!!! 
	}
//clock_t time_end = clock();
//double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
//cout<<endl << time_cost << endl;
} 


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
			if(i!=n&&a>=1)//�Ƿ�Ϊ�� 
				cout<<"+";
			if(i!=0&&a==-1)//�Ƿ�Ϊ������aΪ-1 
				cout<<"-";			
			if(a!=1&&a!=-1||i==0)//�Ƿ�Ϊ1,-1,�����ĳ��� 
				cout<<a;								
			if(i>1)//�Ƿ�Ϊ���� 
				cout<<"x^"<<i;
			if(i==1)//�Ƿ�ָ��Ϊһ;x^1=x; 
				cout<<"x";
		}//1,��,-1��Ҫд����!!!!!!!! 
	}
//clock_t time_end = clock();
//double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
//cout<<endl << time_cost << endl;
} 


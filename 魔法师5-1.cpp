#include<bits/stdc++.h>
using namespace std;
char a[108][108];
int b[108][108];
int main()
{      
	int sum=0,s=0,n=0,i=0,x=0,m=0,y=0,k=0,o=0,j=0,t=48;
	cout<<"���������̴�С:"<<endl; 
 	cin>>n;
 	cout<<"������ħ��ʦ����:"<<endl;
	cin>>k;
 	for(i=1;i<=n;i++)
 	{
 		for(j=1;j<=n;j++)
		{
			a[i][j]='0';	
		}	
	}
	for(o=1;o<=k;o++)
	{
		cout<<"������ħ��ʦ��λ:"<<endl; 
		cin>>x>>y;
		a[x][y]='+';			
	}
	cout<<"ս�Գ���ͼ���ڴ�ӡ��........"<<endl;
	cout<<"��ӡ�ɹ�!"<<endl;
	cout<<"-----------------------------------------"<<endl;
 	for(i=1;i<=n;i++)
 	{
 		for(j=1;j<=n;j++)
		{
			if(a[i][j]=='+')
				cout<<"+"<<" ";
			else
				cout<<(a[i+1][j]=='+')+(a[i-1][j]=='+')+(a[i][j+1]=='+')+(a[i][j-1]=='+')+(a[i-1][j-1]=='+')+(a[i+1][j+1]=='+')+(a[i-1][j+1]=='+')+(a[i+1][j-1]=='+')<<" ";
		}
		cout<<endl;	
	}		
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
bool a[100];
int h[100];
int main()
{
	int m,n,x,s=0,v=0,v1=0;//m=˳ʱ������m���˳�Ȧ��n=�м��ˣ�x=һ�غϣ����ڼ�����,s=���������v=���������ж��ǲ��������� ��v1=��x�˵����� 
	cin>>n>>m;
	for(i=1;i<=n;i++)
		a[i]=1;
	s=n;
	while(s>0)
	{
		if(x>n)
		x=1;
		if(a[x]==1)
		{
			v1=h[x] 
			v++;
			if(v==m)
			{
				a[x]=0;
				cout<<v1<<" ";
				s--;
				x=0;
			}
	 
		}	
	}
	cout<<"||-��Ϸ����---�Ҵ���ȫ����-||"<<endl;
	cout<<"||-Game over---the survivors are all dead-||"<<endl;
	cout<<"||-��ʧ����-||"<<endl;
	cout<<"||-You have failed!-||"<<endl;
}

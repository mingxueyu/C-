#include<bits/stdc++.h>
using namespace std;
char x,y;
int n,m,a,b,c,t[1500000],ans=1;//ans=��Ŀ�е�n 
int main()
{
	int i=1,j,k;
	y='0';
    while(cin>>x)
    {
        n++;
        if(x==y)
            t[ans]++;//t�ĵ�n++;//����0��1���������� 
        else
		{
			ans++;
            t[ans]++;//��������ַ�ҲҪ�㵽һ���µĸ����� 
            y=x;	
		}
    }
    cout<<sqrt(n);//n*n���� 
    for(i=1;i<=ans;i++)
        cout<<" "<<t[i];//����֮����
}

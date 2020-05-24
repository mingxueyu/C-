#include<bits/stdc++.h>
using namespace std;
char x,y;
int n,m,a,b,c,t[1500000],ans=1;//ans=题目中的n 
int main()
{
	int i=1,j,k;
	y='0';
    while(cin>>x)
    {
        n++;
        if(x==y)
            t[ans]++;//t的第n++;//代表0或1的连续个数 
        else
		{
			ans++;
            t[ans]++;//刚输入的字符也要算到一个新的格子里 
            y=x;	
		}
    }
    cout<<sqrt(n);//n*n矩阵 
    for(i=1;i<=ans;i++)
        cout<<" "<<t[i];//逗号之悲剧
}

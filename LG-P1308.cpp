#include<bits/stdc++.h>
using namespace std;  
int len,sum,mx,mxx,s,t;
char x[10000000],y[10000000];
int main()
{
	int j=0,i,k=0;
	cin>>x;
	gets(y);
	gets(y);
	len=strlen(x);
	for(i=0;x[i]!='\0';i++)
	{
		if(x[i]<='Z'&&x[i]>='A')
		{
			x[i]+=32;
		}
	}
	for(i=0;y[i]!='\0';i++)
	{
		if(y[i]<='Z'&&y[i]>='A')
		{
			y[i]+=32;
		}
	}	//转换统一格式小写 
	for(int i=0;y[i]!='\0';i++)//将y[i]遍历一遍 
	{
		s=0;
		sum=0;//计数器清零;s=中间相同字符有几个;sum=这个单词有几个 
		if(y[i-1]==' '||i==0)//如果它的前一个是' '或者为句子开头 
		{
			t=i;//第一次出现位置 
			for(j=i;y[j]!=' ';j++)//从i开始,直到遇见空格(一个单词结束) 
			{		
				if(y[j]==x[j])//如果这两个字符相同 
					s++;//相同计数器++ 
				sum++;//单词长度计数器++ 
			}	
			if(sum==s&&s!=0&&sum!=0)//如果相同字符数等于单词长度,且均不等于0 
			{
				if(k==0)//如果这是第一次发现 
					mx=t;//记录第一次发现位置 
				mxx++;//相同单词计数器++; 
				k=1;//使其永不再次进入记录第一次位置的判断 
			}	
		}	
//		cout<<y[i]<<" s="<<s<<"sum="<<sum<<endl;
	}
	if(k==1) 
		cout<<mxx<<" "<<mx;
	else if(k==0)
		 	cout<<"-1";	
} 

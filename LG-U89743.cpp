#include<bits/stdc++.h>
using namespace std;
int t[10000000];
int l,n,ans,ans1;//-1=�� -2=��  //1=�Ǳ����� 
int main()
{
    int i,j;
    cin>>l>>n;
    for(i=0;i<=l;i++)
    	t[i]=1; 
    for(i=1;i<=n;i++)
    {
        int k,x,y;//k=ִ�в��� 
        cin>>k>>x>>y;//x-y=ִ�в������� 
        if(k==0)//�� 
            for(j=x;j<=y;j++)
            {
                if(t[j]==-1)//��������� 
                    ans1++;//�����ֱ��ε�������++; 
                t[j]=-2;  //���Ϊ������       	
			}
        else
            for(j=x;j<=y;j++)
                if(t[j]==-2)//����Ǳ������� 
                    t[j]=-1;//�Ǿ����� 
    }
    for(i=0;i<=l;i++)
        if(t[i]==-1)//��������� 
            ans++;//���µ�����++; 
    cout<<ans<<endl<<ans1;
    return 0;
}

#include<iostream>
#include<cstdio>
using namespace std;   
char ch;   
int x,y,ans,map[550][550],dx[5]={0,1,-1,0,0},dy[5]={0,0,0,1,-1};//dx,dy�����������ĸ����򣨰�0���˹�ȥ�� 
void dfs(int m,int n)  
{ 
    if(m<0||n<0||m>x+1||n>y+1||map[m][n])  //���Խ������ϰ��ͻ��� 
        return;  
    map[m][n]=2;   
    for(int i=1;i<=4;i++)  //������������ 
        dfs(m+dx[i],n+dy[i]);
}  
int main()
{
    scanf("%d%d",&x,&y);
    for(int i=1;i<=x;i++)  //ϰ�ߴ�������ֵ�ͼ 
        for(int j=1;j<=y;j++)
        {
            cin>>ch;  
            if(ch=='0')  
                map[i][j]=0; 
            else map[i][j]=1;
        }
    dfs(0,0);   //��ˮ��ʼ���� 
    for(int i=1;i<=x;i++)  //Ѱ��û�б���ˮϮ���ĵ㼴δ��Ⱦɫ�ĵ� 
        for(int j=1;j<=y;j++)
            if(!map[i][j])
                ans++;   
    printf("%d",ans);
    return 0;  
}

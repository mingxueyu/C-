#include<iostream>
#include<cstdio>
using namespace std;   
char ch;   
int x,y,ans,map[550][550],dx[5]={0,1,-1,0,0},dy[5]={0,0,0,1,-1};//dx,dy是上下左右四个方向（把0空了过去） 
void dfs(int m,int n)  
{ 
    if(m<0||n<0||m>x+1||n>y+1||map[m][n])  //如果越界或有障碍就回溯 
        return;  
    map[m][n]=2;   
    for(int i=1;i<=4;i++)  //上下左右搜索 
        dfs(m+dx[i],n+dy[i]);
}  
int main()
{
    scanf("%d%d",&x,&y);
    for(int i=1;i<=x;i++)  //习惯处理成数字地图 
        for(int j=1;j<=y;j++)
        {
            cin>>ch;  
            if(ch=='0')  
                map[i][j]=0; 
            else map[i][j]=1;
        }
    dfs(0,0);   //洪水开始泛滥 
    for(int i=1;i<=x;i++)  //寻找没有被洪水袭击的点即未被染色的点 
        for(int j=1;j<=y;j++)
            if(!map[i][j])
                ans++;   
    printf("%d",ans);
    return 0;  
}

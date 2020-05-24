#include<bits/stdc++.h>
using namespace std;
int t[10000001],sum,sum1;
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    for(i=0;i<=n;i++)
    	t[i]=1;
    for(i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(x==0)//砍 
        {
            for(j=y;j<=z;j++)
            {
                if(t[j]==-1)//-1=有树 
                    sum++;
                t[j]=-2;//-2=被砍了 
            }
        }
        else//种 
        {
            for(int j=y;j<=z;j++)
            {
                if(t[j]==-2)//无树 
                    t[j]=-1;//有树 
            }
        }
    }
    for(i=0;i<=n;i++)
        if(t[i]==-1)
            sum1++;
    cout<<sum1<<endl<<sum;
    return 0;
}

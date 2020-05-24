#include<bits/stdc++.h>
using namespace std;
int t[10000000];
int l,n,ans,ans1;//-1=有 -2=无  //1=是本来的 
int main()
{
    int i,j;
    cin>>l>>n;
    for(i=0;i<=l;i++)
    	t[i]=1; 
    for(i=1;i<=n;i++)
    {
        int k,x,y;//k=执行操作 
        cin>>k>>x>>y;//x-y=执行操作区间 
        if(k==0)//砍 
            for(j=x;j<=y;j++)
            {
                if(t[j]==-1)//如果是树苗 
                    ans1++;//种上又被拔掉的树苗++; 
                t[j]=-2;  //标记为被砍掉       	
			}
        else
            for(j=x;j<=y;j++)
                if(t[j]==-2)//如果是被砍掉的 
                    t[j]=-1;//那就种上 
    }
    for(i=0;i<=l;i++)
        if(t[i]==-1)//如果是树苗 
            ans++;//留下的树苗++; 
    cout<<ans<<endl<<ans1;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ans=2147483647,y,m,i;
    double n,x;
    cin>>n;
    for(i=1;i<=3;i++)
    {
        cin>>x>>y;
        m=ceil(n/x)*y;
        if(m<ans)
			ans=m;
   }
    cout<<ans;
    return 0;
}

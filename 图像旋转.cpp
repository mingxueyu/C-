
#include<bits/stdc++.h>
using namespace std;
int a[188][188]
int main()
{
   int i,j,m,n;
   cin>>n>>m;
   for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
      {
         cin>>a[i][j];
      }
   for(i=1;i<=m;i++)
   {
      for(j=n;j>=1;j--)
      {
        cout<<a[i][j]<<" ";
      }
cout<<endl;
   }
      
} 

#include<bits/stdc++.h>
using namespace std;
int a[1000];
char x,y,z;
int main()
{
    cin>>a[1]>>a[2]>>a[3];
    cin>>x>>y>>z;
    sort(a+1,a+4);
    cout<<a[x-'A'+1]<<" "<<a[y-'A'+1]<<" "<<a[z-'A'+1];
    return 0;
}

#include<iostream>
using namespace std;
int ans=0;
int g(int m, int n, int x)
{
    int i;
    if (n == 1)
        return 1;
    for (i = x; i <= m / n; i++)
    {
    	ans += g(m - i, n - 1, i);
    	cout<<ans<<endl;
	}
}
int main()
{
    int t, m, n;
    cin >> m >> n;
     g(m, n, 0);
    return 0;
}

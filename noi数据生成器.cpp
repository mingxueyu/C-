#include<bits/stdc++.h>
#define RND(L,R) (DEV_RND%((R)-(L)+1)+(L))
#define DEV_RND ((int)rand()*RAND_MAX+rand())
using namespace std;
int main()
{	
	int n,T;
	srand(time(0));	
	T=RND(1,1000);	
	printf("%d\n",T);	
	while(T--)
	{		
		int a=RND(1,1000000),b=RND(1,1000000);
		cout<<max(a,b)<<" "<<min(a,b);
	}	
	return 0;
}


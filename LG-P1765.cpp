#include<bits/stdc++.h>
using namespace std;
char a[10000000];
int sum;
int main()
{
	gets(a);
	int i;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]=='a')
			sum+=1;
		if(a[i]=='b')
			sum+=2;
		if(a[i]=='c')
			sum+=3;
		if(a[i]=='d')
			sum+=1;
		if(a[i]=='e')
			sum+=2;
		if(a[i]=='f')
			sum+=3;
		if(a[i]=='g')
			sum+=1;
		if(a[i]=='h')
			sum+=2;
		if(a[i]=='i')
			sum+=3;
		if(a[i]=='j')
			sum+=1;
		if(a[i]=='k')
			sum+=2;
		if(a[i]=='l')
			sum+=3;
		if(a[i]=='m')
			sum+=1;
		if(a[i]=='n')
			sum+=2;
		if(a[i]=='o')
			sum+=3;
		if(a[i]=='p')
			sum+=1;
		if(a[i]=='q')
			sum+=2;
		if(a[i]=='r')
			sum+=3;
		if(a[i]=='s')
			sum+=4;
		if(a[i]=='t')
			sum+=1;
		if(a[i]=='u')
			sum+=2;
		if(a[i]=='v')
			sum+=3;
		if(a[i]=='w')
			sum+=1;
		if(a[i]=='x')
			sum+=2;	
		if(a[i]=='y')
			sum+=3;
		if(a[i]=='z')
			sum+=4;
		if(a[i]==' ')
			sum+=1;
	}
	cout<<sum;
	return 0;	
}
